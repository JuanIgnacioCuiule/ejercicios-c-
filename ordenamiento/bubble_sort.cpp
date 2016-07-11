#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void burbuja( int largo, int vector[]);
int calcular_largo(int vector[]);

int main()
{
  clock_t t;
  int vector[300], indice = 0;
  srand(time(NULL));

  printf("Ingrese el %dº numero: ", indice+1 );
  scanf(" %d", &vector[indice]);

  while(vector[indice] != 0){
    indice++;
    printf("Ingrese el %dº numero: ", indice+1 );
    scanf(" %d", &vector[indice]);
  }

  int largo_vector = calcular_largo(vector);

  printf("El vector desordenado: \n");

  for(int i = 0; i < largo_vector; i++){
    printf("%d ",vector[i]);
  }

  burbuja(largo_vector, vector);

  printf("El vector ordenado: \n");

  for(int i = 0; i < largo_vector; i++){
    printf("%d ",vector[i]);
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
  printf("Se realizaron: %d cambios.\n", cambios);
  printf("Se realizaron: %d comparaciones.\n", comparaciones);
  printf("El proceso tomo: %f segundos.\n", ((float)ticks)/CLOCKS_PER_SEC);
}

int calcular_largo(int vector[]) {
	int b = 0;
	while(vector[b] != 0) {
		b++;
	}
	return b;
}
