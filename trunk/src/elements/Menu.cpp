/*
 * Menu.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Menu.h"

Menu::Menu() {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteMenu.setTexture(pResourcesLoader->textureMenu);
	spriteMenu.setScale(0.63,0.83);
	font = pResourcesLoader->policeMenu;
	text1.setFont(font);
	text1.setString("Entrez dans l'arene");
	text1.setCharacterSize(48);
	text1.setColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(150,100);
	text2.setFont(font);
	text2.setString("Meilleurs scores");
	text2.setCharacterSize(48);
	text2.setColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(180,250);	
	text3.setFont(font);
	text3.setString("A propos");
	text3.setCharacterSize(48);
	text3.setColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(300,400);
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spriteMenu);
	pWindow.draw(text1);
	pWindow.draw(text2);
	pWindow.draw(text3);
};


