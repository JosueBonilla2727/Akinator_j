#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct Node {
	int dato;
	Node *der;
	Node *izq;
};

Node *arbol = NULL;
void menu();
void insertar_Nodo(Node *&, int);
Node* crearNodo(int);
void mostrar_arbol(Node *, int);



int main() {
	
	menu();

	return 0;
};

void menu() {

	int dato, op, contador=0;

	do {
		cout << "MENU" << endl;
		cout << "1.- Ingresar nodo" << endl;
		cout << "2.- Mostrar arbol" << endl;
		cout << "0.- salir" << endl;
		cout << "Opcion: " << endl;
		cin >> op;

		switch (op) {
			case 1:
				cout << "Digite el nuemero:" << endl;
				cin >> dato;
				insertar_Nodo(arbol, dato);
				system("pause");
			break;

			case 2:
				mostrar_arbol(arbol, contador);
				system("pause");
			break;
		}
		system("cls");
	} while (op != 0);
}

void mostrar_arbol(Node *arbol,int cont) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrar_arbol(arbol->der, cont + 1);
		for(int i=0; i<cont; i++){
			cout <<"  ";
		}
		cout << arbol->dato << endl;
		mostrar_arbol(arbol->izq, cont + 1);
	}
}

Node* crearNodo(int n) {
	Node* nuevo_nodo = new Node();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

void insertar_Nodo(Node *&arbol, int n) {
	if (arbol == NULL) {
		Node *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else {
		int valor_raiz = arbol->dato;
		if (n < valor_raiz) {
			insertar_Nodo(arbol->izq, n);
		}
		else {
			insertar_Nodo(arbol->der, n);
		}
	}
}



