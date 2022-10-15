#pragma once

#include <conio.h>
#include <iostream>
#include "Node.h"

using namespace std;

Node* arbol = NULL;

class Correr{
	private:
		int opz, contador = 0;
		string dato;
		Node s;

	public:

		void correr() {
			menu();
		}

		void menu() {
			do {
				cout << "MENU" << endl;
				cout << "1.- Ingresar nodo" << endl;
				cout << "2.- Mostrar arbol" << endl;
				cout << "3.- Jugar" << endl;
				cout << "0.- salir" << endl;
				cout << "Opcion: " << endl;
				cin >> opz;

				switch (opz) {
				case 1:
					cout << "tu personaje:";
					cin >> dato;
					cout << endl << endl;
					s.insertar_Nodo(arbol, dato);
					system("pause");
					break;

				case 2:
					s.mostrar_arbol(arbol, contador);
					system("pause");
					break;
				case 3:
					system("pause");
					break;
				}
				system("cls");
			} while (opz != 0);
		}
};
