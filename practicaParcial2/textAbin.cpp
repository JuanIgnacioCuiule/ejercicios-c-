#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct Registro {
		char cod_prod[20];
		int cod_suc;
		double litros;
		float monto;
	};

int main(int argc, char* argv[])
{
	FILE *archivoTexto;
	FILE *archivoBinario;
	
	Registro reg;
	archivoTexto = fopen(argv[1], "r");
	archivoBinario = fopen(argv[2], "w+b");

	if (!archivoTexto) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	while(fscanf(archivoTexto, "%s\t%d\t%lf\t%f\n", reg.cod_prod, &reg.cod_suc, &reg.litros, &reg.monto) != EOF) {
		cout << reg.cod_prod << endl;
		fwrite(&reg, sizeof(struct Registro), 1, archivoBinario);
	}
	fclose(archivoTexto);
	fclose(archivoBinario);
	return EXIT_SUCCESS;
}

