#include <stdio.h>

char buffer[33];
char reservadas[][8] = {"inicio", "fin", "escribir", "leer"};
int i = 0;

void limpiarBuffer() {
	for (int j = 0; j < 33; ++j) {
		buffer[j] = '\0';
	}
	i = 0;
}

int largo(char palabra[]) {
	int largoDePalabra = 0;
	while (palabra[largoDePalabra] != '\0') {
		largoDePalabra++;
	}
	return largoDePalabra;
}

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

int esPalabraReservada() {
	return strcmp(buffer, reservadas[0]) == 0  // inicio
			|| strcmp(buffer, reservadas[1]) == 0  // fin
			|| strcmp(buffer, reservadas[2]) == 0  // escribir
			|| strcmp(buffer, reservadas[3]) == 0; // leer
}

int esEspacio(char caracter) {
	return caracter == ' '
			|| caracter == '\n'
			|| caracter == '\t';
}

int main () {
	FILE *fp;
	fp = fopen("archivo.micro","r");
	
	while(!feof(fp)) {
		char letra = getc(fp);
		while(!feof(fp) && !esEspacio(letra)) {
			buffer[i] = letra;
			i++;
			letra = getc(fp);
		}
		if (esPalabraReservada()) {
			printf("Palabra reservada: %s\n", buffer);
		}
		limpiarBuffer();
	}

	fclose(fp);
	return 0;	
}

