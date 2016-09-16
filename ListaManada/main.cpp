#include <iostream>

using namespace std;

struct Manada {
	string descrip;	//tipo de animal
	int cab;	//cantidad de cabezas
	double peso;	//peso total
};

struct Nodo {
	Manada dato;	//valor que contiene el nodo
	Nodo* sig;	//puntero al siguiente nodo
};

void push(Nodo* &pila, Manada valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

Manada pop(Nodo* &pila)
{
	Manada valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

void mostrar_manada(Manada m)
{
	cout << m.descrip << '\t' << m.cab << '\t' << m.peso << endl;
}

void mostrar(Nodo* lista)
{
	while(lista != NULL)
	{
		mostrar_manada(lista->dato);
		lista = lista->sig;
	}
}

void agregar(Nodo*& cola, Manada valor)
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

void ingresarManada(Manada &m)
{
	cout << "Tipo de animal:\t\t";
	cin >> m.descrip;
	cout << "Cantidad de cabezas:\t";
	cin >> m.cab;
	cout << "Peso:\t\t";
	cin >> m.peso;
}

Manada crearManada(void)
{
	Manada m;
	cout << "Tipo de animal:\t\t";
	cin >> m.descrip;
	cout << "Cantidad de cabezas:\t";
	cin >> m.cab;
	cout << "Peso:\t\t";
	cin >> m.peso;
	return m;
}

bool buscar_lineal(Manada clave, Nodo* lista)
{
	while (lista != NULL) {
		if (lista->dato.descrip == clave.descrip &&
			lista->dato.cab == clave.cab &&
			lista->dato.peso == clave.peso)
			return true;
		lista = lista->sig;
	}
	return false;
}

int main()
{
	Nodo *pila = NULL;
	Manada m;

	ingresarManada(m);
	push(pila, m);
	ingresarManada(m);
	push(pila, m);
	ingresarManada(m);
	push(pila, m);

	cout << "Listando pila:" << endl;
	mostrar(pila);

	cout << endl << "Eliminamos" << endl;
	while(pila != NULL)
		mostrar_manada(&pila)
}
