#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

int a,b,p;
int aristas[100][100];
int distancias[100];
int visitado[100];

struct Arista
{
    int origen;
    int destino;
    int peso;
};

int dij(int x, int ver) {
    visitado[x] = 1;

    for (int i=1; i <= ver; i++) {
        if((visitado[i]==0) && (aristas[x][i]!=-1)) {
            if((distancias[x]+aristas[x][i] < distancias[i]) || (distancias[i]==-1)) {
                distancias[i]=distancias[x]+aristas[x][i];
            }
        }
    }

    int menor=-1, sp=-1;
    for(int i=0; i<= ver; i++) {
        if((visitado[i]==0) && (distancias[i]>=0) && ((sp>distancias[i]) || (sp==-1))) {
            sp=distancias[i];
            menor=i;
        }
    }

    if(menor!=-1) {
        dij(menor, ver);
        return 0;
    }
    return 0;
}

void mostrar(Arista lista) {
	cout << lista.origen << "\t" << lista.destino << "\t" << lista.peso << endl;
}

int main() {
    FILE* f;
    Arista N;
    Arista aux;

    f = fopen("Grafo.dat", "rb");

    fread(&N, sizeof(Arista), 1, f);
	mostrar(N);

    for(int i=0; i<=N.peso; i++) {
        for(int j=0; j <=N.peso; j++) {
            aristas[i][j]=-1;
        }
    }

    for(int i=0; i <= N.peso; i++) {
        distancias[i] = -1;
    }

    distancias[1]=0;

    while(!feof(f)) {
        fread(&aux, sizeof(Arista), 1, f);
        mostrar(aux);
        aristas[aux.origen][aux.destino]=aux.peso;
        aristas[aux.destino][aux.origen]=aux.peso;
    }

    dij(1, N.peso);

    for(int i=1; i<=N.peso; i++) {
	cout << "Minima distancia desde 1 hasta " << i << ": " << distancias[i] << endl;
    }

}
