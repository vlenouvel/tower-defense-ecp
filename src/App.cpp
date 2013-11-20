/*
 * App.cpp
 *
 *  TowerDefense ECP
 *
 *  Classe principale du Jeu, qui comprend la boucle, les fonctions d'affichage, de gestion d'event
 *  et de mise à jours des entités de jeu.
 *  Elle gere egalement le changement d'etat du jeu.
 *       
 */

#include "App.h"

using namespace std;

ResourceManager* manager = ResourceManager::getInstance();


App::App() {
	test = 0;
	font.loadFromFile("resources/polices/Capture it.ttf");
	texteFPS.setFont(font);
	texteFPS.setCharacterSize(48);
	texteFPS.setColor(sf::Color::White);
	texteFPS.setStyle(sf::Text::Bold);
	texteFPS.setPosition(20,20);

	// Creation de la fenetre de jeu
	window.create(sf::VideoMode(800, 600), "Tower Defense", sf::Style::Close);

	// Creation de l'etat de l'ecran de chargement
	pEtatActuel = new EtatChargement(this);
}
App::~App() {

}


void App::jouer() {

	// Timer de la Boucle de jeu
	sf::Clock horloge;
	sf::Time framestartTime;
	sf::Time difference;
	sf::Time tempsLegal;
	sf::Time hibernation;

	long double imagesParSeconde = 20;
	float tempsUneImage = 1.f/imagesParSeconde;
	tempsLegal = sf::seconds(tempsUneImage);

	// Charge la musique de fond
	sf::Music music;
	music.openFromFile("resources/sons/musicTest.ogg");
	music.play();

	// lance l'horloge
	horloge.restart();

	
	// boucle de jeu
	while (window.isOpen()) {
		framestartTime = horloge.getElapsedTime();
		// la boucle en soi
		boucle();
		//fin de la boucle de jeu
		difference = horloge.getElapsedTime() - framestartTime;

		if (difference < tempsLegal){
			hibernation = tempsLegal - difference;
			sf::sleep(hibernation);
			test = imagesParSeconde;
		}
		else
			test = 1./difference.asSeconds();
	}
}

void App::boucle() {
	App::gererEvents();
	App::update();
	App::render();
}

void App::gererEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		// Ferme la fenetre de jeu
		if (event.type == sf::Event::Closed)
			window.close();
		else
		{
			// Sinon on delegue au gestionnaire d'event de l'Etat
			pEtatActuel->handleEvent(event);
		}

	}
}

void App::update() {
	pEtatActuel->agir();
}

void App::render() {
	sf::RenderWindow &rWindow = window;
	window.clear();

	pEtatActuel->dessiner(rWindow);

	// Affichage du nombre de FPS
	ostringstream ss;
	ss << test;
	texteFPS.setString(ss.str());
	window.draw(texteFPS);

	// Affichage de l'ensemble de la fenetre
	window.display();
}

// Gere le changement d'etat de jeu
void App::changerEtat(Etat *pNouvelEtat)
{
	delete pEtatActuel;
	pEtatActuel = pNouvelEtat;
}

