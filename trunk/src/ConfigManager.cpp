/*
 * ConfigManager.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ConfigManager.h"

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
	argent = atoi(config->FirstChildElement("argent")->GetText());
	vie = atoi(config->FirstChildElement("vie")->GetText());
	tauxRevente = atoi(config->FirstChildElement("tauxRevente")->GetText());

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
	mapPersonnageNormal["gain"] = atoi(persoNormal->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoRapide = personnages->FirstChildElement("rapide");

	mapPersonnageRapide["vie"] = atoi(persoRapide->FirstChildElement("vie")->GetText());
	mapPersonnageRapide["vitesse"] = atoi(persoRapide->FirstChildElement("vitesse")->GetText());
	mapPersonnageRapide["armure"] = atoi(persoRapide->FirstChildElement("armure")->GetText());
	mapPersonnageRapide["gain"] = atoi(persoRapide->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoSolide = personnages->FirstChildElement("solide");

	mapPersonnageSolide["vie"] = atoi(persoSolide->FirstChildElement("vie")->GetText());
	mapPersonnageSolide["vitesse"] = atoi(persoSolide->FirstChildElement("vitesse")->GetText());
	mapPersonnageSolide["armure"] = atoi(persoSolide->FirstChildElement("armure")->GetText());
	mapPersonnageSolide["gain"] = atoi(persoSolide->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoVolant = personnages->FirstChildElement("volant");

	mapPersonnageVolant["vie"] = atoi(persoVolant->FirstChildElement("vie")->GetText());
	mapPersonnageVolant["vitesse"] = atoi(persoVolant->FirstChildElement("vitesse")->GetText());
	mapPersonnageVolant["armure"] = atoi(persoVolant->FirstChildElement("armure")->GetText());
	mapPersonnageVolant["gain"] = atoi(persoVolant->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoGenerateur = personnages->FirstChildElement("generateur");

	mapPersonnageGenerateur["vie"] = atoi(persoGenerateur->FirstChildElement("vie")->GetText());
	mapPersonnageGenerateur["vitesse"] = atoi(persoGenerateur->FirstChildElement("vitesse")->GetText());
	mapPersonnageGenerateur["armure"] = atoi(persoGenerateur->FirstChildElement("armure")->GetText());
	mapPersonnageGenerateur["gain"] = atoi(persoGenerateur->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoAccelerant = personnages->FirstChildElement("accelerant");

	mapPersonnageAccelerant["vie"] = atoi(persoAccelerant->FirstChildElement("vie")->GetText());
	mapPersonnageAccelerant["vitesse"] = atoi(persoAccelerant->FirstChildElement("vitesse")->GetText());
	mapPersonnageAccelerant["armure"] = atoi(persoAccelerant->FirstChildElement("armure")->GetText());
	mapPersonnageAccelerant["gain"] = atoi(persoAccelerant->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoDouble = personnages->FirstChildElement("double");

	mapPersonnageDouble["vie"] = atoi(persoDouble->FirstChildElement("vie")->GetText());
	mapPersonnageDouble["vitesse"] = atoi(persoDouble->FirstChildElement("vitesse")->GetText());
	mapPersonnageDouble["armure"] = atoi(persoDouble->FirstChildElement("armure")->GetText());
	mapPersonnageDouble["gain"] = atoi(persoDouble->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* persoBoss = personnages->FirstChildElement("boss");

	mapPersonnageBoss["vie"] = atoi(persoBoss->FirstChildElement("vie")->GetText());
	mapPersonnageBoss["vitesse"] = atoi(persoBoss->FirstChildElement("vitesse")->GetText());
	mapPersonnageBoss["armure"] = atoi(persoBoss->FirstChildElement("armure")->GetText());
	mapPersonnageBoss["gain"] = atoi(persoBoss->FirstChildElement("gain")->GetText());

	tinyxml2::XMLElement* vagues = config->FirstChildElement("vagues");

	tinyxml2::XMLElement* vague1 = vagues->FirstChildElement("vague1");
	mapVague1["typePersos"] = atoi(vague1->FirstChildElement("typePersos")->GetText());
	mapVague1["nombre"] = atoi(vague1->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague2 = vagues->FirstChildElement("vague2");
	mapVague2["typePersos"] = atoi(vague2->FirstChildElement("typePersos")->GetText());
	mapVague2["nombre"] = atoi(vague2->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague3 = vagues->FirstChildElement("vague3");
	mapVague3["typePersos"] = atoi(vague3->FirstChildElement("typePersos")->GetText());
	mapVague3["nombre"] = atoi(vague3->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague4 = vagues->FirstChildElement("vague4");
	mapVague4["typePersos"] = atoi(vague4->FirstChildElement("typePersos")->GetText());
	mapVague4["nombre"] = atoi(vague4->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague5 = vagues->FirstChildElement("vague5");
	mapVague5["typePersos"] = atoi(vague5->FirstChildElement("typePersos")->GetText());
	mapVague5["nombre"] = atoi(vague5->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague6 = vagues->FirstChildElement("vague6");
	mapVague6["typePersos"] = atoi(vague6->FirstChildElement("typePersos")->GetText());
	mapVague6["nombre"] = atoi(vague6->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague7 = vagues->FirstChildElement("vague7");
	mapVague7["typePersos"] = atoi(vague7->FirstChildElement("typePersos")->GetText());
	mapVague7["nombre"] = atoi(vague7->FirstChildElement("nombre")->GetText());

	tinyxml2::XMLElement* vague8 = vagues->FirstChildElement("vague8");
	mapVague8["typePersos"] = atoi(vague8->FirstChildElement("typePersos")->GetText());
	mapVague8["nombre"] = atoi(vague8->FirstChildElement("nombre")->GetText());
}

ConfigManager::ConfigManager() {
	loadConfig();
}

ConfigManager::~ConfigManager() {
	// VIDE
}

