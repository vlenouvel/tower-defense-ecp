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
#include "../ConfigManager.h"
#include <iostream>

Ressources::Ressources() {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureRessources = pResourcesLoader->textureRessources;
	spriteRessources.setTexture(textureRessources);
	spriteRessources.setScale(1,0.4);
	spriteRessources.setPosition(715,0);
	font = pResourcesLoader->policeTableauDeBord;
	texteRessources.setFont(font);
	texteRessources.setCharacterSize(14);
	texteRessources.setColor(sf::Color::White);
	texteRessources.setPosition(715,0);

	ConfigManager *pConfigManager = ConfigManager::getInstance();
	vie = pConfigManager->vie;
	argent = pConfigManager->argent;
	score = 0;
	nombreVagues = 0;
}

Ressources::~Ressources() {
	// TODO Auto-generated destructor stub
}

void Ressources::dessiner(sf::RenderWindow &pWindow){
	ostringstream ss;
	//std::string scoreTexte = "Score:" + to_string((long double)ressources->getScore()) + "\n" + "Argent:" + to_string((long double)ressources->getArgent())+ "\n" + "Vie:" + to_string((long double)ressources->getVie());
	//ss <<  "Score:" << (long double)ressources->getScore() << "\n" + "Argent:" << (long double)ressources->getArgent() << "\n" << "Vie:" << (long double)ressources->getVie();
	ss << "Score:";
	ss << score;
	ss << "\n";
	ss << argent;
	ss << " $\nVie:";
	ss << vie;
	ss << "\nVague";
	//if(nombreVagues>0)
	//	ss << "s";
	ss << ":";
	ss << nombreVagues;
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

void Ressources::setVagues(int nbVagues)
{
	nombreVagues = nbVagues;
}
