#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Registro
{
	char prod[20];
	double kg;
	int unid;
};

struct Nodo
{
	Registro dato; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};

void push(Nodo* &pila, Registro valor)
{
	Nodo* nuevo = new Nodo;	// Creo un nuevo nodo
	nuevo->dato = valor;	// Guardo el valor como dato
	nuevo->sig = pila;	// Guardo el puntero al sig
	pila = nuevo;	// A pila le copia la direccion a la que apunta "nuevo"
}

void mostrar(Nodo* lista)
{
	while (lista!= NULL){
		cout << lista->dato.prod << "\t" << lista->dato.kg << "\t" << lista->dato.unid << endl;
		lista = lista->sig;
	}
}

int main()
{
	Nodo* pila = NULL;
	Registro reg;
	FILE *f;

	f = fopen("lotes.bin", "rb");
	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}

	Registro mayor_lote;
	mayor_lote.kg = 0.0;
	mayor_lote.unid = 0;

	int registros = 0;
	double acum = 0.0;

	fread(&reg, sizeof(Registro), 1, f);
	while(!feof(f)) {
		push(pila, reg);
		registros++;
		acum += reg.kg;
		if (reg.unid > mayor_lote.unid) {			mayor_lote.kg = reg.kg;
			mayor_lote.unid = reg.unid;
			strcpy(mayor_lote.prod, reg.prod);
		}
		fread(&reg, sizeof(Registro), 1, f);
	}



	mostrar(pila);
	cout << "El lote con mas unidades es: " << endl;
	cout << mayor_lote.prod << "\t" <<  mayor_lote.kg << "\t" << mayor_lote.unid << endl << endl;
	cout << "El promedio de kg por lote es de: " << (acum == 0 ? 0 : acum/registros) << endl;


	return 0;
}
