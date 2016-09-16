#include <iostream>

using namespace std;

template <typename T> struct Nodo
{
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void push(Nodo<T>* &pila, T valor)
{ 	/*
	Me dan un valor de tipo T y la pila donde lo quiero guardar.
	Node<T>* &pila = pila es una ref a un puntero de nodo para poder
	odificar el orignial.
	*/
	Nodo<T>* nuevo = new Nodo<T>;	// Creo un nuevo nodo
	nuevo->dato = valor;	// Guardo el valor como dato
	nuevo->sig = pila;	// Guardo el puntero al sig
	pila = nuevo;	// A pila le copia la direccion a la que apunta "nuevo"
}

template <typename T> T pop(Nodo<T>* &pila)
{
	T valor;
	Nodo<T>* viejo = pila;
	valor = pila->dato;
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
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T> int buscar_max(Nodo<T>* lista)
{
	if (lista == NULL)
		return -1;
	int mayor = lista->dato;
	while (lista != NULL) {
		if (lista->dato > mayor)
			mayor = lista->dato;
		lista = lista->sig;
	}
	return mayor;
}

template <typename T> double promerdio_mayores(Nodo<T>* lista, double vara)
{
	if (lista == NULL)
		return -1;

	int cont = 0;
	double acum = 0;

	while (lista != NULL) {
		if (lista->dato >= vara) {
			cont++;
			acum = acum+lista->dato;
		}
		lista = lista->sig;
	}
	return acum == 0 ? 0 : acum/cont;
}

int main()
{
	Nodo<int> *pila = NULL;
	push(pila, 20000);
	push(pila, 10);
	push(pila, 11);
	push(pila, 13000);
	push(pila, 121);
	push(pila, 132);
	push(pila, 4000);
	cout << "Listo..." << endl;
	mostrar(pila);
	cout << "Fin listado" << endl;
	cout << "El maximo de la lista es: " << buscar_max(pila) << endl;
	cout << "Borramos" << endl;
	while (pila) {
		cout << "Borre: " << pop(pila) << endl;
	}
	cout << "Listo nuevamente" << endl;
	mostrar(pila);
	cout << "Fin listado" << endl;
	cout << "El maximo de la lista ahora es: " << buscar_max(pila) << endl;

	Nodo<double> *pilaDouble = NULL;
	push(pilaDouble, 3.3);
	push(pilaDouble, 8.1);
	push(pilaDouble, 9.3);
	push(pilaDouble, 1.2);
	push(pilaDouble, 4.5);
	push(pilaDouble, 5.3);
	push(pilaDouble, 4.0);
	cout << "Listo..." << endl;
	mostrar(pilaDouble);
	cout << "Fin listado" << endl;
	cout << "El promedio de las notas aprobadas (>=4) es: " << promerdio_mayores(pilaDouble, 4.0) << endl;
	return 0;
}
