/*
 * Menu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Menu.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::dessiner(sf::RenderWindow &pWindow){
	sf::Font font;
	font.loadFromFile("resources/polices/Capture it.ttf");
	sf::Text text1;
	text1.setFont(font);
	text1.setString("Entrez dans l'arene");
	text1.setCharacterSize(48);
	text1.setColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(150,100);
	sf::Text text2;
	text2.setFont(font);
	text2.setString("Meilleurs scores");
	text2.setCharacterSize(48);
	text2.setColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(180,250);
	sf::Text text3;
	text3.setFont(font);
	text3.setString("Tuto");
	text3.setCharacterSize(48);
	text3.setColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(350,400);
	pWindow.clear();
	pWindow.draw(text1);
	pWindow.draw(text2);
	pWindow.draw(text3);
};


