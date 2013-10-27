//============================================================================
// Name        : TowerDefense.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Main file of the game
//============================================================================

#include <iostream>
using namespace std;

// Test
#include <string>

#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

string getDir()
{
	char cCurrentPath[FILENAME_MAX];

	 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	     {
		 string b = string(errno, sizeof(errno));
		 return b;
	     }

	//cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	string a = string(cCurrentPath);
	return a;

}

//Fin de test

int main() {
	cout << getDir();
	cout << " Tower Defense" << endl << "top Carrier" << endl; // prints
    cout << "Top Lenouvel" << endl;
	cout << "Top Delevacque" << endl;
	return 0;
}
