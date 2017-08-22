#include <stdio.h>

int main () {
	FILE *fp;
	FILE *final;
	fp = fopen("archivo.c","r");
	final = fopen("salida.c", "w");

	int charAnteriorFueBarra = 0;
	char letra;
	char siguienteChar;
	int comentarioDeLineasMultiples = 0;

	while (!feof(fp)) {
		letra = getc(fp);
		if (letra == '\"' || letra == '\'') {
			fprintf(final, "%c", letra);
			siguienteChar = getc(fp);
			while(siguienteChar != letra && !feof(fp)) { 
				fprintf(final, "%c", siguienteChar);
				siguienteChar = getc(fp);
			}
		}
		else if (letra == '/' && !charAnteriorFueBarra) {
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
				fprintf(final, "%c", letra);
				ungetc(siguienteChar, fp);
			}			
		}
		else if (letra != '/' && !feof(fp)) {
			charAnteriorFueBarra = 0;
			fprintf(final, "%c", letra);
		}
	}

	fclose(fp);
	fclose(final);
	return 0;	
}
