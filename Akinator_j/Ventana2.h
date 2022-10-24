
#pragma once

#include <conio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Node.h"
#include "Correr.h"

using namespace std;

Node* arbol = NULL;

class Ventana2 {
	private: 

		sf::RenderWindow* windows2;

		sf::RectangleShape* rectangulo_no;
		sf::RectangleShape* rectangulo_si;

		sf::Texture txt_fondo2;
		sf::Sprite spr_fondo2;

		sf::Text* txt_si;
		sf::Text* txt_no;
		sf::Text* txt_prg;

		sf::Font* fuente1;
		
		Node n;

		Node* izq;
		Node* der;
		


		bool gameover = false;
		int fps, add;
		string dato;

	public:

		Ventana2(sf::Vector2f dimenciones2, string titulo2) {
			gameover = false;
			fps = 60;
			windows2 = new sf::RenderWindow(sf::VideoMode(dimenciones2.x, dimenciones2.y), titulo2);
			windows2->setFramerateLimit(fps);

			Cargar_graficosN();

			textos_n();

			crear_figuras_n();

			gameloop_n();
		}

		void gameloop_n() {
			while (!gameover) {
				windows2->clear();

				windows2->draw(spr_fondo2);
				windows2->draw(*rectangulo_si);
				windows2->draw(*rectangulo_no);
				windows2->draw(*txt_si);
				windows2->draw(*txt_no);
				windows2->draw(*txt_prg);

				botones_n();

				windows2->display();
			}
		}

		void preguntas_n() {
			cout << "tu personaje:";
			cin >> dato;
			cout << endl << endl;
			n.insertar_Nodo(arbol, dato);
		}

		void crear_figuras_n() {
			rectangulo_no = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo_no->setFillColor(sf::Color::White);
			rectangulo_no->setPosition(545, 225);

			rectangulo_si = new sf::RectangleShape(sf::Vector2f(200.f, 80.f));
			rectangulo_si->setFillColor(sf::Color::White);
			rectangulo_si->setPosition(245, 225);
		}

		void textos_n() {
			fuente1 = new sf::Font();
			fuente1->loadFromFile("arial.ttf");

			txt_si = new sf::Text();
			txt_si->setFont(*fuente1);
			txt_si->setString("SI");
			txt_si->setPosition(320, 235);
			txt_si->setCharacterSize(44);
			txt_si->setFillColor(sf::Color::Red);
			txt_si->setStyle(sf::Text::Bold | sf::Text::Underlined);

			txt_no = new sf::Text();
			txt_no->setFont(*fuente1);
			txt_no->setString("NO");
			txt_no->setPosition(610, 235);
			txt_no->setCharacterSize(44);
			txt_no->setFillColor(sf::Color::Red);
			txt_no->setStyle(sf::Text::Bold | sf::Text::Underlined);

			txt_prg = new sf::Text();
			txt_prg->setFont(*fuente1);
			preguntas_n();
			txt_prg->setString("TU PERSONAJE "+ dato + "?");
			txt_prg->setPosition(200, 100);
			txt_prg->setCharacterSize(50);
			txt_prg->setFillColor(sf::Color::Red);
			txt_prg->setStyle(sf::Text::Bold);
		}

		void Cargar_graficosN() {
			string rutas;

			txt_fondo2.loadFromFile("televisa.jpg");
			spr_fondo2.setTexture(txt_fondo2);
			spr_fondo2.setScale((float)windows2->getSize().x / txt_fondo2.getSize().x, (float)windows2->getSize().y / txt_fondo2.getSize().y);
		}

		void si() {
			add == 1;
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
	
					}
					if (rectangulo_no->getGlobalBounds().contains(mousePosF))
					{

					}
				}
				break;
				}
			}
		}
};
