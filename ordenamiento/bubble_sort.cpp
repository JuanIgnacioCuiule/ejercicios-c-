#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void burbuja( int largo, int vector[]);
int calcular_largo(int vector[]);

int main()
{
  clock_t t;
  int vector[300], indice = 0;
  srand(time(NULL));

  cout << "Ingrese el "<< indice+1 <<" numero: ";
  cin >> vector[indice];

  while(vector[indice] != 0){
    indice++;
    cout << "Ingrese el " << indice+1 << "º numero: ";
    cin >> vector[indice];
  }

  int largo_vector = calcular_largo(vector);

  cout << "El vector desordenado: " << endl;

  for(int i = 0; i < largo_vector; i++){
    cout << vector[i];
  }

  burbuja(largo_vector, vector);

  cout << "El vector ordenado: " << endl;

  for(int i = 0; i < largo_vector; i++){
    cout << vector[i] << " ";
  }

  return 0;
}

void burbuja( int largo, int vector[])
{
  clock_t ticks;
  ticks = clock();
  int cambios = 0, comparaciones = 0;
  int i, j;
  int aux;
  int ordenado = 0;
  for( i = 0; i < largo - 1 && ordenado == 0; i++){
    comparaciones++;
    ordenado = 1;
      for( j = 0; j < largo - 1 - i; j++){
        comparaciones++;
        if( vector[j] > vector[j+1]){
          ordenado = 0;
          aux = vector[j];
          vector[j] = vector[j+1];
          vector[j+1] = aux;
          cambios++;
        }
    }
  }
  ticks = clock() - ticks;
  cout << "Se realizaron: "<< cambios <<" cambios." << endl;
  cout << "Se realizaron: "<< comparaciones <<" comparaciones." << endl;
  cout << "El proceso tomo: "<< ((float)ticks)/CLOCKS_PER_SEC <<" segundos." << endl;
}

int calcular_largo(int vector[]) {
	int b = 0;
	while(vector[b] != 0) {
		b++;
	}
	return b;
}
