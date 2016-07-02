#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long long int Mcd(long long int a, long long int b);
long long int modInverse(long long int a, long long int m);

int main()
{

	srand(time(NULL));
	
	int primos[168] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
	43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
	113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
	193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
	271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353,
	359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
	443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
	541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
	619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
	719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
	821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 
	911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

	for (int i = 0; i < 5; ++i)
	{
		int asciiVal = rand()%95 + 32;
		char asciiChar = asciiVal;
		printf("%d\t%c\n", asciiVal, asciiChar);
	}


	// p y q dos numeros primos...
	int p = primos[rand()%168];
	int q = primos[rand()%168];

	// n y euler(n)...
	long long int n = p*q;
	long long int phi_n = (p-1)*(q-1);
	
	// e tal que 1 < e < euler(n) y e coprimo con n y euler(n)
	long long int e = rand()%phi_n;
	while(Mcd(e, n) != 1 || Mcd(e, phi_n) != 1)
	{
		e = rand()%phi_n;
	}

	// d tal que (d*e)%phi_n = 1
	// Usamos la funcion modIverse para generar la d...
	long long int d = modInverse(e, phi_n) + phi_n * (rand()%5 + 1);

	printf("el num p     es: %li\n", p);
	printf("el num q     es: %li\n", q);
	printf("el num n     es: %li\n", n);
	printf("el num phi_n es: %li\n", phi_n);
	printf("el num e     es: %li\n", e);
	printf("el num d     es: %li\n", d);

	char mensajePlano[100];
	printf("Ingrese el mensaje a encriptar (Max 100 caracteres): ");
	fgets(mensajePlano, 100, stdin);

	for (int i = 0; i < strlen(mensajePlano); ++i)
	{
		printf("%c", mensajePlano[i]);
	}
	printf("\n");

	return 0;
}	

long long int Mcd(long long int a, long long int b) {
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

long long int modInverse(long long int a,long long int m) {
    a = a%m;
    for (int x=1; x<m; x++){
       if ((a*x) % m == 1) {
          return x;
       }
    }
}