#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T> void mostrar(T vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

template <typename T> int buscar_lineal(T clave, T vec[], int dim, int (*criterio)(T, T))
{
	for (int i = 0; i < dim; i++)
		if (criterio(vec[i], clave) == 0)
			return i;
	return -1;
}

template <typename T> int buscar_lineal_ord(T clave, T vec[], int dim, int (*criterio)(T, T))
{
	int i;
	for (i = 0; i < dim && criterio(vec[i], clave) < 0; i++);
	if (i < dim && criterio(vec[i], clave) == 0)
		return i;
	else
		return -1;
}

template <typename T> int buscar_bin(T clave, T vec[], int dim, int (*criterio)(T, T))
{
	int inf = 0;
	int sup = dim - 1;
	int medio;
	while (inf <= sup) {
		medio = (inf + sup) / 2;
		// llamado de atención en 2006 x Joshua Bloch de Google
		// https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
		//medio = inf + ((sup - inf) / 2);
		if (criterio(vec[medio], clave) < 0)
			inf = medio + 1;
		else if (criterio(vec[medio], clave) > 0)
			sup = medio - 1;
		else //Lo encontramos!!
			return medio;
	}
	return -1;
}

// ============ ENTEROS
int criterio_int(int a, int b)
{
	return a - b;
}

// ============ STRING
int criterio_str(string a, string b)
{
	if (a == b)
		return 0;
	else
		return a > b ? 1 : -1;
	//return a.compare(b);
}

int main()
{
	int vec_ent[10] =	{2, 7, 9, 13, 17, 24, 31, 33, 46, 72};
				//{25, 7, 92, 13, 17, 74, 61, 53, 2, 4};
	string vec_str[10] =
//			     {"Pedro", "Ana", "Juan", "Maria", "Jose", "Juana",
//			      "Beatriz", "Sebastian", "Miguel", "Sofia"
//			     };
			     {"Ana", "Beatriz", "Jose", "Juan", "Juana", "Maria",
			      "Miguel", "Pedro", "Sebastian", "Sofia"
			     };
	int valor, pos;
	string s;

	cout << "Vector:" << endl;
	mostrar(vec_ent, 10);

	cout << endl << "ingrese el valor a buscar: ";
	while (cin >> valor) { //para terminar usar una letra
		pos = buscar_bin(valor, vec_ent, 10, criterio_int);
		if (pos >= 0)
			cout << "El valor " << valor
			<< " se encuentra en el indice " << pos << endl;
		else
			cout << "El valor " << valor
			<< " NO se encuentra en el vector" << endl;

		cout << endl << "ingrese el valor a buscar: ";
	}
	//al poner la letra prendi failbit, debo limpiar para poder seguir
	cin.clear();
	cin.ignore(10, '\n'); // salteo la letra usada para frenar

	cout << endl << "*****" << endl << "Busqueda de cadenas" << endl;
	mostrar(vec_str, 10);
	cout << endl << "ingrese la cadena a buscar: ";
	while (cin >> s) { //para terminar usar EOF (Ctrl+D en linux y Ctrl+Z en windows)
		pos = buscar_bin(s, vec_str, 10, criterio_str);
		if (pos >= 0)
			cout << "La cadena  " << s
			<< " se encuentra en el indice " << pos << endl;
		else
			cout << "La cadena " << s
			<< " NO se encuentra en el vector" << endl;

		cout << endl << "ingrese la cadena a buscar: ";
	}

	return EXIT_SUCCESS;
}
