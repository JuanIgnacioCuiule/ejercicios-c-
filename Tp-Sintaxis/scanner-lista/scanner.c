#include <stdio.h>
#include "automata.h"

char buffer[33];
int i = 0;
 
typedef enum {
  INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
  PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
} TOKEN;

struct Nodo {
  TOKEN token;
  char cadena[33];
  Nodo* sig;
} Nodo;

void agregar(Nodo*& cola, Nodo nodo) {
  Nodo* nuevo = new Nodo;
  nuevo->token = nodo.token;
  nuevo->cadena = nodo.cadena;
  if (cola == NULL) {
    cola = nuevo;
  } else {
    Nodo* aux = cola;
    while (aux->sig != NULL) //mientras que no sea el último
      aux = aux->sig;  //avanzo al siguiente
    aux->sig = nuevo;
  }
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

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
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

int esIdentificador() {
  char primerChar = buffer[0];
  return primerChar != '=' && !(primerChar >= '0' && primerChar <= '9');
}

void mostrar(Nodo* lista)
{
  while (lista != NULL) {
    printf("%c\n", lista.cadena);
    lista = lista->sig;
  }
}

int main () {
  Nodo* cola1 = NULL;

  Nodo primer = { INICIO, "inicio", NULL };
  agregar(cola1, primer);
  mostrar(cola1);

  return 0; 
}

