/*
 * Log.h
 *
 *  TowerDefense ECP
 *      
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
