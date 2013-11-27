/*
 * EtatMort.cpp
 *
 */

#include "EtatMort.h"

EtatMort::EtatMort(App* tApp) : Etat(tApp)  {
	pApp = tApp;
	ResourceManager* manager = ResourceManager::getInstance();

	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();

	font = pResourcesLoader->policeTableauDeBord;
	text1.setFont(font);
	text1.setString("Vous avez perdu !");
	text1.setCharacterSize(48);
	text1.setColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(150, 100);

	int score = manager->getRessources()->getScore();
	text2.setFont(font);
	ostringstream ss;
	ss << score;
	text2.setString("Votre score est de : " + ss.str());
	text2.setCharacterSize(24);
	text2.setColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(180, 250);


	text4.setFont(font);
	text4.setString("Cliquez pour revenir au menu");
	text4.setCharacterSize(24);
	text4.setColor(sf::Color::White);
	text4.setStyle(sf::Text::Bold);
	text4.setPosition(150,400);

	ofstream fichierScoreOut;
	fichierScoreOut.open("scores.txt",ios_base::app);
	fichierScoreOut << score << "\n";
	fichierScoreOut.close();

	ifstream fichierScoreIn("scores.txt");
	int max = 0;
	int temp;
	while(fichierScoreIn >> temp)
	{
		if(temp > max)
			max = temp;
	}
	fichierScoreIn.close();
	text3.setFont(font);
	text3.setCharacterSize(24);
	text3.setColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(180, 325);
	if (score > max)
	{
		text3.setString("Vous avez battu votre meilleur score !");
	} else {
		ostringstream ss2;
		ss2 << max;
		text3.setString("Votre meilleur score est de: " + ss2.str());
	}
}

void EtatMort::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			clearAllElements();

			Etat *pNouvelEtat = new EtatMenu(pApp);
			pApp->changerEtat(pNouvelEtat);
		}
	}
}

void EtatMort::dessiner(sf::RenderWindow &pWindow)
{
	pWindow.draw(text1);
	pWindow.draw(text2);
	pWindow.draw(text3);
	pWindow.draw(text4);
}
EtatMort::~EtatMort() {
	// TODO Auto-generated destructor stub
}

void EtatMort::clearAllElements()
{
	ResourceManager *pResourcesManager = ResourceManager::getInstance();
	delete pResourcesManager->getCarte();
	delete pResourcesManager->getRessources();
    delete pResourcesManager->getVague();
    delete pResourcesManager->getGenerateurVague();

    vector<Batiment*> batimentConteneur = pResourcesManager->getBatiment();
    for(unsigned int i = 0; i < batimentConteneur.size() ; i++)
    {
    	delete batimentConteneur[i];
    }

    vector<Personnage*> personnageConteneur = pResourcesManager->getPersonnage();
    for(unsigned int i = 0; i < personnageConteneur.size() ; i++)
    {
    	delete personnageConteneur[i];
    }

    vector<Projectile*> projectileConteneur = pResourcesManager->getProjectile();
    for(unsigned int i = 0; i < projectileConteneur.size() ; i++)
    {
    	delete projectileConteneur[i];
    }

    pResourcesManager->clearResourcesManager();
}
