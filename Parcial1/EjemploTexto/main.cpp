#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/***************
Ejemplo simple de lectura de una archivo de texto donde los campos estan
separados por tabuladores. Notar que en el fscanf los tabuladores los represento
con \t
Si bien preguntar por EOF me asegura detectar el fin de archivo, si pregunto
por 3 (tres elementos correctamente leidos) detectaria tambien otros casos de
error, por ejemplo registros mal formados.
***************/

int main()
{
	FILE *f;
	struct Registro {
		int nro;
		char animal[20];
		double valor;
	};
	Registro reg;

	f = fopen("Archivo.txt", "r");
	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	int registros = 0;
	while(fscanf(f, "%d\t%s\t%lf\n", &reg.nro, reg.animal, &reg.valor) != EOF) { // mejor 3 que EOF
		cout << "Registro " << ++registros << ": " << reg.nro << "\t"
				<< reg.animal << "\t"<< reg.valor << endl;
	}
	fclose(f);
	printf("\nTotal de registros leidos: %d\n", registros);
	return EXIT_SUCCESS;
}
