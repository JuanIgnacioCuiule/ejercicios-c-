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
  match(INICIO);
  listaSentencias();
  match(FIN);
}

void listaSentencias() {
  TOKEN t = proximoToken();
  while(t == ID || t == LEER || t == ESCRIBIR) {
    sentencia(t);
    printf("%s %s\n", tokens[nodoActual->token], nodoActual->cadena);
    t = proximoToken();
  }
  return;
}
// INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
// PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
void sentencia(TOKEN t) {
  switch(t) {
    case ID:
      printf("sentencia por id\n");
      match(ASIGNACION);
      while(proximoToken() != PUNTOYCOMA){};
      break;
      // expresion();
      // match(PUNTOYCOMA);
    case LEER:
      printf("sentencia por leer\n");
      match(PARENIZQUIERDO);
      listaIdentificadores();
      //match(PARENDERECHO);
      match(PUNTOYCOMA);
      break;
    case ESCRIBIR:
      printf("sentencia por ecribir\n");
      match(PARENIZQUIERDO);
      while(proximoToken() != PARENDERECHO){};
      // listaExpresiones();
      // match(PARENDERECHO);
      match(PUNTOYCOMA);
      break;
    default:
      errorSintactico();
  }
  return;
}

void listaIdentificadores() {
  match(ID);
  for (TOKEN t = proximoToken(); t == COMA; t = proximoToken()) {
    match(ID);
  }
  return;
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