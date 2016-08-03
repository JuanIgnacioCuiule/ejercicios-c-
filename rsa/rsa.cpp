#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long int maximo_comun_divisor(long int a, long int b);
long int modInverso(long int a, long int m);
long int potencia_modular(int base, long int exponent, long int modulus);
void encriptar(char mensajePlano[], long int mensajeEncriptado[], long int e, long int n);
void desencriptar(long int mensajeEncriptado[], char salida[], long int e, long int n);
int calcular_largo(long int mensaje[]);


int main()
{

	srand(time(NULL));

	int eleccion_menu;

	printf("Ingresa el numero correspondiente a la funcion que quieras usar\n");
	printf("1. Generar claves publica y privada\n");
	printf("2. Encriptar desde archivo\n");
	printf("3. Desencriptar desde archivo\n");

	scanf("%d", &eleccion_menu);

	if (eleccion_menu == 1)
	{	// GENERAR CLAVES PUBLICA Y PRIVADA
		int primos[10] = {17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

		// p y q dos numeros primos...
		int p = primos[rand()%10];
		int q = primos[rand()%10];

		// n y euler(n)...
		long int n = p*q;
		long int phi_n = (p-1)*(q-1);

		// e tal que 1 < e < euler(n) y e coprimo con n y euler(n)
		long int e = rand()%phi_n;
		while(maximo_comun_divisor(e, n) != 1 || maximo_comun_divisor(e, phi_n) != 1)
		{
			e = rand()%phi_n;
		}

		// d tal que (d*e)%phi_n = 1
		// Usamos la funcion modIverse para generar la d...
		long int d = modInverso(e, phi_n) + phi_n * (rand()%5 + 1);

		printf("--- Las claves son ---\n");
		printf("--- publica (%li,%li) ---\n", e, n);
		printf("--- privada (%li,%li) ---\n", d, n);

	}
	else if (eleccion_menu == 2)
	{	// ENCRIPTAR DESDE ARCHIVO
		long int e, n;

		FILE * archivo_de_texto;

		archivo_de_texto = fopen("mensaje_entrada.txt", "r");

		char mensaje_entrada[1000]; // Contiene el mensaje del archivo
		long int mensajeEncriptado[1000]; // Contiene el mensaje encriptado

		//Limpiamos los 1000 elementos que tiene el mensaje
		//antes de llenarlo con los caracteres
		for (int i = 0; i < 1000; ++i)
		{
			mensaje_entrada[i] = 0;
			mensajeEncriptado[i] = 0;
		}

		for (int i = 0; i < 1000; ++i)
		{
			fscanf(archivo_de_texto, "%c", &mensaje_entrada[i]);
			if (mensaje_entrada[i] == 0)
			{
				break;
			}
		}

		fclose(archivo_de_texto);

		printf("Ingrese la clave bajo la cual queres encriptar el mensaje\n");
		printf("Clave e (publica): ");
		scanf("%li", &e);
		printf("Clave n: ");
		scanf("%li", &n);

		encriptar(mensaje_entrada, mensajeEncriptado, e, n); // Salida en hex a cryptofile.txt
		printf("El mensaje encriptado a quedado en el archivo \"cryptofile.txt\" \n");
	}
	else if(eleccion_menu == 3)
	{
		long int d, n;

		FILE * archivo_de_encriptado;

		archivo_de_encriptado = fopen ("cryptofile.txt","r");

		long int crypto_hex[1000]; // Contiene los valores recibidos del archivo cryptofile.txt
		char mensaje_salida[1000]; // Contiene el mensaje que saldra

		for (int i = 0; i < 1000; ++i)
		{
			crypto_hex[i] = 0;
			mensaje_salida[i] = 0;
		}

		for (int i = 0; i < 1000; ++i)
		{
			fscanf (archivo_de_encriptado, "%05X ", &crypto_hex[i]);
			if (crypto_hex[i] == 0)
			{
				break;
			}
		}

		fclose(archivo_de_encriptado);

		printf("Ingrese su clave privada para desencriptar el mensaje\n");
		printf("Clave d (privada): ");
		scanf("%li", &d);
		printf("Clave n: ");
		scanf("%li", &n);

		desencriptar(crypto_hex, mensaje_salida, d, n);

		printf("El mensaje encriptado a quedado en el archivo \"mensaje_salida.txt\" \n");

		FILE * salidarchivo;
		salidarchivo = fopen("mensaje_salida.txt", "w");

		for (int i = 0; i < strlen(mensaje_salida); ++i)
		{
			fprintf(salidarchivo, "%c", mensaje_salida[i]);
		}

		fclose(salidarchivo);
	}

	return 0;
}

long int maximo_comun_divisor(long int a, long int b) {
	while(a!=b){
		while (a > b)
		{
			a -= b;
		}
		while (b > a)
		{
			b -= a;
		}
	}
	return a;
}

long int modInverso(long int a,long int m) {
    a = a%m;
    for (int x=1; x<m; x++){
       if ((a*x) % m == 1) {
          return x;
       }
    }
}

void encriptar(char mensajePlano[], long int mensajeEncriptado[], long int e, long int n) {
	FILE * cryptofile;
	cryptofile = fopen("cryptofile.txt", "w");

	for (int i = 0; i < strlen(mensajePlano); ++i)
	{
		int asciiCode = mensajePlano[i];

		mensajeEncriptado[i] = potencia_modular(asciiCode, e, n);

		fprintf(cryptofile, "%05X ", mensajeEncriptado[i]);
		// FORMATEO DEL ARCHIVO DE salida
		if (i > 0 && i <= 7 && i%7 == 0)
		{
			fprintf(cryptofile, "\n", "");
		} else if (i > 8 && i%8 == 7)  {
			fprintf(cryptofile, "\n", "");
		}

	}

	fclose(cryptofile);
}

void desencriptar(long int mensajeEncriptado[], char salida[], long int d, long int n) {
	for (int i = 0; i <= calcular_largo(mensajeEncriptado); ++i)
	{
		long int numero = mensajeEncriptado[i];
		char caracter = potencia_modular(numero, d, n);
		salida[i] = caracter;
	}
}

long int potencia_modular(int base, long int exponent, long int modulus) {
    long int c = 1;
    for (int i = 1; i <= exponent; i++) {
        c = (c * base)%modulus;
    }
    return c;
}

int calcular_largo(long int mensaje[]) {
	int i = 0;

	while(mensaje[i] != 0) {
		i++;
	}

	return i;
}
