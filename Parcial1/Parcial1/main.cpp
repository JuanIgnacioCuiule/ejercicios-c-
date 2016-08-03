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
	Registro regA, regB;
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
	double montoTotal = 0;
	//feof no es la mejor idea!!! (pero con binarios anda razonablemente)
	fread(&regA, sizeof(Registro), 1, file1);
	fread(&regB, sizeof(Registro), 1, file2);
	strcpy(cadenaAnt, regA.cadena);
    while (!feof(file1) && !feof(file2)) {
        if (strcmp(regA.cadena, regB.cadena) < 0) {
            fwrite(&regA, sizeof(Registro), 1, salida);
            cantCadena++;
            cout << regA.cadena << "\t" << regA.ingresos <<  endl;
            fread(&regA, sizeof(Registro), 1, file1);
            strcpy(cadenaAnt, regA.cadena);
        } else {
            fwrite(&regB, sizeof(Registro), 1, salida);
            cantCadena++;
            cout << regB.cadena << "\t" << regB.ingresos << endl;
            fread(&regB, sizeof(Registro), 1, file2);
            strcpy(cadenaAnt, regB.cadena);
        }
    }
	while (!feof(file1)) {
        fread(&regA, sizeof(Registro), 1, file1);
        fwrite(&regA, sizeof(Registro), 1, salida);
        cantCadena++;
	}
	while (!feof(file2)) {
        fread(&regB, sizeof(Registro), 1, file2);
        fwrite(&regB, sizeof(Registro), 1, salida);
        cantCadena++;
	}
    cout << "cantidad cadena: " << cantCadena << endl;
	fclose(file1);
	fclose(file2);
	fclose(salida);
	return EXIT_SUCCESS;
}
