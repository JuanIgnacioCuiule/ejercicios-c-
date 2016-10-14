#include <iostream>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Nodo
{
	char c; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};

void push(Nodo* &pila, char valor)
{ 	/*
	Me dan un valor de tipo T y la pila donde lo quiero guardar.
	Node<T>* &pila = pila es una ref a un puntero de nodo para poder
	odificar el orignial.
	*/
	Nodo* nuevo = new Nodo;	// Creo un nuevo nodo
	nuevo->c = valor;	// Guardo el valor como
	nuevo->sig = pila;	// Guardo el puntero al sig
	pila = nuevo;	// A pila le copia la direccion a la que apunta "nuevo"
}

char pop(Nodo* &pila)
{
	char valor = pila->c;
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
		cout << lista->c << endl;
		lista = lista->sig;
	}
}

int main()
{

	Nodo* pila = NULL;
	char l;
	char la;

	cout << "Ingresa la primer letra: ";

	cin.get(l);
	while(l!='.' && l!='\n') {
		push(pila, l);
		cin.get(l);
	}
	cin.get(l);
	while(l!='\n') {
		la = pop(pila);
		if(la==l) {
			cin.get(l);
			if(pila==NULL)
				cout << "Son inversos";
		} else {
			if(pila==NULL)
				cout << "No son inversos";
				break;
			cout << "No son inversos...";
			break;
		}
	}

	mostrar(pila);

	return 0;
}
