#include <stdio.h>
#include "automata.h"

char buffer[33];
int i = 0;

void strcopy(char destino[], char origen[]) {
  int largoDestino = (sizeof(destino)/sizeof(char));
  int largoOrigen = (sizeof(destino)/sizeof(char));
  for (int j = 0; j < largoOrigen && j < largoDestino; ++j) {
    destino[j] = origen[j];
  }
}

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

void limpiarBuffer() {
  for (int j = 0; j < 33; ++j) {
    buffer[j] = '\0';
  }
  i = 0;
}

int largo(char palabra[]) {
  int largoDePalabra = 0;
  while (palabra[largoDePalabra] != '\0') {
    largoDePalabra++;
  }
  return largoDePalabra;
}

typedef enum {
  INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
  PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
} TOKEN;

typedef struct Nodo {
  TOKEN token;
  char cadena[33];
  //char cadena;
  struct Nodo* sig; 
} Nodo;

void agregar(Nodo** cola, TOKEN token, char cadena[]) {
  Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
  nuevo->token = token;
  nuevo->cadena[0] = cadena[0];
  strcopy(nuevo->cadena, cadena);
  if (*cola == NULL) {
    *cola = nuevo;
  } else {
    Nodo* aux = *cola;
    while (aux->sig != NULL) {
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
};

void mostrar(Nodo* lista) {
  while (lista != NULL) {
    printf("%d %s\n", lista->token, lista->cadena);
    lista = lista->sig;
  }
}

int esPalabraReservada() {
  return strcmp(buffer, "inicio") == 0
      || strcmp(buffer, "fin") == 0
      || strcmp(buffer, "escribir") == 0
      || strcmp(buffer, "leer") == 0;
}

int esEspacio(char caracter) {
  return caracter == ' '
      || caracter == '\n'
      || caracter == '\t';
}

int esOperadorAditivo(char caracter) {
  return caracter == '+'
      || caracter == '-';
}

int esCaracterDePuntuacion(char caracter) {
  return caracter == ','
      || caracter == ';'
      || caracter == '('
      || caracter == ')';
}

// Devuelve el token correspondiente dada un char
// sirve para caracteres de puntuacion, suma, resta
TOKEN token(char letra) {
  switch(letra) {
    case ',':
      return COMA;
      break;
    case ';':
      return PUNTOYCOMA;
      break;
    case '(':
      return PARENIZQUIERDO;
      break;
    case ')':
      return PARENDERECHO;
      break;
    case '+':
      return SUMA;
      break;
    case '-':
      return RESTA;
      break;      
  }
}

// Devuelve el token correspondiente dada una cadena
// sirve para las palabras reservadas
TOKEN tokenCadena(char cadena[]) {
  if (strcmp(cadena, "inicio") == 0)
    return INICIO;
  else if (strcmp(cadena, "leer") == 0)
    return LEER;
  else if (strcmp(cadena, "escribir") == 0)
    return ESCRIBIR;
  else if (strcmp(cadena, "fin") == 0)
    return FIN;
}

int esIdentificador() {
  char primerChar = buffer[0];
  return primerChar != '=' && !(primerChar >= '0' && primerChar <= '9');
}

int main () {
  Nodo* lista = NULL;
  FILE *fp;
  fp = fopen("archivo.micro","r");

  while (!feof(fp)) {
    char letra = getc(fp);
    if (esOperadorAditivo(letra)) {
      char cadena[2] = "\0";
      cadena[0] = letra;
      agregar(&lista, token(letra), cadena);
    }
    else if (letra == ':') {
      char prox = getc(fp);
      if (prox == '=' && !feof(fp)) {
        agregar(&lista, ASIGNACION, ":=");
      } else if (feof(fp)) {
        break;
      } else {
        ungetc(prox, fp);
      }
    }
    else if(esCaracterDePuntuacion(letra)) {
      char cadena[2] = "\0";
      cadena[0] = letra;
      agregar(&lista, token(letra), cadena);
    }
    else {
      while (!feof(fp) && !esEspacio(letra)) {
        buffer[i] = letra;
        i++;
        letra = getc(fp);
        if (esCaracterDePuntuacion(letra) || esOperadorAditivo(letra)) {
          ungetc(letra, fp);
          break;
        }
      }
      if (esPalabraReservada()) {
        agregar(&lista, tokenCadena(buffer), buffer);
      } else if (esConstanteNumerica(buffer)) {
        agregar(&lista, CONSTANTE, buffer);
      } else if (!feof(fp) && buffer[0] != '\0') {
        if (esIdentificador()) {
          agregar(&lista, ID, buffer);
        }
      }
      limpiarBuffer();
    }
  }

  fclose(fp);
  mostrar(lista);
  return 0; 
}

