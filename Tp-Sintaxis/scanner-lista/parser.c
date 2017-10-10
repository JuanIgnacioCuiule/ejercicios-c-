#include "scanner.h"

Nodo* nodoActual;
int hayToken = 0;
TOKEN proximoToken() {
  if (!hayToken) {
    nodoActual = lista;
    hayToken = 1;
  }
  else
    nodoActual = nodoActual->sig;
  return nodoActual->token;
}

void errorSintactico() {
  printf("Error Sintactico\n");
}

void match(TOKEN t) {
  if (t != proximoToken())
    errorSintactico();
}

void objetivo() {
  // <objetivo> -> <programa> FDT
  programa();
  match(FDT);
}

void programa() {
  // <programa> -> INICIO <listaSentencias> FIN
  TOKEN t;
  match(INICIO);
  printf("%s %s\n", tokens[nodoActual->token], nodoActual->cadena);
  while((t = proximoToken()) != FIN) {}
  printf("%s %s\n", tokens[nodoActual->token], nodoActual->cadena);
  //match(FIN);
}

int main() {
  scanner();

  objetivo();
  // printf("--- Lista de tokens y cadenas ---\n");
  // mostrar(lista);
  // printf("--- Tabla de símbolos ---\n");
  // mostrarTabla(tabla);
  return 0;
}