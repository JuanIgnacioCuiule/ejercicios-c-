#include <iostream>

using namespace std;


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
{ 	/*
	Me dan un valor de tipo T y la pila donde lo quiero guardar.
	Node<T>* &pila = pila es una ref a un puntero de nodo para poder
	odificar el orignial.
	*/
	Nodo* nuevo = new Nodo;	// Creo un nuevo nodo
	nuevo->dato = valor;	// Guardo el valor como dato
	nuevo->sig = pila;	// Guardo el puntero al sig
	pila = nuevo;	// A pila le copia la direccion a la que apunta "nuevo"
}

Registro pop(Nodo* &pila)
{
	Registro valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

void mostrar(Nodo* lista)
{	/*
	Nodo<T>* lista = Pedir un "clon" del original para poder mostrarlo
	como quiera.
	*/
	while (lista!= NULL){
		cout << lista->dato.prod << "\t" << lista->dato.kg << "\t" << lista->dato.unid << endl;
		lista = lista->sig;
	}
}

bool dup(Nodo* &lista)
{
	if(lista==NULL)
		return false;
	Registro regDup = lista->dato;
	push(lista, regDup);
	return true;
}

bool swapLista(Nodo* &lista)
{
	if(lista==NULL || lista->sig==NULL)
		return false;
	Registro regSwap1 = lista->dato;
	Registro regSwap2 = lista->sig->dato;
	pop(lista);
	pop(lista);
	push(lista, regSwap1);
	push(lista, regSwap2);
	return true;
}

bool rot(Nodo* &lista)
{
	if(lista==NULL || lista->sig==NULL || lista->sig->sig==NULL)
		return false;
	Registro regSwap1 = lista->dato;
	Registro regSwap2 = lista->sig->dato;
	Registro regSwap3 = lista->sig->sig->dato;
	pop(lista);
	pop(lista);
	pop(lista);
	push(lista, regSwap1);
	push(lista, regSwap2);
	push(lista, regSwap3);
	return true;
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

	swapLista(pila);
	cout << endl;
	cout << "Swap primero con segundo..." << endl;
	mostrar(pila);

	rot(pila);
	cout << endl;
	cout << "Rot primero con tercero..." << endl;
	mostrar(pila);

	dup(pila);
	cout << endl;
	cout << "Duplico primero..." << endl;
	mostrar(pila);

	return 0;
}
