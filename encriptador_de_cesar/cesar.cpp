#include <iostream>
using namespace std;

void descifrar(char mensaje[], int largo, int corrimiento);
void cifrar(char mensaje[], int largo, int corrimiento);
int indice_en_vector(char vec[], int largo, char obj);
int calcular_largo(char mensaje[]);

char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{
	char mensajeIngresado[300];
	char mensajeEncriptado[300];
	char cod;
	int corrimiento;

	do {
		cout << "Por favor indica que eso lo que queres hacer con un numero... 1 para cifrar, 2 para descifrar o 3 para aplicar fuerza bruta: ";
		cin >> cod;
	} while(cod != '1' && cod != '2' && cod!='3');

	if (cod == '1')
	{
		cout << "Ingresa en mensaje a cifrar: ";
		cin >> mensajeIngresado;
		
		int largo = calcular_largo(mensajeIngresado);

		do {
			cout << "Ingresa el corrimiento a aplicar en el cifrado: ";
			cin >> corrimiento;
		} while(corrimiento != 0 && sizeof(corrimiento) != 4);

		cifrar(mensajeIngresado, largo, corrimiento);

	} else if (cod == '2')
	{
		cout << "Ingresa el mensaje a descifrar: ";
		cin >> mensajeIngresado;
		
		int largo = calcular_largo(mensajeIngresado);

		do {
			cout << "Ingresa el corrimiento aplicado al cifrado: ";
			cin >> corrimiento;
		} while(corrimiento != 0 && sizeof(corrimiento) != 4);

		descifrar(mensajeIngresado, largo, corrimiento);
	} else if (cod == '3')
	{
		cout << "Ingresa el mensaje a descifrar: ";
		cin >> mensajeIngresado;

		int largo = calcular_largo(mensajeIngresado);

		// Deciframos con los 26 corrimientos posibles
		for (int i = 0; i < 26; ++i) 
		{
			descifrar(mensajeIngresado, largo, i+1);
			cout << endl;
		}
	}

	cout << endl;
	return 0;
}

void cifrar(char mensaje[], int largo, int corrimiento) {
	for (int i = 0; i < largo; ++i)
	{
		int posicion = indice_en_vector(alfabeto, 26, mensaje[i]) + corrimiento;
		if (posicion >= 26)
		{
			posicion = posicion-26; // Corregimos la posicion
		}

		cout << alfabeto[posicion]; // Imprime letra por letra el mensaje encriptado
	}
}

void descifrar(char mensaje[], int largo, int corrimiento) {
	for (int i = 0; i < largo; ++i)
	{
		int posicion = indice_en_vector(alfabeto, 26, mensaje[i]) - corrimiento;
		if (posicion < 0)
		{
			posicion = posicion+26; // Corregimos la posicion		
		}
		cout << alfabeto[posicion]; // Imprime letra por letra el mensaje encriptado
	}
}

int indice_en_vector(char vec[], int largo, char obj) {
	int i = 0;
	bool encontrado = false;

	while(!encontrado && i < largo) {
		if (obj == vec[i])
		{
			// Encontro el objeto en la posicion i
			encontrado = true;
		} else {
			i++;
		}
	}

	return i;
}

int calcular_largo(char mensaje[]) {
	int i = 0;

	while(mensaje[i] != '\0') {
		i++;
	}

	return i;
}