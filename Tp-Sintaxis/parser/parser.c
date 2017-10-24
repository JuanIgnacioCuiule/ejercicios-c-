#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scanner.c"
#include "headers/parser.h"

Nodo* nodoActual;
int hayToken = 0;

/*
* typedef struct Reg_expresion {
*  TOKEN token;
*  char cadena[32];
*  int constante;
* } Reg_expresion;
*/

int main() {
  scanner();
  objetivo();
  return 0;
}

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
  programa();
  match(FDT);
}

void programa() {
  match(INICIO);
  listaSentencias();
  match(FIN);
}

void listaSentencias() {
  TOKEN t = proximoToken();
  while(t == ID || t == LEER || t == ESCRIBIR) {
    sentencia(t);
    t = proximoToken();
    //printf("dentro while LS %s\n", tokens[t]);
  }
  nodoActual = nodoActual->ant;
  return;
}

void sentencia(TOKEN t) {
  Reg_expresion res;
  char identificador[32];
  switch(t) {
    case ID:
      strcpy(identificador, nodoActual->cadena);
      match(ASIGNACION);
      expresion(&res);
      //nodoActual = nodoActual->ant;
      match(PUNTOYCOMA);
      printf("Asignar %s %s\n", res.cadena, identificador);
      break;
    case LEER:
      match(PARENIZQUIERDO);
      listaIdentificadores();
      match(PARENDERECHO);
      match(PUNTOYCOMA);
      break;
    case ESCRIBIR:
      match(PARENIZQUIERDO);
      listaExpresiones();
      match(PARENDERECHO);
      match(PUNTOYCOMA);
      break;
    default:
      errorSintactico();
  }
  return;
}

void listaIdentificadores() {
  match(ID);
  printf("Leer %s\n", nodoActual->cadena);
  TOKEN t = proximoToken();
  while(t == COMA) {
    match(ID);
    printf("Leer %s\n", nodoActual->cadena);
    t = proximoToken();
  }
  //printf("token en LI %s\n", tokens[nodoActual->token]);
  nodoActual = nodoActual->ant;
  return;
}

void primaria(Reg_expresion * operando) {
  TOKEN t = proximoToken();
  Reg_expresion res;
  switch(t) {
    case ID:
      operando->token = ID;
      strcpy(operando->cadena, nodoActual->cadena);
      break;
    case CONSTANTE:
      operando->token = CONSTANTE;
      strcpy(operando->cadena, nodoActual->cadena);
      operando->constante = atoi(nodoActual->cadena);
      break;
    case PARENIZQUIERDO:
      expresion(&res);
      match(PARENDERECHO);
      *operando = res;
      break;
  }
}

void listaExpresiones(void) {
  Reg_expresion reg;
  expresion(&reg);
  TOKEN t = proximoToken();
  while(t == COMA) {
    expresion(&reg);
    t = proximoToken();
  }
  nodoActual = nodoActual->ant;
}

Reg_expresion genInfijo(Reg_expresion e1, TOKEN op, Reg_expresion e2) {
  Reg_expresion reg;
  unsigned static int temporal = 1;
  char cadenaTemporal[32] = "temp&";
  char cadenaNumero[32];
  char cadenaOp[32];
  if (op == SUMA)
    strcpy(cadenaOp, "Sumar");
  else 
    strcpy(cadenaOp, "Restar");
  sprintf(cadenaNumero, "%d", temporal);
  temporal++;
  strcat(cadenaTemporal, cadenaNumero);
  if (!estaEnTS(tabla, ID, cadenaTemporal)) {
    agregarSimbolo(tabla, ID, cadenaTemporal);
    printf("Declarar %s\n", cadenaTemporal);
  }
  reg.token = ID;
  strcpy(reg.cadena, cadenaTemporal);
  printf("%s %s %s %s\n", cadenaOp, e1.cadena, e2.cadena, cadenaTemporal);
  return reg;
}

void expresion(Reg_expresion * resultado) {
  Reg_expresion operandoIzq, operandoDer;
  TOKEN op;
  TOKEN t;
  primaria(&operandoIzq);
  for (t = proximoToken(); t == SUMA || t == RESTA; t = proximoToken()) {
    operadorAditivo(&op);
    primaria(&operandoDer);
    operandoIzq = genInfijo(operandoIzq, op, operandoDer);
  }
  *resultado = operandoIzq;
  nodoActual = nodoActual->ant;
}

void operadorAditivo(TOKEN *op) {
  TOKEN t = nodoActual->token;
  if(t == SUMA || t == RESTA)
    *op = t;
  else
    printf("Error Sintactico");
}