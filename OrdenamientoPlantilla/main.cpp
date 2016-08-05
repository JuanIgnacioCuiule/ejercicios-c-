#include <iostream>
#include <string.h>
#include <strings.h>

using namespace std;


// Creamos un template para que una funcion nos sirva para distintos tpos de
// datos... para eso usamos <typename T> y para usarlo lo ponemos como
// mostrar<tipodedato>(vec, dim)
template <typename T> void mostrar (T vec[], int dim)
{
    for(int i=0; i < dim; i++)
        cout << i << ": " << vec[i] << endl;
}

template <typename T> void ordenar (T vec[], int dim, int (*criterio)(T, T))
{
	int i,j;
	T aux;

	for (i=1; i<dim; i++)
	{
		aux = vec[i];
		j = i-1;

		while(j>=0 && criterio(vec[j],aux) > 0)
		{
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = aux;
	}
}

int criterio_int_asc(int a, int b)
{
	return a - b;
}

int criterio_int_des(int a, int b)
{
	return b - a;
}

int criterio_str_asc(string a, string b)
{
	if(a > b)
		return 1;
	else if (a == b)
		return -1;
	else
		return 0;
}

int criterio_str_des(string a, string b)
{
	return a > b ? -1 : (b > a ? 1 : 0);
}

int criterio_cad_asc(const char *a, const char *b)
{
	return strcmp(a,b);
}

int criterio_cad_des(const char *a, const char *b)
{
	return -strcmp(a,b);
}

int main()
{
    int vec_ent[10] = {9, 2, 5, 3, 7, 4, 1, 10, 6, 7};
    string vec_str[10] = {"Pedro", "ana", "Juan", "Maria", "Jose", "Juana", "Beatriz", "Seabstian", "Miguel", "Sofia"};
    const char *vec_cadena[10] = {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"};

    cout << "Vectores enteros original:" << endl;
    mostrar<int>(vec_ent, 10);
    cout << endl;

    cout << "Vectores enteros ordenados_asc:" << endl;
    ordenar<int>(vec_ent, 10, criterio_int_asc);
    mostrar<int>(vec_ent, 10);
    cout << endl;

    cout << "Vectores enteros ordenados_des:" << endl;
    ordenar<int>(vec_ent, 10, criterio_int_des);
    mostrar<int>(vec_ent, 10);
    cout << endl;

    cout << "Valores strings original:" << endl;
    mostrar<string>(vec_str, 10);
    cout << endl;

    cout << "Valores strings ordenados_asc:" << endl;
    ordenar<string>(vec_str,10, criterio_str_asc);
    mostrar<string>(vec_str, 10);
    cout << endl;

    cout << "Valores strings ordenados_des:" << endl;
    ordenar<string>(vec_str,10, criterio_str_des);
    mostrar<string>(vec_str, 10);
    cout << endl;

    cout << "Valores cadena original:" << endl;
    mostrar<const char*>(vec_cadena, 10);
    cout << endl;

    cout << "Valores cadena ordenados_asc:" << endl;
    ordenar<const char*>(vec_cadena,10, criterio_cad_asc);
    mostrar<const char*>(vec_cadena, 10);
    cout << endl;

    cout << "Valores cadena ordenados_des:" << endl;
    ordenar<const char*>(vec_cadena,10, criterio_cad_des);
    mostrar<const char*>(vec_cadena, 10);
    cout << endl;

    return 0;
}
