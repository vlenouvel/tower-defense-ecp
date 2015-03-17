Pour l'utiliser dans une classe, on met en tête du fichier :

#include "ResourceManager.h"

ResourceManager`*` manager = ResourceManager::getInstance();


Pour ajouter un objet (ici une tour), on ajoute son pointeur:

Tour `*`pTour = new Tour();

manager->add((Tour`*`) pTour);


Pour récuperer le vecteur de pointeur (ici des tours):

vector<Tour`*`> tourConteneur = manager->getTour();



En revanche, pour Menu et Carte, getMenu() et getCarte() ne retourne que le pointeur du Menu et de la Carte (vu qu'il y en a qu'un seul).