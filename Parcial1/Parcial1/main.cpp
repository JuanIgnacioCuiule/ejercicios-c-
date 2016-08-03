#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
	struct Registro {
		char cadena[20];
		double ingresos;
	};
	Registro reg;
	FILE *file1;
	FILE *file2;
	FILE *salida;

	file1 = fopen("tabla1.bin", "rb");
	file2 = fopen("tabla2.bin", "rb");
	salida = fopen("salida.bin", "wb");
	if (!file1 || !file2) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	char cadenaAnt[20];
	int cantTotal = 0;
	double montoTotal = 0;
	//feof no es la mejor idea!!! (pero con binarios anda razonablemente)
	fread(&reg, sizeof(Registro), 1, file1);
	while (!feof(file1)) { // Equivale a fread() == 1
		strcpy(cadenaAnt, reg.cadena);
		int cantCadena = 0;
		cout << "===== Listado para: " << cadenaAnt << " =====" << endl << endl ;
		cout << "TOTALES " << cadenaAnt << ":\t" << cantCadena << '\t' << endl;
		cantTotal += cantCadena;
	}
	cout << "\tGRAN TOTAL:\t" << cantTotal << '\t' << montoTotal << endl;
	fclose(file1);
	fclose(file2);
	fclose(salida);
	return EXIT_SUCCESS;
}
