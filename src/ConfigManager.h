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

private:
	ConfigManager();
};

#endif /* CONFIGMANAGER_H_ */
