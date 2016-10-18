#include <iostream>
using namespace std;

/*
Caracteres especiales - No permitidos
Espacios - No permitidos
Caracteres numericos - Al menos uno
Letras mayusculas - Al menos una
Minimo y maximo de largo - De 6 a 20 caracteres
Caracteres repetidos - Maximo 2 caracteres consecutivos repetidos
*/

int calcular_largo(char mensaje[]) {
	int i = 0;
	while(mensaje[i] != 0) {
		i++;
	}
	return i;
}

int main()
{
	char pass[100];

	cin >> pass;

	cout << endl << "--Comprobando largo de contraseña ingresada..." << endl;
	if(calcular_largo(pass) < 6 || calcular_largo(pass) > 20) {
		cout << "La contraseña no cumple con las condiciones de longitud requeridas" << endl;
		cout << "6 o caracteres, 20 o menos" << endl << endl;
		return 0;
	} else {
		cout << "*La contraseña cumple con las condiciones de longitus requeridas" << endl << endl;
	}

	cout << "--Comprobando existencia de letra mayuscula..." << endl;
	bool mayus = false;
	for(int i = 0; i < calcular_largo(pass); i++) {
		if(pass[i] >= 65 && pass[i] <= 90) {
			mayus = true;
		}
	}
	if(mayus) {
		cout << "*La contraseña tiene mayuscula/s" << endl << endl;
	} else {
		cout << "La contraseña no contiene ninguna mayuscula" << endl << endl;
		return 0;
	}

	cout << "--Comprobando existencia de letra minuscula..." << endl;
	bool minus = false;
	for(int i = 0; i < calcular_largo(pass); i++) {
		if(pass[i] >= 97 && pass[i] <= 122) {
			minus = true;
		}
	}
	if(minus) {
		cout << "*La contraseña tiene minuscula/s" << endl << endl;
	} else {
		cout << "La contraseña no contiene ninguna minuscula" << endl << endl;
		return 0;
	}

	cout << "--Comprobando existencia de numetos..." << endl;
	bool num = false;
	for(int i = 0; i < calcular_largo(pass); i++) {
		if(pass[i] >= 48 && pass[i] <= 57) {
			num = true;
		}
	}
	if(num) {
		cout << "*La contraseña tiene numero/s" << endl << endl;
	} else {
		cout << "La contraseña no contiene ningun numero" << endl << endl;
		return 0;
	}

	cout << "--Comprobando que no incluya espacios..." << endl;
	bool espacios = false;
	for(int i = 0; i < calcular_largo(pass); i++) {
		if(pass[i] == 32) {
			espacios = true;
		}
	}
	if(espacios) {
		cout << "La contraseña tiene espacio/s" << endl << endl;
		return 0;
	} else {
		cout << "*La contraseña no contiene ningun espacio" << endl << endl;

	}

	cout << "--Comprobando que no incluya caracteres especiales..." << endl;
	bool especiales = false;
	for(int i = 0; i < calcular_largo(pass); i++) {
		if(pass[i] < 48 || (pass[i] > 57 && pass[i] < 65) || (pass[i] > 90 && pass[i] < 97) || pass[i] > 122) {
			especiales = true;
		}
	}
	if(especiales) {
		cout << "La contraseña tiene caracteres especiales" << endl << endl;
		return 0;
	} else {
		cout << "*La contraseña no contiene ningun caracter especial" << endl << endl;

	}

	cout << "--Comprobando que no mas de dos caracteres consecutivos repetidos..." << endl;
	bool repetidos = false;
	for(int i = 2; i < calcular_largo(pass); i++) {
		if(pass[i] == pass[i-1] && pass[i] == pass[i-2]) {
			repetidos = true;
		}
	}
	if(repetidos) {
		cout << "La contraseña tiene caracteres consecutivos repetidos mas de 2 veces" << endl << endl;
		return 0;
	} else {
		cout << "*La contraseña no contiene ningun caracter consecutivo repetido mas de 2 veces" << endl << endl;

	}

	return 0;

}
