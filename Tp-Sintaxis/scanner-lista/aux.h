void strcopy(char destino[], char origen[]) {
  int largoDestino = (sizeof(destino)/sizeof(char));
  int largoOrigen = (sizeof(destino)/sizeof(char));
  for (int j = 0; j < largoOrigen && j < largoDestino; ++j) {
    destino[j] = origen[j];
  }
}

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

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