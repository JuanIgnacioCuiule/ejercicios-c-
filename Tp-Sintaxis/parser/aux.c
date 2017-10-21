#include "headers/aux.h"

int largo(char palabra[]) {
  int largoDePalabra = 0;
  while (palabra[largoDePalabra] != '\0') {
    largoDePalabra++;
  }
  return largoDePalabra;
}

char buffer[33];
int i = 0;
void limpiarBuffer() {
  for (int j = 0; j < 33; ++j) {
    buffer[j] = '\0';
  }
  i = 0;
}