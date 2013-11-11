#include <iostream>
#include <exception>
#include "App.h"
#include <SFML/Audio.hpp>
using namespace std;

int main() {

	// on n'aura qu'une application => creation statique et non dynamique
	App app;

	try {
		sf::Music music;
		music.openFromFile("resources/sons/musicTest.ogg");
		music.play();
		while (app.isRunning()) {
	   		app.boucle();
	    }
	} catch (const exception &e) {
		std::cerr << "Il y a eu une erreur: " << endl << e.what();
	}

	//delete app;
	//app = NULL;
	return 0;
}
