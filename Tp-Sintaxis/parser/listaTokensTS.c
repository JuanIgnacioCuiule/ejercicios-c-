#include "headers/listaTokensTS.h"

// Agrega nodo (ant:token:cadena:sig)
void agregar(Nodo** cola, TOKEN token, char cadena[]) {
  Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
  nuevo->ant = NULL;
  nuevo->sig = NULL;
  nuevo->token = token;
  //nuevo->cadena[0] = cadena[0];
  strcpy(nuevo->cadena, cadena);
  if (*cola == NULL) {
    *cola = nuevo;
  } else {
    Nodo* aux = *cola;
    while (aux->sig != NULL) {
      aux = aux->sig;
    }
    nuevo->ant = aux;
    aux->sig = nuevo;
  }
};

// Agrega simbolo a TS sin repeticion
void agregarSimbolo(Simbolo tabla[], TOKEN token, char cadena[]) {
  int x = 0;
  while (strcmp(tabla[x].cadena, cadena) != 0 && strcmp(tabla[x].cadena, "\0") != 0 && x < 100)
    x++;
  if(strcmp(tabla[x].cadena, "\0") == 0) {
    Simbolo nuevo;
    nuevo.token = token;
    nuevo.cadena[0] = cadena[0];
    strcpy(nuevo.cadena, cadena);
    tabla[x] = nuevo;
  }
};

int estaEnTS(Simbolo tabla[], TOKEN token, char cadena[]) {
  int x = 0;
  while (strcmp(tabla[x].cadena, cadena) != 0 && strcmp(tabla[x].cadena, "\0") != 0 && x < 100)
    x++;
  if (strcmp(tabla[x].cadena, cadena) == 0)
    return 1;
  else
    return 0;
}

// Muestra lista (token:cadena)
void mostrar(Nodo* lista) {
  while (lista != NULL) {
    printf("%s %s\n", tokens[lista->token], lista->cadena);
    lista = lista->sig;
  }
}

// Muestra TS
void mostrarTabla(Simbolo tabla[]) {
  for(int i = 0; i < 100 && strcmp(tabla[i].cadena, "\0") != 0; i++) {
    printf("El token es: %d, La cadena es: %s\n", tabla[i].token, tabla[i].cadena);
  }
}