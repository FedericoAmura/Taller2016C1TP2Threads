/*
 * LispEnvironment.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef LISPENVIRONMENT_H_
#define LISPENVIRONMENT_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include "Thread.h"
#include "InterpreteLISP.h"

#define LINE_OK 0

typedef std::list<std::string> (*funcionLisp_t)(std::list<std::string>);

class LispEnvironment {
private:
	std::map<std::string, void*> environmentVariables;
//	std::map<std::string, funcionLisp_t*> environmentFunctions;
	std::vector<InterpreteLISP*> lines;
	int i,j;

public:
	LispEnvironment();

	int enterLine(std::string linea);

//	std::list<std::string> print(std::list<std::string> args);

	virtual ~LispEnvironment();
};

#endif /* LISPENVIRONMENT_H_ */
