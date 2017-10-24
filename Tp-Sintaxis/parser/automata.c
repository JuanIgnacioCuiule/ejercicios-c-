#include "headers/automata.h"

const int TT[6][5] = {{5,1,5,5,5},
                      {1,1,3,2,5},
                      {5,5,4,5,5},
                      {5,5,5,4,5},
                      {5,5,5,5,5},
                      {5,5,5,5,5}};

int columna(char c) {
  if (c == '0') {
    return 0;
  } else if (c > '0' && c <= '9') {
    return 1;
  } else if (c == 'u' || c == 'U') {
    return 2;
  } else if (c == 'l' || c == 'L') {
    return 3;
  } else {
    return 4;
  }
}

int esConstanteNumerica(char cadena[]) {
  int i = 0;
  int estado = 0;
  while (cadena[i] != '\0' && estado != 5){
    int col = columna(cadena[i]);
    estado = TT[estado][col];
    i++;  
  }

  return estado == 1 
      || estado == 2 
      || estado == 3 
      || estado == 4;  
}