#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
 FILE* f = fopen("PERSONAS.DAT","w+b");
 int dni;
 char nom[20];
 double altura;
 // el usuario ingresa los datos de una persona
 cout << "Ingrese dni, nombre, altura: ";
 cin >> dni;
 cin >> nom;
 cin >> altura;
 while( dni>0 )
 {
	// armo una estructura para grabar en el archivo
	struct Persona
	{
		int dni;
		char nombre[20];
		double altura;
	};
	Persona p;
	p.dni = dni;
	strcpy(p.nombre,nom);
	p.altura = altura;
	fwrite(&p,sizeof(Persona),1,f); // grabo la estructura en el archivo
	cout << "Ingrese dni, nombre, altura: ";
	cin >> dni;
 	cin >> nom;
	cin >> altura;
 }
 fclose(f);
 return 0;
}