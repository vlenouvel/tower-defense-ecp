/*
 * Ressources.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Ressources.h"
#include <string>

Ressources::Ressources() {
	textureRessources.loadFromFile("resources/textures/textureResources.jpg");
	spriteRessources.setTexture(textureRessources);
	spriteRessources.setScale(1,0.4);
	spriteRessources.setPosition(700,0);
	ressources = 0;
	font.loadFromFile("resources/polices/Capture it.ttf");
	texteRessources.setFont(font);
	texteRessources.setCharacterSize(48);
	texteRessources.setColor(sf::Color::White);
	texteRessources.setStyle(sf::Text::Bold);
	texteRessources.setPosition(720,0);
	texteRessources.setFont(font);

}

Ressources::~Ressources() {
	// TODO Auto-generated destructor stub
}

void Ressources::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spriteRessources);
	//texteRessources.setString(to_string(ressources));
	pWindow.draw(texteRessources);
}

