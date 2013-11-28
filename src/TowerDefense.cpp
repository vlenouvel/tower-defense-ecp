/*
 * TowerDefense.cpp
 *
 * Point d'entrée du jeu
 *
 */
#include "App.h"

int main() {
	// on n'aura qu'une application => creation statique et non dynamique
	App app;
	app.jouer();

	return 0;
}
