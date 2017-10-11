#include "headers/tokens.h"

// solo para ver en consola
char* tokens[] = {"INICIO", "FIN", "LEER", "ESCRIBIR", "ID", "CONSTANTE", "PARENIZQUIERDO", "PARENDERECHO",
"PUNTOYCOMA", "COMA", "ASIGNACION", "SUMA", "RESTA", "FDT", "ERRORLEXICO"};

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