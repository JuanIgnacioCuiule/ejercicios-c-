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
	FILE *f;
	f = fopen("DatosCC.bin", "rb");
	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	/*************
	Voy a hacer corte de control por país y producto informando
	Los totales correspondientes de cantidad y monto
	Al final mostramos el total del archivo
	**************/

	char paisAnt[20];
	char prodAnt[20];
	int cantTotal = 0;
	double montoTotal = 0;
	//feof no es la mejor idea!!! (pero con binarios anda razonablemente)
	fread(&reg, sizeof(Registro), 1, f);
	while (!feof(f)) { // Equivale a fread() == 1
		strcpy(paisAnt, reg.pais);
		int cantPais = 0;
		double montoPais = 0;
		cout << "===== Listado para: " << paisAnt << " =====" << endl << endl ;
		while (!feof(f) && strcmp(paisAnt, reg.pais) == 0) {
			strcpy(prodAnt, reg.prod);
			int cantProd = 0;
			double montoProd = 0;
			cout << "Producto: " << prodAnt << " ---" << endl;
			while (!feof(f) && strcmp(paisAnt, reg.pais) == 0 && strcmp(prodAnt, reg.prod) == 0) {
				cantProd += reg.cant;
				montoProd += reg.monto;
				cout << reg.pais << '\t' << reg.prod << '\t' << reg.cant << '\t' << reg.monto << endl;
				fread(&reg, sizeof(Registro), 1, f);
			}
			cout << "---Totales " << prodAnt << ":\t\t" << cantProd
					<< '\t' << montoProd << endl << endl;
			cantPais += cantProd;
			montoPais += montoProd;
		}
		cout << "TOTALES " << paisAnt << ":\t" << cantPais << '\t'
					<< montoPais << endl << endl;
		cantTotal += cantPais;
		montoTotal += montoPais;
	}
	cout << "\tGRAN TOTAL:\t" << cantTotal << '\t' << montoTotal << endl;
	fclose(f);
	return EXIT_SUCCESS;
}
