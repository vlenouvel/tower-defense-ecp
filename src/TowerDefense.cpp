/*
 * TowerDefense.cpp
 *
 * Point d'entrée du jeu
 *
 */
#include "App.h"
#include <gtest/gtest.h>
#include "testsunitaires.h"


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	//int i = RUN_ALL_TESTS();
	// on n'aura qu'une application => creation statique et non dynamique
	App app;
	app.jouer();

	return 0;
}
