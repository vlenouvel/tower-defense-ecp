/*
 * ConfigManager.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ConfigManager.h"

using namespace std;

// Pointeur vers l'unique instance du ResourceManager
ConfigManager* configManagerPointeur = 0;
// instance = true si une instance existe deja
bool instanceConfig = false;

ConfigManager* ConfigManager::getInstance()
{
	if(!instanceConfig)
	{
		configManagerPointeur = new ConfigManager();
		instanceConfig = true;
	}
	return configManagerPointeur;
}

void ConfigManager::loadConfig()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("config.xml");
	tinyxml2::XMLElement* config = doc.FirstChildElement("config");

	fps = atoi(config->FirstChildElement("fps")->GetText());

	tinyxml2::XMLElement* batiments = config->FirstChildElement("batiments");

	tinyxml2::XMLElement* tourAttaqueBasique = batiments->FirstChildElement("tourAttaqueBasique");

	mapTourBasique["prix"] = atoi(tourAttaqueBasique->FirstChildElement("prix")->GetText());
	mapTourBasique["attaque"] = atoi(tourAttaqueBasique->FirstChildElement("attaque")->GetText());
	mapTourBasique["portee"] = atoi(tourAttaqueBasique->FirstChildElement("portee")->GetText());
	mapTourBasique["temps"] = atoi(tourAttaqueBasique->FirstChildElement("temps")->GetText());

	tinyxml2::XMLElement* tourFrost = batiments->FirstChildElement("tourFrost");

	mapTourDeGlace["prix"] = atoi(tourFrost->FirstChildElement("prix")->GetText());
	mapTourDeGlace["attaque"] = atoi(tourFrost->FirstChildElement("attaque")->GetText());
	mapTourDeGlace["portee"] = atoi(tourFrost->FirstChildElement("portee")->GetText());
	mapTourDeGlace["temps"] = atoi(tourFrost->FirstChildElement("temps")->GetText());

	tinyxml2::XMLElement* tourCanon = batiments->FirstChildElement("tourCanon");

	mapTourCanon["prix"] = atoi(tourCanon->FirstChildElement("prix")->GetText());
	mapTourCanon["attaque"] = atoi(tourCanon->FirstChildElement("attaque")->GetText());
	mapTourCanon["portee"] = atoi(tourCanon->FirstChildElement("portee")->GetText());
	mapTourCanon["temps"] = atoi(tourCanon->FirstChildElement("temps")->GetText());
	mapTourCanon["rayonExplosion"] = atoi(tourCanon->FirstChildElement("rayonExplosion")->GetText());

	tinyxml2::XMLElement* tourSupport = batiments->FirstChildElement("tourSupport");

	mapTourSupport["prix"] = atoi(tourSupport->FirstChildElement("prix")->GetText());


	tinyxml2::XMLElement* mur = batiments->FirstChildElement("mur");

	mapMur["prix"] = atoi(mur->FirstChildElement("prix")->GetText());

	tinyxml2::XMLElement* personnages = config->FirstChildElement("personnages");

	tinyxml2::XMLElement* persoNormal = personnages->FirstChildElement("normal");

	mapPersonnageNormal["vie"] = atoi(persoNormal->FirstChildElement("vie")->GetText());
	mapPersonnageNormal["vitesse"] = atoi(persoNormal->FirstChildElement("vitesse")->GetText());
	mapPersonnageNormal["armure"] = atoi(persoNormal->FirstChildElement("armure")->GetText());

	tinyxml2::XMLElement* persoRapide = personnages->FirstChildElement("rapide");

	mapPersonnageRapide["vie"] = atoi(persoRapide->FirstChildElement("vie")->GetText());
	mapPersonnageRapide["vitesse"] = atoi(persoRapide->FirstChildElement("vitesse")->GetText());
	mapPersonnageRapide["armure"] = atoi(persoRapide->FirstChildElement("armure")->GetText());

	tinyxml2::XMLElement* persoSolide = personnages->FirstChildElement("solide");

	mapPersonnageSolide["vie"] = atoi(persoSolide->FirstChildElement("vie")->GetText());
	mapPersonnageSolide["vitesse"] = atoi(persoSolide->FirstChildElement("vitesse")->GetText());
	mapPersonnageSolide["armure"] = atoi(persoSolide->FirstChildElement("armure")->GetText());

}

ConfigManager::ConfigManager() {
	loadConfig();
}

ConfigManager::~ConfigManager() {
	// TODO Auto-generated destructor stub
}

