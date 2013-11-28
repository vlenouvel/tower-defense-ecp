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



App::App() {
	fpsReels = 0;
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
	ConfigManager *configManager = ConfigManager::getInstance();
	long double imagesParSeconde = configManager->fps;
	sf::Int32 tempsUneImage = 1000.f/imagesParSeconde;
	tempsLegal = sf::milliseconds(tempsUneImage);

	// Charge la musique de fond
	sf::Music music;
	music.openFromFile("resources/sons/musicTest.ogg");
	music.play();

	// lance l'horloge
	horloge.restart();

	
	// boucle de jeu
	while (window.isOpen()) {
		horloge.restart();

		// la boucle en soi
		boucle();
		//fin de la boucle de jeu

		if (horloge.getElapsedTime() < tempsLegal){
			sf::sleep(tempsLegal - horloge.getElapsedTime());
		}
		fpsReels = (int)(1000.f/horloge.getElapsedTime().asMilliseconds());
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
	std::ostringstream ss;
	ss << fpsReels;
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

