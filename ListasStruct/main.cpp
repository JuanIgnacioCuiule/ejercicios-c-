#include <iostream>

using namespace std;

struct Manada {
	string descrip;	//tipo de animal
	int cab;	//cantidad de cabezas
	double peso;	//peso total
};

struct Nodo {
	Manada dato; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};

void push(Nodo* &pila, Manada valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}
// Notar que en push y pop no cambia nada, salvo el tipo de dato int por Manada
Manada pop(Nodo* &pila)
{
	Manada valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
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

void mostrar_manada(Manada m)
{
	cout << m.descrip << '\t' << m.cab << '\t' << m.peso << endl;
}

void mostrar(Nodo* lista)
{
	while (lista != NULL) {
		mostrar_manada(lista->dato);
		lista = lista->sig;
	}
}

bool buscar_lineal(Manada clave, Nodo* lista)
{
	while (lista != NULL) {
		// podría usar un criterio, para que no quede fijo en el código de buscar
		if (lista->dato.descrip == clave.descrip
		 && lista->dato.cab == clave.cab
		 && lista->dato.peso == clave.peso)
			return true;
		lista = lista->sig;
	}
	return false;
}

void ingresarManada(Manada &m)
{//Lee los datos y los coloca en la estructura que nos pasan como parámetro
	cout << "Tipo de animal:\t\t";
	cin >> m.descrip;
	cout << "Cantidad de cabezas:\t";
	cin >> m.cab;
	cout << "Peso total:\t\t";
	cin >> m.peso;
	cout << endl;
}

Manada crearManada(void)
{// devuelve una estructura, así que no hace falta pasarle parámetro
	Manada m;
	cout << "Tipo de animal:\t\t";
	cin >> m.descrip;
	cout << "Cantidad de cabezas:\t";
	cin >> m.cab;
	cout << "Peso total:\t\t";
	cin >> m.peso;
	cout << endl;
	return m;
}

int main()
{
	Nodo *pila = NULL;
	Manada m;

	ingresarManada(m);//Podría usar m = crearManada(), son solo dos modos distintos
	push(pila, m);
	ingresarManada(m);
	push(pila, m);
	ingresarManada(m);
	push(pila, m);
	cout << "Listando Pila:" << endl;
	mostrar(pila);
	cout << endl << "Eliminamos" << endl;
	while (pila != NULL)
		mostrar_manada(pop(pila));
	cout << endl << "Confirmamos pila vacía:" << endl;
	mostrar(pila);
	cout << "fin mostrar pila" << endl;

	Nodo* cola = NULL;
	m = crearManada();
	agregar(cola, m);
	agregar(cola, crearManada());//puedo evitar el uso de m como intermediario
	agregar(cola, crearManada());
	cout << endl << "Listando cola:" << endl;
	mostrar(cola);
	cout << endl << "Eliminamos" << endl;
	while (cola != NULL)
		mostrar_manada(pop(cola));
	cout << endl << "Confirmamos cola vacía:" << endl;
	mostrar(cola);
	cout << "fin mostrar cola" << endl;

	agregar(cola, crearManada());
	agregar(cola, crearManada());
	agregar(cola, crearManada());
	cout << endl << "Datos" << endl;
	mostrar(cola);

	cout << endl << "Ingrese la manada a buscar: " << endl;
	m = crearManada();
	while (m.descrip != "") {
		if (buscar_lineal(m, cola))
			cout << "SI está en la lista" << endl;
		else
			cout << "NO está en la lista" << endl;
		cout << endl << "Ingrese la manada a buscar: "<< endl;
		m = crearManada();
	}
	return 0;
}
