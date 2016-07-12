#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector <string> archivos;
	int indice_archivos = 0;
	char aux[30];
	printf("max_size %i\n", archivos.max_size());
	printf("Ingrese el nombre del primer archivo: ");
	scanf("%s", &aux);
	archivos.push_back(aux);

	while (archivos[indice_archivos] != "0") {
		indice_archivos++;
		printf("Ingrese el nombre del %d º archivo: ", indice_archivos+1);
		scanf("%s", &aux);
		archivos.push_back(aux);
	}

	string archivo;
	vector <string> pdf;
	vector <string> txt;
	vector <string> mp3;
	vector <string> jpg;

	char extension[4];
	int cont_pdf = 0;
	int cont_txt = 0;
	int cont_mp3 = 0;
	int cont_jpg = 0;

	for (int i = 0; i < archivos.size()-1; i++)
	{
		archivo =  archivos[i];

		int largo_nombre = archivo.size();

		extension[0] = archivo[largo_nombre-4];
		extension[1] = archivo[largo_nombre-3];
		extension[2] = archivo[largo_nombre-2];
		extension[3] = archivo[largo_nombre-1];

		if (strcmp(extension, ".pdf") == 0)
		{	
			pdf.push_back(archivo);
		} 
		else if (strcmp(extension, ".txt") == 0)
		{
			txt.push_back(archivo);
		}
		else if (strcmp(extension, ".mp3") == 0)
		{
			mp3.push_back(archivo);
		}
		else if (strcmp(extension, ".jpg") == 0) 
		{
			jpg.push_back(archivo);
		}
	}

	printf("%s\n", "--- PDF ---");
	for (int i = 0; i < pdf.size(); ++i)
	{
		for (int a = 0; a < pdf[i].size(); ++a)
		{
			printf("%c", pdf[i][a]);
		}
		printf("\n");
	}
	printf("\n");

	printf("%s\n", "--- TXT ---");
	for (int i = 0; i < txt.size(); ++i)
	{
		for (int a = 0; a < txt[i].size(); ++a)
		{
			printf("%c", txt[i][a]);
		}
		printf("\n");
	}
	printf("\n");

	printf("%s\n", "--- MP3 ---");
	for (int i = 0; i < mp3.size(); ++i)
	{
		for (int a = 0; a < mp3[i].size(); ++a)
		{
			printf("%c", mp3[i][a]);
		}
		printf("\n");
	}
	printf("\n");

	printf("%s\n", "--- JPG ---");
	for (int i = 0; i < jpg.size(); ++i)
	{
		for (int a = 0; a < jpg[i].size(); ++a)
		{
			printf("%c", jpg[i][a]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

