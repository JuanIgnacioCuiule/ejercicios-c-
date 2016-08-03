//#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<string> archivos;
	int indice_archivos = 0;
	char aux[30];
	cout << "max_size " <<  archivos.max_size() << endl;
	cout << "Ingrese el nombre del primer archivo: " << endl;
	cin >> aux;
	archivos.push_back(aux);

	while (archivos[indice_archivos] != "0") {
		indice_archivos++;
		cout << "Ingrese el nombre del" << indice_archivos+1 << " º archivo: ";
		cin >> aux;
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

	cout << "--- PDF ---" << endl;
	for (int i = 0; i < pdf.size(); ++i)
	{
		for (int a = 0; a < pdf[i].size(); ++a)
		{
			cout << pdf[i][a];
		}
		cout << endl;
	}
	cout << endl;

	cout << "--- TXT ---" << endl;
	for (int i = 0; i < txt.size(); ++i)
	{
		for (int a = 0; a < txt[i].size(); ++a)
		{
			cout << txt[i][a];
		}
		cout << endl;
	}
	cout << endl;

	cout << "--- MP3 ---" << endl;
	for (int i = 0; i < mp3.size(); ++i)
	{
		for (int a = 0; a < mp3[i].size(); ++a)
		{
			cout << mp3[i][a];
		}
		cout << endl;
	}
	cout << endl;

	cout << "--- JPG ---" << endl;
	for (int i = 0; i < jpg.size(); ++i)
	{
		for (int a = 0; a < jpg[i].size(); ++a)
		{
			cout << jpg[i][a];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
