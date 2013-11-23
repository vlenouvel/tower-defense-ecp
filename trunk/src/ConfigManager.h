/*
 * ConfigManager.h
 *
 *  Created on: 20 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

#include <iostream>
#include "tinyxml2.h"
#include <map>
#include <string>

class ConfigManager {
public:
	static ConfigManager* getInstance();
	virtual ~ConfigManager();
	void loadConfig();
	int fps;
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
	std::map<std::string, int> mapVague1;
	std::map<std::string, int> mapVague2;
	std::map<std::string, int> mapVague3;
	std::map<std::string, int> mapVague4;
	std::map<std::string, int> mapVague5;
	std::map<std::string, int> mapVague6;
	std::map<std::string, int> mapVague7;
	std::map<std::string, int> mapVague8;

private:
	ConfigManager();
};

#endif /* CONFIGMANAGER_H_ */
