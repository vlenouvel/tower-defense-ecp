/*
 * EtatScores.cpp
 *
 *  Created on: 19 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatScores.h"

EtatScores::EtatScores(App *tApp) : Etat(tApp){
	pApp = tApp;
	lireMeilleursScores();
	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	font = pResourcesLoader->policeTableauDeBord;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(180, 150);
	std::ostringstream ss;
	ss << "Vos meilleurs scores :";
	for(int i = 0; i < 3 ; i++)
	{
		ss << "\n";
		ss << meilleursScores[i];
	}
	std::cout << ss.str() << std::endl;
	text.setString(ss.str());
}

void EtatScores::handleEvent(sf::Event event)
{
	if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
	{
		Etat *pNouvelEtat = new EtatMenu(pApp);
		pApp->changerEtat(pNouvelEtat);
	}
}

void EtatScores::dessiner(sf::RenderWindow &pWindow)
{
	pWindow.draw(text);
}

void EtatScores::agir()
{

}

void EtatScores::lireMeilleursScores()
{
	std::ifstream fichierScoreIn("scores.txt");
	int temp;
	std::vector<int> tousLesScores;
	while (fichierScoreIn >> temp)
	{
		tousLesScores.push_back(temp);
	}
	// sort in descending order
	std::sort(tousLesScores.begin(), tousLesScores.end(), std::greater<int>());
	for(int i = 0; i < 3; i++)
	{
		meilleursScores[i] = tousLesScores[i];
	}
}

EtatScores::~EtatScores() {
	// TODO Auto-generated destructor stub
}

