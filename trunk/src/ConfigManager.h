/*
 * ConfigManager.h
 *
 *  Created on: 20 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

#include "tinyxml2.h"
#include <map>
#include <string>

class ConfigManager {
public:
	static ConfigManager* getInstance();
	virtual ~ConfigManager();
	void loadConfig();
	int fps;
	int argent;
	int vie;
	int tauxRevente;
	std::map<std::string, int> mapTourBasique;
	std::map<std::string, int> mapTourCanon;
	std::map<std::string, int> mapTourDeGlace;
	std::map<std::string, int> mapTourSupport;
	std::map<std::string, int> mapMur;
	std::map<std::string, int> mapPersonnageNormal;
	std::map<std::string, int> mapPersonnageRapide;
	std::map<std::string, int> mapPersonnageSolide;
	std::map<std::string, int> mapPersonnageVolant;
	std::map<std::string, int> mapPersonnageGenerateur;
	std::map<std::string, int> mapPersonnageAccelerant;
	std::map<std::string, int> mapPersonnageDouble;
	std::map<std::string, int> mapPersonnageBoss;
	std::map<std::string, int> mapVagueNormal;
	std::map<std::string, int> mapVagueRapide;
	std::map<std::string, int> mapVagueSolide;
	std::map<std::string, int> mapVagueVolant;
	std::map<std::string, int> mapVagueGenerateur;
	std::map<std::string, int> mapVagueAccelerant;
	std::map<std::string, int> mapVagueDouble;
	std::map<std::string, int> mapVagueBoss;

private:
	ConfigManager();
};

#endif /* CONFIGMANAGER_H_ */
