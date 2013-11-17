/*
 * Ressources.cpp
 *
 *  Classe de gestion de l'argent du joueur
 *
 */

#include "Ressources.h"
#include <string>
#include <sstream>
#include "../ResourceManager.h"

Ressources::Ressources(Etat* tEtat) : pEtat(tEtat) {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureRessources = pResourcesLoader->textureRessources;
	spriteRessources.setTexture(textureRessources);
	spriteRessources.setScale(1,0.4);
	spriteRessources.setPosition(680,0);
	ressources = 0;
	font = pResourcesLoader->police;
	texteRessources.setFont(font);
	texteRessources.setCharacterSize(16);
	texteRessources.setColor(sf::Color::White);
	texteRessources.setStyle(sf::Text::Bold);
	texteRessources.setPosition(680,0);
	texteRessources.setFont(font);

	// TODO Changer vies et argent de depart
	vie = 20;
	argent = 100;
	score = 0;
}

Ressources::~Ressources() {
	// TODO Auto-generated destructor stub
}

void Ressources::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();

	Ressources* ressources = manager->getRessources();
	ostringstream ss;
	//std::string scoreTexte = "Score:" + to_string((long double)ressources->getScore()) + "\n" + "Argent:" + to_string((long double)ressources->getArgent())+ "\n" + "Vie:" + to_string((long double)ressources->getVie());
	//ss <<  "Score:" << (long double)ressources->getScore() << "\n" + "Argent:" << (long double)ressources->getArgent() << "\n" << "Vie:" << (long double)ressources->getVie();
	ss << "Score:";
	ss << ressources->getScore();
	ss << "\nArgent:";
	ss << ressources->getArgent();
	ss << "\nVie:";
	ss << ressources->getVie();

	texteRessources.setString(ss.str());
	pWindow.draw(spriteRessources);
	//texteRessources.setString(to_string(ressources));
	pWindow.draw(texteRessources);
}

int Ressources::getArgent() {
	return argent;
}

void Ressources::perdreArgent(int montantPerte) {
	argent = argent - montantPerte;
}

void Ressources::gagnerArgent(int montantGain) {
	argent = argent + montantGain;
}

int Ressources::getVie() {
	return vie;
}

void Ressources::perdreVie() {
	vie = vie - 1;
}

int Ressources::getScore() {
	return score;
}

void Ressources::augmenterScore(int nbPoint) {
	score = score + nbPoint;
}
