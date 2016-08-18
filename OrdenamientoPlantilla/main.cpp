#include <iostream>
#include <cstdlib>
#include <string.h>
#include <strings.h>

using namespace std;

template <typename T> void mostrar(T vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

//Algoritmo de inserción
template <typename T> void ordenar(T vec[], int dim, int (*criterio)(T, T))
{
	int i, j;
	T aux;

	for (i=1 ; i < dim ; i++) {
		aux = vec[i];
		j = i-1;

		//&& vec[j] > aux
		while (j >= 0 && criterio(vec[j], aux) > 0) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j+1] = aux;
	}
}

// ============ ENTEROS
int criterio_int_asc(int a, int b)
{
	return a - b;
}

int criterio_int_des(int a, int b)
{
	return b - a;
}

// ============ CADENAS
int criterio_cad_asc(const char *a, const char *b)
{
	return strcmp(a, b);
}

int criterio_cad_des(const char *a, const char *b)
{
	return -strcmp(a, b);
}

// ============ STRING
int criterio_str_asc(string a, string b)
{
	if (a > b)
		return 1;
	else if (b < a)
		return -1;
	else
		return 0;
}

int criterio_str_des(string a, string b)
{
	return a > b ? -1 : (b > a ? 1 : 0);
}

int criterio_str_case(string a, string b)
{
	//strcasecmp declarada en strings.h
	//c_str devuelve un const char* terminado en \0
	return strcasecmp(a.c_str(), b.c_str());
}

int main()
{
	int vec_ent[10] = {9, 2, 5, 3, 7, 4, 1, 10, 6, 7};
	const char *vec_cad[10] = {"uno", "dos", "tres", "cuatro", "cinco", "seis",
				"siete", "ocho", "nueve", "diez"};
	string vec_str[10] = {"Pedro", "ana", "Juan", "Maria", "Jose", "Juana",
			      "Beatriz", "Sebastian", "Miguel", "Sofia"
			     };

	// ============ Con enteros
	cout << "Vector enteros original:" << endl;
	mostrar<int>(vec_ent, 10);
	cout << endl;

	cout << "Vector enteros Ascendente:" << endl;
	ordenar<int>(vec_ent, 10, criterio_int_asc);
	mostrar<int>(vec_ent, 10);
	cout << endl;

	cout << "Vector enteros Descendente:" << endl;
	ordenar<int>(vec_ent, 10, criterio_int_des);
	mostrar<int>(vec_ent, 10);
	cout << endl;

	// ============ Con cadenas
	cout << "Vector cadenas original:" << endl;
	mostrar<const char *>(vec_cad, 10);
	cout << endl;

	cout << "Vector cadenas Ascendente:" << endl;
	ordenar<const char *>(vec_cad, 10, criterio_cad_asc);
	mostrar<const char *>(vec_cad, 10);
	cout << endl;

	cout << "Vector cadenas Descendente:" << endl;
	ordenar<const char *>(vec_cad, 10, criterio_cad_des);
	mostrar<const char *>(vec_cad, 10);
	cout << endl;

	// ============ Con strings
	cout << "Vector strings original:" << endl;
	mostrar<string>(vec_str, 10);
	cout << endl;

	cout << "Vector strings Ascendente:" << endl;
	ordenar<string>(vec_str, 10, criterio_str_asc);
	mostrar<string>(vec_str, 10);
	cout << endl;

	cout << "Vector strings Descendente:" << endl;
	ordenar<string>(vec_str, 10, criterio_str_des);
	mostrar<string>(vec_str, 10);
	cout << endl;

	cout << "Vector strings Ascendente sin mayusculas y minusculas:" << endl;
	ordenar<string>(vec_str, 10, criterio_str_case);
	mostrar<string>(vec_str, 10);
	cout << endl;

	return EXIT_SUCCESS;
}
