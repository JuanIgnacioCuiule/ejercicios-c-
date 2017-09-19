#include <stdio.h>
#include "automata.h"

char buffer[33];
int i = 0;
 
typedef enum {
  INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
  PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
} TOKEN;

typedef struct Nodo {
  TOKEN token;
  //char cadena[33];
  char cadena;
  struct Nodo* sig; 
} Nodo;

void agregar(Nodo** cola, TOKEN token, char cadena) {
  Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
  nuevo->token = token;
  nuevo->cadena = cadena;
  if (*cola == NULL) {
    *cola = nuevo;
  } else {
    Nodo* aux = *cola;
    while (aux->sig != NULL) {//mientras que no sea el último
      aux = aux->sig;  //avanzo al siguiente
    }
    aux->sig = nuevo;
  }
};

void mostrar(Nodo* lista) {
  while (lista != NULL) {
    printf("%c\n", lista->cadena);
    printf("%d\n", lista->token);
    lista = lista->sig;
  }
}

int main () {
  Nodo* cola1 = NULL;
  agregar(&cola1, INICIO, 'a');
  agregar(&cola1, LEER, 'b');
  agregar(&cola1, PUNTOYCOMA, 'c');
  agregar(&cola1, FDT, 'd');
  mostrar(cola1);

  return 0; 
}

