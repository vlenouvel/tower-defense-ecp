#include <iostream>
#include <exception>
#include "App.h"
#include <SFML/Audio.hpp>

using namespace std;


int main() {

	// on n'aura qu'une application => creation statique et non dynamique
	App app;
	app.jouer();

	return 0;
}
