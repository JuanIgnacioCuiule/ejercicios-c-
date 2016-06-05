#include <iostream>
using namespace std;

void mostrar_tablero(int tablero[]);
void comprobar(int tablero[], bool &en_juego, char jugador1[], char jugador2[]);
void poner_ficha(int tablero[], char jugador[40], int cord, char jugador1[], char jugador2[]);

void mostrar_tablero(int tablero[]) {

	cout << "En estos momentos el tablero esta asi: " << endl;
	cout << "      1   2   3" << endl << endl;
	cout << "1   | " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << " |" << endl;
	cout << "    |---|---|---|" << endl;
	cout << "2   | " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << " |" << endl;
	cout << "    |---|---|---|" << endl;
	cout << "3   | " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << " |" << endl << endl;

}

void comprobar(int tablero[], bool &en_juego, char jugador1[], char jugador2[]) {
	cout << "Comprobando..." << endl;
	if (tablero[0] != 0 &&tablero[0] == tablero[1] && tablero[0] == tablero[2] && tablero[1] == tablero[2])
	{
		en_juego = false;
		if (tablero[0] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[0] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[0] != 0 &&tablero[0] == tablero[4] && tablero[0] == tablero[8] && tablero[4] == tablero[8])
	{
		en_juego = false;
		if (tablero[0] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[0] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[0] != 0 &&tablero[0] == tablero[3] && tablero[0] == tablero[6] && tablero[3] == tablero[6])
	{
		en_juego = false;
		if (tablero[0] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[0] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[1] != 0 &&tablero[1] == tablero[4] && tablero[1] == tablero[7] && tablero[4] == tablero[7])
	{
		en_juego = false;
		if (tablero[1] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[1] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[3] != 0 && tablero[3] == tablero[4] && tablero[3] == tablero[5] && tablero[4] == tablero[5])
	{
		en_juego = false;
		if (tablero[3] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[3] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[6] != 0 &&tablero[6] == tablero[4] && tablero[6] == tablero[2] && tablero[4] == tablero[2])
	{
		en_juego = false;
		if (tablero[6] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[6] == 2)
		{
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[6] != 0 &&tablero[6] == tablero[7] && tablero[6] == tablero[8] && tablero[7] == tablero[8])
	{
		en_juego = false;
		if (tablero[6] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[6] == 2){
			cout << jugador2 << " ha ganado." << endl;
		}
	}
	else if (tablero[2] != 0 &&tablero[2] == tablero[5] && tablero[2] == tablero[8] && tablero[5] == tablero[8])
	{
		en_juego = false;
		if (tablero[2] == 1)
		{
			cout << jugador1 << " ha ganado." << endl;
		}
		else if (tablero[2] == 2){
			cout << jugador2 << " ha ganado." << endl;
		}
	}
}

void poner_ficha(int tablero[], char jugador[40],int cord, char jugador1[], char jugador2[]) {
	int id;
	if (jugador == jugador1)
	{
		id = 1;
	} else if (jugador == jugador2)
	{
		id = 2;
	}
	switch(cord) {
		case 11:
			tablero[0] = id;
			break;
		case 12:
			tablero[1] = id;
			break;
		case 13:
			tablero[2] = id;
			break;
		case 21:
			tablero[3] = id;
			break;
		case 22:
			tablero[4] = id;
			break;
		case 23:
			tablero[5] = id;
			break;
		case 31:
			tablero[6] = id;
			break;
		case 32:
			tablero[7] = id;
			break;
		case 33:
			tablero[8] = id;
			break;

	}
}