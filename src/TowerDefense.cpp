#include <iostream>
#include <exception>
#include "App.h"

using namespace std;

int main() {

	// on n'aura qu'une application => creation statique et non dynamique
	App app;

	try {

		app.init();

	} catch (const exception &e) {
		std::cerr << "Il y a eu une erreur: " << endl << e.what();
	}

	//delete app;
	//app = NULL;

	return 0;
}
