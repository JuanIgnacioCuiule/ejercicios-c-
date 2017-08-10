#include <stdio.h>

int main () {
	FILE *fp;
	fp = fopen ("archivo.c","r");

	int charAnteriorFueBarra = 0;

	char letra;
	char siguienteLetra;

	while (!feof(fp)) {
		letra = getc(fp);
		if (letra == '/' && !charAnteriorFueBarra) {
			charAnteriorFueBarra = 1;
			siguienteLetra = getc(fp);
			if (siguienteLetra != '/')
				printf("%c", letra);
			ungetc(siguienteLetra, fp);
		} else if (letra == '/' && charAnteriorFueBarra) {
			// Estoy en un comentario
			while(!feof(fp) && getc(fp) != '\n') {}
			printf("\n");
		} else if (letra != '/') {
			charAnteriorFueBarra = 0;
			printf("%c",letra);
		}
	}
	
	printf("\n");
	return 0;	
}
