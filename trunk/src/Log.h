/*
 * Log.h
 *
 *  Created on: 11 nov. 2013
 *      Author: francois
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>

using namespace std;

class Log {
public:
	bool actif;
	virtual ~Log();
	Log();
	void log(const string& text);
};

#endif /* LOG_H_ */
