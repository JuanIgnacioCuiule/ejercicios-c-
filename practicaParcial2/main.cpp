#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Registro {
	char cod_prod[20];
	int cod_suc;
	double litros;
	float monto;
};

struct DatoProd {
	char cod_prod[20];
	double sum_lt;
};

struct NodoProd {
	DatoProd dato;
	NodoProd* sig;
};

struct NodoLP {
	char cod_prod[20];
	NodoLP* sig;
};

struct DatoSuc {
	int cod_suc;
	float sum_mon;
	NodoLP* lista;
};

struct NodoSuc {
	DatoSuc dato;
	NodoSuc* sig;
};

void pushProd(NodoProd* &listaProd, DatoProd prod) {
	NodoProd* nuevo = new NodoProd;
	nuevo->dato = prod;
	nuevo->sig = listaProd;
	listaProd = nuevo;
}

void generarListaProd(FILE* f, NodoProd* &listaProd) {
	Registro reg;
	DatoProd prod;
	fread(&reg, sizeof(Registro), 1, f);

	while(!feof(f)) {
		strcpy(prod.cod_prod, reg.cod_prod);
		prod.sum_lt = 0;
		while(!feof(f) && strcmp(prod.cod_prod, reg.cod_prod) == 0) {
			prod.sum_lt += reg.litros;
			fread(&reg, sizeof(Registro), 1, f);
			// AGREGAR PARA SUCURSAL
			/*sucursal . suc = reg.suc
			sucursal .lista = NULL;
			sucursal totalmonto = 0;
			psuc = insertarOrdUnico(sucursal, listaausc);
			psuc->dato.totmonto +=reg.monto;
			insertarOrdUnico(prodaux.prod, psuc->dato.lista);
			fread(&reg, sizeof(Registro), 1, f);*/
		}
		pushProd(listaProd, prod);
	}
}

void mostrarListaProd(NodoProd* listaProd)
{
	if(listaProd == NULL) cout << "PORQUE NULL?";
	while (listaProd != NULL){
		cout << "Producto: " << listaProd->dato.cod_prod << "\t Litros: " << listaProd->dato.sum_lt << endl;
		listaProd = listaProd->sig;
	}
}

int main() {
	NodoProd* listaProd = NULL;
	NodoSuc* listaSuc = NULL;

	FILE *f;

	f = fopen("Datos.dat", "rb");

	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	generarListaProd(f, listaProd);

	fclose(f);

	mostrarListaProd(listaProd);

	return 0;
}




