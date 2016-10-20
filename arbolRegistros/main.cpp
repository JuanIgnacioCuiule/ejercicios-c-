#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* izq;
	Nodo* der;
};

void insertar(Nodo* &raiz, int dato) {
	if(raiz == NULL) {
		Nodo* aux = new Nodo;
		aux->dato = dato;
		aux->izq = NULL;
		aux->der = NULL;
		raiz = aux;
	} else {
		if(dato < raiz->dato) {
			insertar(raiz->izq, dato);
		} else if(dato > raiz->dato) {
			insertar(raiz->der, dato);
		} else {
			cout << dato << " no entro por estar repetido" << endl;
		}
	}
	return;
}

void inOrden(Nodo* arbol){
	if (arbol != NULL) { 
		inOrden(arbol->izq);
		cout << arbol->dato;
		inOrden(arbol->der);
	}
	return; 
}

int main() {
	
	Nodo* raiz = NULL;
	
	insertar(raiz, 10);
	insertar(raiz, 5);
	insertar(raiz, 20);
	insertar(raiz, 3);
	insertar(raiz, 4);
	insertar(raiz, 1);
	insertar(raiz, 6);
	
}
