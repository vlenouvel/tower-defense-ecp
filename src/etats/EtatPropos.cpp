/*
 * EtatPropos.cpp
 *
 *  Etat qui affiche quelques informations sur le jeu
 */

#include "EtatPropos.h"

EtatPropos::EtatPropos(App *tApp) : Etat(tApp){
	pApp = tApp;

	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	font = pResourcesLoader->policeTableauDeBord;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(180, 150);
	std::ostringstream ss;
	ss << "Developpeurs:\n\nVincent Carrier\nFrancois De Leo\nArnaud Delevacque\nVincent Lenouvel";
	text.setString(ss.str());
}

void EtatPropos::handleEvent(sf::Event event)
{
	if((event.type == sf::Event::KeyPressed)||(event.type == sf::Event::MouseButtonPressed))
	{
		Etat *pNouvelEtat = new EtatMenu(pApp);
		pApp->changerEtat(pNouvelEtat);
	}
}

void EtatPropos::dessiner(sf::RenderWindow &pWindow)
{
	pWindow.draw(text);
}

void EtatPropos::agir()
{

}
EtatPropos::~EtatPropos() {
	// VIDE
}

