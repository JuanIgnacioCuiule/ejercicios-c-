#include <stdio.h>

int main () {
	FILE *fp;
	fp = fopen ("archivo.c","r");

	int charAnteriorFueBarra = 0;
	char letra;
	char siguienteChar;
	int comentarioDeLineasMultiples = 0;

	while (!feof(fp)) {
		letra = getc(fp);
		if (letra == '/' && !charAnteriorFueBarra) {
			charAnteriorFueBarra = 1;
			siguienteChar = getc(fp);
			if (siguienteChar == '*' && charAnteriorFueBarra) {
				comentarioDeLineasMultiples = 1;
				while(!feof(fp) && comentarioDeLineasMultiples) {
					while(!feof(fp) && getc(fp) != '*') {}
					if (!feof(fp)) {
						siguienteChar = getc(fp);
						if (siguienteChar == '/') {
							comentarioDeLineasMultiples = 0;
							charAnteriorFueBarra = 0;
						}
					}
				}
			} else if (siguienteChar == '/' && charAnteriorFueBarra) {
				while(!feof(fp) && getc(fp) != '\n') {}
				charAnteriorFueBarra = 0;
			} else if (siguienteChar != '/') {
				printf("%c", letra);
				ungetc(siguienteChar, fp);
			}			
		}
		else if (letra != '/') {
			charAnteriorFueBarra = 0;
			printf("%c",letra);
		}
	}
	
	printf("\n");
	return 0;	
}
