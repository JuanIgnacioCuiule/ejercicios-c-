#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	FILE *archivoTexto;
	FILE *archivoBinario;
	struct Registro {
		int origen;
		int destino;
		int peso;
	};
	
	Registro reg;

	archivoTexto = fopen(argv[1], "r");
	archivoBinario = fopen(argv[2], "w+b");

	if (!archivoTexto) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	int registros = 0;
	while(fscanf(archivoTexto, "%d\t%d\t%d\n", &reg.origen, &reg.destino, &reg.peso) != EOF) {
		fwrite(&reg, sizeof(struct Registro), 1, archivoBinario);
		registros++;
	}
	fclose(archivoTexto);
	fclose(archivoBinario);
	printf("\nTotal de registros leidos: %d\n", registros);
	return EXIT_SUCCESS;
}