#include <stdio.h>

int main () {
	FILE *fp;
	fp = fopen ("archivo.txt","r");
	
	int contadorDeEspacios = 0;
	int cantidadDePalabras = 0;
	char letra;

	// Variable para evitar contar espacios múltiples como palabras
	int anteriorFueEspacio = 0;

	fscanf(fp, "%c", &letra);

	// Para evitar espacios al comienzo del archivo
	while(letra == ' ' || letra == '\n' || letra == '\t') {
		fscanf(fp, "%c", &letra);
	}

	while (!feof(fp)) {
		if (!anteriorFueEspacio && (letra == ' ' || letra == '\n' || letra == '\t')) {
			contadorDeEspacios++;
			anteriorFueEspacio = 1;
		} else if (letra != ' ' && letra != '\n' && letra != '\t') {
			anteriorFueEspacio = 0;
		}
		fscanf(fp,"%c", &letra);
	}
	
	// Para evitar contar una palabra de más cuando el archivo termina en espacio
	if (letra == ' ' || letra == '\n' || letra == '\t') {
		cantidadDePalabras = contadorDeEspacios;
	} else {
		cantidadDePalabras = contadorDeEspacios + 1;
	}

	printf("La cantidad de palabras que tiene el archivo es: %i\n", cantidadDePalabras);
	
	return 0;	
}
