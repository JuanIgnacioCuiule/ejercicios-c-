#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

long calcular_largo(char mensaje[]);
long mcd(long a, long b);
void generar_variables(long &p, long &q, long &n, long &e, long &d, long &phi_n, long primeros_5[]);
void encriptar(char mensaje[], char salida[], long e, long n);
void desencriptar(char mensaje[], char salida[], long d, long n);
long indice_en_vector(char vec[], long largo, char obj);

char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{
	srand(time(NULL));

	for (long i = 0; i < 5; i++){
		long asciiVal = rand()%29 + 97;
		cout << (char) asciiVal << " is " << asciiVal << endl;
	}

	long primeros_5[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	long p, q, n, e, d, phi_n;

	// p y q numeros primos
	// e <-- clave de encriptacion o clave publica
	// d <-- clave de desencriptacion o clave privada
	// phi <-- cantidad de numeros coprimos de un numero

	char mensaje_plano[100], mensaje_encriptado[100];

	generar_variables(p, q, n, e, d, phi_n, primeros_5);
	
	cout << "p: " << p << " q: " << q << " n: " << n  << endl;
	cout << " phi(n): " << phi_n << " e: " << e << " d: " << d << endl;
	cout << "clave publica: (" << e << ", " << n << ")" << endl;
	cout << "clave privada: (" << d << ", " << n << ")" << endl;
	
	cin >> mensaje_plano;

	encriptar(mensaje_plano, mensaje_encriptado, e, n);

	for (long i = 0; i < calcular_largo(mensaje_encriptado); ++i)
	{
		cout << mensaje_encriptado[i];
	}
	
	cout << endl;

	/*char salida[100];

	desencriptar(mensaje_encriptado, salida, d, n);

	for (long i = 0; i < calcular_largo(salida); ++i)
	{
		cout << salida[i];
	}
	cout << endl;
	*/

	return 0;

}

long calcular_largo(char mensaje[]) {
	long i = 0;

	while(mensaje[i] != '\0') {
		i++;
	}

	return i;
}

long mcd(long a, long b) {
    while (a != b){
		while (a > b){
			a -= b;
		}
		while (b > a){
			b -= a;
		}
    }
    return a;
}

void encriptar(char mensaje[], char salida[], long e, long n) {
	for (long i = 0; i < calcular_largo(mensaje); ++i)
	{
		long letra = (long) mensaje[0];
		long potencia = pow(letra, e);
		long resto = fmod(potencia, n);
		salida[i] = (char) resto;
		cout << "potencia: " << potencia << " resto: " << (int) resto << endl;
	}
}

void desencriptar(char mensaje[], char salida[], long d, long n) {
	for (long i = 0; i < calcular_largo(mensaje); ++i)
	{
		long letra = (long) mensaje[i];
		long resto = fmod(pow(letra, d), n);
		salida[i] = (char) resto;
	}	
}

void generar_variables(long &p, long &q, long &n, long &e, long &d, long &phi_n, long primeros_5[]) {
	p = primeros_5[rand() % 4];
	q = primeros_5[rand() % 4];
	n = p*q;
	phi_n = (p-1)*(q-1);
	e = phi_n - 1;
	d = phi_n * (rand() % 5 + 1) + e;
	while(mcd(e,n)!=1 || mcd(e,phi_n)!=1)
	{
		e--;
	}
}

long indice_en_vector(char vec[], long largo, char obj) {
	long i = 0;
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







