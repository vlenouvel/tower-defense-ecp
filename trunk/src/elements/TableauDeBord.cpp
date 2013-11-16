/*
 * TableauDeBord.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "TableauDeBord.h"
#include <string>

TableauDeBord::TableauDeBord() {
	textureTableauDeBord.loadFromFile("resources/textures/textureResources.jpg");
	spriteTableauDeBord.setTexture(textureTableauDeBord);
	spriteTableauDeBord.setScale(1,3);
	spriteTableauDeBord.setPosition(700,100);
	font.loadFromFile("resources/polices/Capture it.ttf");
	texteTableauDeBord.setFont(font);
	texteTableauDeBord.setCharacterSize(48);
	texteTableauDeBord.setColor(sf::Color::White);
	texteTableauDeBord.setStyle(sf::Text::Bold);
	texteTableauDeBord.setPosition(720,0);
	texteTableauDeBord.setFont(font);

	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.jpg");
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(710,300);

	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.jpg");
	spriteTourAttaqueBasique.setTexture(textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition(760,300);

}

TableauDeBord::~TableauDeBord() {
	// TODO Auto-generated destructor stub
}

void TableauDeBord::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spriteTableauDeBord);
	pWindow.draw(texteTableauDeBord);
	pWindow.draw(spriteCanonLourd);
	pWindow.draw(spriteTourAttaqueBasique);
}