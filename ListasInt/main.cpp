#include <iostream>

using namespace std;

struct Nodo {
	int dato; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};

void push(Nodo* &pila, int valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(Nodo* &pila)
{
	int valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

void agregar(Nodo*& cola, int valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = NULL;
	if (cola == NULL) {
		cola = nuevo;
	} else {
		Nodo* aux = cola;
		while (aux->sig != NULL) //mientras que no sea el último
			aux = aux->sig;  //avanzo al siguiente
		aux->sig = nuevo;
	}
}

void mostrar(Nodo* lista)
{
	while (lista != NULL) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

bool buscar_lineal(int clave, Nodo* lista)
{
	while (lista != NULL) {
		if (lista->dato == clave)
			return true;
		lista = lista->sig;
	}
	return false;
}

int main()
{
	Nodo *pila = NULL;
	push(pila, 1);
	push(pila, 2);
	push(pila, 3);
	cout << "Pila, ingresamos: 1 2 3. Listamos:" << endl;
	mostrar(pila);
	cout << endl << "Eliminamos" << endl;
	while (pila != NULL)
		cout << pop(pila) << endl;
	cout << endl << "Confirmamos pila vacía:" << endl;
	mostrar(pila);
	cout << "fin mostrar pila" << endl;

	Nodo* cola = NULL;
	agregar(cola, 1);
	agregar(cola, 2);
	agregar(cola, 3);
	cout << endl << "Cola ingresamos: 1 2 3. Listamos:" << endl;
	mostrar(cola);
	cout << endl << "Eliminamos" << endl;
	while (cola != NULL)
		cout << pop(cola) << endl;
	cout << endl << "Confirmamos cola vacía:" << endl;
	mostrar(cola);
	cout << "fin mostrar cola" << endl;

	agregar(cola, 5);
	agregar(cola, 20);
	agregar(cola, 15);
	cout << endl << "Datos" << endl;
	mostrar(cola);
	int nro;
	cout << endl << "Ingrese el número a buscar: ";
	while (cin >> nro) {
		if (buscar_lineal(nro, cola))
			cout << nro << " SI está en la lista" << endl;
		else
			cout << nro << " NO está en la lista" << endl;
		cout << "Ingrese el número a buscar: ";
	}
	return 0;
}
