#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

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

void copiarVec(int vec1[], int vec2[]) {
	for( int i = 0; i < 50; i++) {
		vec2[i] = vec1[i];
	}
}

int media(int vec_des[])  {
	int i, j;
	int aux;
	int ordenado = 0;
	int vec_ord[50];
	copiarVec(vec_des, vec_ord);
	for( i = 0; i < 50 - 1 && ordenado == 0; i++){
		ordenado = 1;
		for( j = 0; j < 50 - 1 - i; j++){
			if( vec_ord[j] > vec_ord[j+1]){
				ordenado = 0;
				aux = vec_ord[j];
				vec_ord[j] = vec_ord[j+1];
				vec_ord[j+1] = aux;
			}
		}
	}
	return vec_ord[25];
}



int main() {

	srand(time(NULL));
	Nodo* raiz = NULL;
	int busq = 0;
	int e_borrar = 0;

	int v[50];

	for(int a = 0; a < 50; a++) {
		v[a] = rand()%1000;
	}


	cout << media(v) << " media \n";
	insertar(raiz, v[media(v)]); // Insertamos la media como raiz,
				      // esto nos da mas chances de tener un arbol balanceado

	for(int a = 0; a < 50; a++) {
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
