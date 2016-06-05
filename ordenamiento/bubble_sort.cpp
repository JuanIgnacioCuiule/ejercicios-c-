#include <iostream>
#include <vector>
using namespace std;

int calcular_largo(int numeros[]);

int main(){

	int indice_numeros = 0;
	int numeros[300];

	cout << "Ingrese el primer numero: ";
	cin >> numeros[0];

	while (numeros[indice_numeros] != 0) {
		indice_numeros++;
		cout << "Ingrese el numero " << indice_numeros+1 << ": ";
		cin  >> numeros[indice_numeros];
	}

	int cont = 0;

	cout << "Se ingresaron: " << calcular_largo(numeros) << " numeros." << endl;

	clock_t tStart = clock(); 
	
	for (int i = 0; i < calcular_largo(numeros); ++i)
	{	
		for (int a = 0; a < (calcular_largo(numeros)-1); ++a)
		{
			if (numeros[i] < numeros[a]){

				cont++;

				int num = numeros[i];
				int num_siguiente = numeros[a];

				numeros[i] = num_siguiente;
				numeros[a] = num;
			}
		}
	}

	cout << "Fueron necesarios: " << cont << " pasos." << endl;

	float tiempo_de_ejecucion = (clock()-tStart)/1000.0;
	cout << "El tiempo de ejecucion fue de: " << tiempo_de_ejecucion << " segundos." << endl;
	return 0;
}


int calcular_largo(int numeros[]) {
	int b = 0;

	while(numeros[b] != 0) {
		b++;
	}

	return b;
}