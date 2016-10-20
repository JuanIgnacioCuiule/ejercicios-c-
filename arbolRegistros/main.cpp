#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo* izq;
	Nodo* der;
};

void insertar(Nodo* &arbol, int elem) {
	if (arbol == NULL) {
		Nodo* aux = new Nodo;
		aux->dato = elem;
		aux->izq = NULL;
		aux->der = NULL;
		arbol = aux;
	} else {
		if (elem < arbol->dato) {
			insertar(arbol->izq, elem);
		} else if (elem > arbol->dato) {
			insertar(arbol->der, elem);
		} else {
			cout << elem << " no entro por estar repetido" << endl;
		}
	}
	return;
}

void reemplazar(Nodo* &arbol, Nodo* &aux) {
	if (arbol->der == NULL) {
		aux->dato = arbol->dato;
		aux = arbol;
		arbol = arbol->izq;
	} else {
		reemplazar(arbol->der, aux);
	}
}

void borrar(Nodo* &arbol, int elem) {
		Nodo* aux = new Nodo;
		if (arbol == NULL)
			return;
			
		if (elem < arbol->dato)
			borrar(arbol->izq, elem);
			
		else if (elem > arbol->dato)
			borrar(arbol->der, elem);
			
		else if (elem == arbol->dato) {
			
			aux = arbol;
			if (arbol->izq == NULL)
				arbol = arbol->der;
				
			else if (arbol->der == NULL)
				arbol = arbol->izq;
				
			else
				reemplazar(arbol->izq, aux);
			
			
		}
}

void inOrden(Nodo* arbol){
	if (arbol != NULL) { 
		inOrden(arbol->izq);
		cout << " - " << arbol->dato;
		inOrden(arbol->der);
	}
	return; 
}

void preOrden(Nodo* arbol){ 
	if (arbol != NULL) { 
		cout << " - " << arbol->dato;
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
	return; 
}

void posOrden(Nodo* arbol){ 
	if (arbol != NULL) { 
		posOrden(arbol->izq);
		posOrden(arbol->der);
		cout << " - " << arbol->dato;
	}
	return; 
}

bool buscar(Nodo* arbol, int elem) {
	if (arbol == NULL) {
		return 0;
	} else if (elem < arbol->dato) {
		buscar(arbol->izq, elem);
	} else if (elem > arbol->dato) {
		buscar(arbol->der, elem);
	} else {
		return 1;
	}
}

void bubble(int vec_des[])  {
	int i, j;
	int aux;
	int ordenado = 0;
	for( i = 0; i < 10 - 1 && ordenado == 0; i++){
		ordenado = 1;
		for( j = 0; j < 10 - 1 - i; j++){
			if( vec_des[j] > vec_des[j+1]){
				ordenado = 0;
				aux = vec_des[j];
				vec_des[j] = vec_des[j+1];
				vec_des[j+1] = aux;
			}
		}
	}
}



int main() {
	
	srand(time(NULL));
	
	Nodo* raiz = NULL;
	int busq = 0;
	int e_borrar = 0;
	
	int v[10];
	
	for(int a = 0; a < 10; a++) {
		v[a] = rand()%100;
	}
	
	bubble(v);
	
	insertar(raiz, v[4]);
	for(int a = 0; a < 10; a++) {
		insertar(raiz, v[a]);
	}
	
	cout << "Ingrese el numero que quiere buscar: ";
	cin >> busq;
	
	if (buscar(raiz, busq)) {
		cout << "El elemento " << busq << " se encuentra en el arbol" << endl;
	} else {
		cout << "El elemento " << busq << " NO se encuentra en el arbol" << endl;
	}
	
	cout << "inOrden: ";
	inOrden(raiz);
	cout << "\n posOrden: ";
	posOrden(raiz);
	cout << "\n preOrden: ";
	preOrden(raiz);
	cout << "\n";
	
	cout << "Ingrese el numero que quiere borrar: ";
	cin >> e_borrar;
	borrar(raiz, e_borrar);
	
	cout << "inOrden: ";
	inOrden(raiz);
	cout << "\n posOrden: ";
	posOrden(raiz);
	cout << "\n preOrden: ";
	preOrden(raiz);
	cout << "\n";
	
	
}
