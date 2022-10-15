#pragma once

#include <conio.h>
#include <iostream>

using namespace std;

class Node {

	private:
		Node* arbol = NULL;
		string dato;
		Node* der;
		Node* izq;

	public:

		void mostrar_arbol(Node* arbol, int cont) {
			if (arbol == NULL) {
				return;
			}
			else {
				mostrar_arbol(arbol->der, cont + 1);
				for (int i = 0; i < cont; i++) {
					cout << "   ";
				}
				cout << arbol->dato << endl;
				mostrar_arbol(arbol->izq, cont + 1);
			}
		}

		Node* crearNodo(string n) {
			Node* nuevo_nodo = new Node();
			nuevo_nodo->dato = n;
			nuevo_nodo->der = NULL;
			nuevo_nodo->izq = NULL;

			return nuevo_nodo;
		}

		void insertar_Nodo(Node*& arbol, string n) {
			string personaje;
			int ad;

			if (arbol == NULL) {
				Node* nuevo_nodo = crearNodo(n);
				arbol = nuevo_nodo;
			}
			else {
				string valor_raiz = arbol->dato;
				cout << "Tu personaje:" << valor_raiz << endl;
				cin >> ad;
				if (ad == 1) {
					insertar_Nodo(arbol->izq, n);
				}
				else {
					insertar_Nodo(arbol->der, n);
				}
			}
		}
		
};
