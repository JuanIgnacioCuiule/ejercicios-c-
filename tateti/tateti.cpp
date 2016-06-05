#include <iostream>
#include "funciones.cpp"
using namespace std;


int main()
{
	int tablero[9];
	char jugador1[40];
	char jugador2[40];
	int cord;
	bool en_juego = true;

	for (int i = 0; i < 9; ++i)
	{
		tablero[i] = 0;
	}

	cout << "Usted es el juagador1, ingrese su nombre por favor: ";
	cin >> jugador1;

	cout << "Usted es el juagador2, ingrese su nombre por favor: ";
	cin >> jugador2;

	while(en_juego) {
		
		cout << jugador1 << " es tu turno... Indica tu movimiento: ";
		cin >> cord;
		poner_ficha(tablero, jugador1, cord, jugador1, jugador2);
		mostrar_tablero(tablero);
		comprobar(tablero, en_juego, jugador1, jugador2);
		if (!en_juego)
		{
			break;
		}

		cout << jugador2 << " es tu turno... Indica tu movimiento: ";
		cin >> cord;
		poner_ficha(tablero, jugador2, cord, jugador1, jugador2);
		mostrar_tablero(tablero);
		comprobar(tablero, en_juego, jugador1, jugador2);

	}

	return 0;
}

