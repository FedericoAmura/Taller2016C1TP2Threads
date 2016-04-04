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
#include "Thread.h"
#include "InterpreteLISP.h"

#define LINE_OK 0

class LispEnvironment {
private:
	std::map<std::string, void*> environmentVariables;
	std::vector<InterpreteLISP*> lines;
	int i,j;

public:
	LispEnvironment();

	int enterLine(std::string linea);

	virtual ~LispEnvironment();
};

#endif /* LISPENVIRONMENT_H_ */
