#pragma once

#include <conio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Node.h"

using namespace std;

Node* arbol = NULL;

class Correr{
	private:

		sf::RenderWindow* windows1;

		sf::RenderWindow* windows2;

		sf::Texture txt_sprite[4];
		sf::Sprite spr_sprite[4];

		sf::Texture txt_fondo;
		sf::Sprite spr_fondo;

		sf::Texture txt_mira;
		sf::Sprite spr_mira;

		sf::Texture txt_titulo;
		sf::Sprite spr_titulo;

		sf::RectangleShape * rectangulo;
		sf::RectangleShape * rectangulo_s;

		sf::RectangleShape* rectangulo_no;
		sf::RectangleShape* rectangulo_si;

		sf::Font * fuente1;
		sf::Text * txt_menu;
		sf::Text* txt_menu_s;
		
		bool gameover = false;

		int opz, scl, fps, contador = 0;
		string dato;
		Node s;

	public:

		Correr(sf::Vector2f dimenciones, string titulo) {
			gameover = false;

			fps = 60;

			windows1 = new sf::RenderWindow(sf::VideoMode(dimenciones.x, dimenciones.y), titulo);
			
			windows1->setFramerateLimit(fps);

			crear_figuras();
			textos();
			cargar_graficos();
			gameloop();
		}

		void gameloop() {
			while (!gameover) {
				windows1->clear();

				windows1->draw(spr_fondo);
				windows1->draw(spr_titulo);
				windows1->draw(*rectangulo);
				windows1->draw(*rectangulo_s);
				windows1->draw(*txt_menu);
				windows1->draw(*txt_menu_s);
				
				for (int c = 0; c < 4; c++) {
					windows1->draw(spr_sprite[c]);
				}

				botones();
		
				windows1->display();
			}
		}

		void botones() {
			sf::Event Event;
			while (windows1->pollEvent(Event))
			{
				switch (Event.type)
				{
				case sf::Event::Closed:
					windows1->close();
					break;
				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(*windows1);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (rectangulo->getGlobalBounds().contains(mousePosF))
					{
						rectangulo->setFillColor(sf::Color::Yellow);
					}
					else
					{
						rectangulo->setFillColor(sf::Color::Blue);
					}
					if (rectangulo_s->getGlobalBounds().contains(mousePosF))
					{
						rectangulo_s->setFillColor(sf::Color::Yellow);
					}
					else
					{
						rectangulo_s->setFillColor(sf::Color::Blue);
					}
				}
				break;
				case sf::Event::MouseButtonPressed:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(*windows1);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (rectangulo_s->getGlobalBounds().contains(mousePosF))
					{
						windows1->clear();
						windows1->close();
					}
					if (rectangulo->getGlobalBounds().contains(mousePosF))
					{
						windows1->close();
						nueva_window();
					}
				}
				break;
				}
			}
		}

		void crear_figuras() {
			rectangulo = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo->setFillColor(sf::Color::White);
			rectangulo->setPosition(645, 225);

			rectangulo_s = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo_s->setFillColor(sf::Color::White);
			rectangulo_s->setPosition(645, 400);
		}

		void textos() {
			fuente1 = new sf::Font();
			fuente1->loadFromFile("arial.ttf");

			txt_menu = new sf::Text();
			txt_menu->setFont(*fuente1);
			txt_menu->setString("INICIAR");
			txt_menu->setPosition(700, 250);
			txt_menu->setCharacterSize(24);
			txt_menu->setFillColor(sf::Color::Red);
			txt_menu->setStyle(sf::Text::Bold | sf::Text::Underlined);

			txt_menu_s = new sf::Text();
			txt_menu_s->setFont(*fuente1);
			txt_menu_s->setString("SALIR");
			txt_menu_s->setPosition(700, 425);
			txt_menu_s->setCharacterSize(24);
			txt_menu_s->setFillColor(sf::Color::Red);
			txt_menu_s->setStyle(sf::Text::Bold | sf::Text::Underlined);
		}


		void cargar_graficos() {
			string rutas;

			for (int c = 0; c < 4; c++) {
				rutas = "adame" + to_string(c + 1) + ".png";
				txt_sprite[c].loadFromFile(rutas);
				spr_sprite[c].setTexture(txt_sprite[c]);
				spr_sprite[c].setPosition(0, 250);
			}
			txt_fondo.loadFromFile("televisa.jpg");
			spr_fondo.setTexture(txt_fondo);
			txt_titulo.loadFromFile("adameneitor.png");
			spr_titulo.setTexture(txt_titulo);
			spr_titulo.setPosition(150, 10);
			spr_fondo.setScale((float)windows1->getSize().x / txt_fondo.getSize().x, (float)windows1->getSize().y / txt_fondo.getSize().y);
		}

		void nueva_window() {
			gameover = false;
			fps = 60;
			windows2 = new sf::RenderWindow(sf::VideoMode(1000, 600), "ADAMENEITOR_JUEGO");
			windows2->setFramerateLimit(fps);

			cargar_graficos();

			crear_figuras_n();

			gameloop_n();
		}

		void pregusntas() {
			Node n;


		}

		void gameloop_n() {
			while (!gameover) {
				windows2->clear();

				windows2->draw(spr_fondo);
				windows2->draw(*rectangulo_si);
				windows2->draw(*rectangulo_no);

				botones_n();
			
				windows2->display();
			}
		}

		void crear_figuras_n() {
			rectangulo_no = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo_no->setFillColor(sf::Color::White);
			rectangulo_no->setPosition(645, 225);

			rectangulo_si = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo_si->setFillColor(sf::Color::White);
			rectangulo_si->setPosition(645, 400);
		}

		void Cargar_graficosN() {
			string rutas;

			for (int c = 0; c < 4; c++) {
				rutas = "adame" + to_string(c + 1) + ".png";
				txt_sprite[c].loadFromFile(rutas);
				spr_sprite[c].setTexture(txt_sprite[c]);
				spr_sprite[c].setPosition(0, 250);
			}
			txt_fondo.loadFromFile("televisa.jpg");
			spr_fondo.setTexture(txt_fondo);
			spr_fondo.setScale((float)windows2->getSize().x / txt_fondo.getSize().x, (float)windows2->getSize().y / txt_fondo.getSize().y);
		}

		void botones_n() {
			sf::Event Event;
			while (windows2->pollEvent(Event))
			{
				switch (Event.type)
				{
				case sf::Event::Closed:
					windows2->close();
					break;
				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(*windows2);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (rectangulo_si->getGlobalBounds().contains(mousePosF))
					{
						rectangulo_si->setFillColor(sf::Color::Yellow);
					}
					else
					{
						rectangulo_si->setFillColor(sf::Color::Blue);
					}
					if (rectangulo_no->getGlobalBounds().contains(mousePosF))
					{
						rectangulo_no->setFillColor(sf::Color::Yellow);
					}
					else
					{
						rectangulo_no->setFillColor(sf::Color::Blue);
					}
				}
				break;
				case sf::Event::MouseButtonPressed:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(*windows2);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (rectangulo_si->getGlobalBounds().contains(mousePosF))
					{
						windows2->clear();
						windows2->close();
					}
					if (rectangulo_no->getGlobalBounds().contains(mousePosF))
					{
						windows2->close();
						nueva_window();
					}
				}
				break;
				}
			}
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
					s.jugarNode(arbol);
					system("pause");
					break;
				}
				system("cls");
			} while (opz != 0);
		}
};
