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
#include "FuncionLISP.h"

#define LINE_OK 0

class LISPEnvironment {
private:
	std::map<std::string, void*> environmentVariables;
	std::map<std::string, FuncionLISP*> environmentFunctions;
	std::vector<InterpreteLISP*> lines;
	int i,j;

public:
	LISPEnvironment();

	int enterLine(std::string linea);

//	std::list<std::string> print(std::list<std::string> args);

	virtual ~LISPEnvironment();
};

#endif /* LISPENVIRONMENT_H_ */
