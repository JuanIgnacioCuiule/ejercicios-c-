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
	nuevo->sig = NULL;
	if (listaProd == NULL) {
		listaProd = nuevo;
	} else {
		NodoProd* aux = listaProd;
		while (aux->sig != NULL) //mientras que no sea el último
			aux = aux->sig;  //avanzo al siguiente
		aux->sig = nuevo;
	}
}

NodoLP *insertarOrdUnico(DatoProd valor, NodoLP*& plista) {
	NodoLP **pp = &plista;

	while (*pp != NULL && (strcmp(valor.cod_prod, (*pp)->cod_prod) > 0))
		pp = &((**pp).sig);

	if (*pp == NULL || (strcmp(valor.cod_prod, (*pp)->cod_prod) != 0)) {
		NodoLP* nuevo = new NodoLP;
		strcpy(nuevo->cod_prod, valor.cod_prod);
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	} else {
		return *pp;
	}
}

NodoSuc *insertarOrdUnico(DatoSuc valor, NodoSuc*& plista) {
	NodoSuc **pp = &plista;

	while (*pp != NULL && valor.cod_suc > (*pp)->dato.cod_suc)
		pp = &((*pp)->sig);

	if (*pp == NULL || valor.cod_suc != (*pp)->dato.cod_suc) {
		NodoSuc* nuevo = new NodoSuc;
		nuevo->dato = valor;
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	} else {
		return *pp;
	}
}

void generarListaProd(FILE* f, NodoProd* &listaProd, NodoSuc* &listaSuc) {
	Registro reg;
	DatoProd prod;
	DatoSuc suc;
	NodoSuc* psuc;

	fread(&reg, sizeof(Registro), 1, f);

	while(!feof(f)) {
		strcpy(prod.cod_prod, reg.cod_prod);
		prod.sum_lt = 0;
		suc.lista = NULL;

		while(!feof(f) && (strcmp(prod.cod_prod, reg.cod_prod) == 0)) {
			prod.sum_lt = prod.sum_lt + reg.litros;
			suc.cod_suc = reg.cod_suc;
			suc.sum_mon = 0;
			psuc = insertarOrdUnico(suc, listaSuc);
			psuc->dato.sum_mon = psuc->dato.sum_mon + reg.monto;
			insertarOrdUnico(prod, psuc->dato.lista);
			fread(&reg, sizeof(Registro), 1, f);
		}
		pushProd(listaProd, prod);
	}
}

void mostrarListaProd(NodoProd* listaProd) {
	while (listaProd != NULL){
		cout << "Producto: " << listaProd->dato.cod_prod << "\t Litros: " << listaProd->dato.sum_lt << endl;
		listaProd = listaProd->sig;
	}
}

void mostrarListaSuc(NodoSuc* listaSuc) {
	while (listaSuc != NULL) {
		cout << "Suc: " << listaSuc->dato.cod_suc << "\t Monto: " << listaSuc->dato.sum_mon << endl;
		while (listaSuc->dato.lista != NULL) {
			cout << listaSuc->dato.lista->cod_prod << "\t";
			listaSuc->dato.lista = listaSuc->dato.lista->sig;
		}
		cout << endl;
		listaSuc = listaSuc->sig;
	}
}

NodoProd* buscarMax(NodoProd* plista) {
	int max = -1;
	NodoProd* pmax = NULL;
	while(plista != NULL) {
		if(plista->dato.sum_lt > max) {
			max = plista->dato.sum_lt;
			pmax = plista;
		}
		plista = plista->sig;
	}
	return pmax;
}

int main() {
	NodoProd* listaProd = NULL;
	NodoProd* pmax = NULL;
	NodoSuc* listaSuc = NULL;

	FILE *f;

	f = fopen("Datos.dat", "rb");

	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	cout << "Punto #2 - Generar lista cod prod y sum de litros" << endl;
	generarListaProd(f, listaProd, listaSuc);
	fclose(f);

	cout << "Punto #3 - Liste los productos con su sumatoria de litros" << endl;
	mostrarListaProd(listaProd);

	cout << "Punto #4 - Monto por sucursal mas productos vendidos" << endl;
	mostrarListaSuc(listaSuc);

	cout << "Punto #5 - Producto que vendio msa litros" << endl;
	pmax = buscarMax(listaProd);
	cout << pmax->dato.cod_prod << " vendio " << pmax->dato.sum_lt << " litros\n";

	return 0;
}




