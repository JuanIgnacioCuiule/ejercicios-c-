#include <iostream>

using namespace std;

template <typename T> struct Nodo
{
	T info; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void push(Nodo<T>* &pila, T valor)
{ 	/*
	Me dan un valor de tipo T y la pila donde lo quiero guardar.
	Node<T>* &pila = pila es una ref a un puntero de nodo para poder
	odificar el orignial.
	*/
	Nodo<T>* nuevo = new Nodo<T>;	// Creo un nuevo nodo
	nuevo->info = valor;	// Guardo el valor como dato
	nuevo->sig = pila;	// Guardo el puntero al sig
	pila = nuevo;	// A pila le copia la direccion a la que apunta "nuevo"
}

template <typename T> T pop(Nodo<T>* &pila)
{
	T valor;
	Nodo<T>* viejo = pila;
	valor = pila->info;
	pila = pila->sig;
	delete viejo;
	return valor;
}

template <typename T> void mostrar(Nodo<T>* lista)
{	/*
	Nodo<T>* lista = Pedir un "clon" del original para poder mostrarlo
	como quiera.
	*/
	while (lista!= NULL){
		cout << lista->info << endl;
		lista = lista->sig;
	}
}

int main()
{
	Nodo<int> *pila = NULL; // Pila todavia vacia
	push(pila, 1);	// Pongo 1
	push(pila, 2);	// Pongo 2
	push(pila, 3);	// Pongo 3
	mostrar(pila);
	cout << "Borramos" << endl;
	while (pila) {
		cout << "Borre: " << pop(pila) << endl;
	}
	cout << "Listo nuevamente" << endl;
	mostrar(pila);
	cout << "Fin listado" << endl;
	return 0;
}
