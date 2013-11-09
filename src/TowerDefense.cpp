#include <iostream>
#include "App.h"
using namespace std;

int main() {

	// on n'aura qu'une application => creation statique et non dynamique
	App app;
	app.init();
}
