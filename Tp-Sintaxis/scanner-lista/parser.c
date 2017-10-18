#include <stdio.h>
#include <stdlib.h>
#include "scanner.c"
#include "headers/parser.h"

Nodo* nodoActual;
int hayToken = 0;

typedef struct Reg_expresion {
  TOKEN token;
  char cadena[32];
  int constante;
} Reg_expresion;

int main() {
  scanner();
  objetivo();
  // printf("--- Lista de tokens y cadenas ---\n");
  // mostrar(lista);
  // printf("--- Tabla de símbolos ---\n");
  // mostrarTabla(tabla);
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
    t = proximoToken();
    printf("dentro while LS %s\n", tokens[t]);
  }
  nodoActual = nodoActual->ant;
  return;
}
// INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
// PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
void sentencia(TOKEN t) {
  Reg_expresion res;
  switch(t) {
    case ID:
      printf("-- sentencia por id --\n");
      printf("%s\n", tokens[nodoActual->token]);
      match(ASIGNACION);
      printf("%s\n", tokens[nodoActual->token]);
      expresion(&res);
      printf("%s\n", tokens[nodoActual->token]);
      nodoActual = nodoActual->ant;
      printf("%s\n", tokens[nodoActual->token]);
      match(PUNTOYCOMA);
      printf("%s\n", tokens[nodoActual->token]);
      printf("-- termina sentencia por id --\n");
      break;
    case LEER:
      printf("-- sentencia por leer --\n");
      printf("%s\n", tokens[nodoActual->token]);
      match(PARENIZQUIERDO);
      printf("%s\n", tokens[nodoActual->token]);
      listaIdentificadores();
      printf("%s\n", tokens[nodoActual->token]);
      match(PARENDERECHO);
      printf("%s\n", tokens[nodoActual->token]);
      match(PUNTOYCOMA);
      printf("%s\n", tokens[nodoActual->token]);
      printf("-- termina sentencia por leer --\n");
      break;
    case ESCRIBIR:
      printf("-- sentencia por ecribir --\n");
      printf("%s\n", tokens[nodoActual->token]);
      match(PARENIZQUIERDO);
      printf("%s\n", tokens[nodoActual->token]);
      listaExpresiones();
      printf("%s\n", tokens[nodoActual->token]);
      match(PARENDERECHO);
      printf("%s\n", tokens[nodoActual->token]);
      match(PUNTOYCOMA);
      printf("%s\n", tokens[nodoActual->token]);
      printf("-- termina sentencia por ecribir --\n");
      break;
    default:
      errorSintactico();
  }
  return;
}

void listaIdentificadores() {
  match(ID);
  TOKEN t = proximoToken();
  while(t == COMA) {
    match(ID);
    t = proximoToken();
  }
  printf("token en LI %s\n", tokens[nodoActual->token]);
  nodoActual = nodoActual->ant;
  return;
}

void primaria(Reg_expresion * operando) {
  TOKEN t = proximoToken();
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
      expresion(&operando);
      match(PARENDERECHO);
      break;
  }
}

void listaExpresiones(void) {
  /* <listaExpresiones> -> <expresion> #escribir_exp {COMA <expresion> #escribir_exp} */
  TOKEN t;
  Reg_expresion reg;
  expresion(&reg);
  for (t = proximoToken(); t == COMA; t = proximoToken()) {
    expresion(&reg);
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
}

void operadorAditivo(TOKEN *op) {
  TOKEN t = nodoActual->token;
  if(t == SUMA || t == RESTA)
    *op = t;
  else
    printf("Error Sintactico");
}