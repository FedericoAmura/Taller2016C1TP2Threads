/*
 * LispEnvironment.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef AMBIENTELISP_H_
#define AMBIENTELISP_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include "Thread.h"
#include "InterpreteLISP.h"
#include "FuncionLISP.h"
#include "FuncionNativaLISP.h"

#define LINE_OK 0

class InterpreteLISP;

class AmbienteLISP {
private:
	std::map<std::string, void*> environmentVariables;
	std::map<std::string, FuncionLISP*> environmentFunctions;
	std::vector<InterpreteLISP*> lines;
	int i,j;

public:
	AmbienteLISP();

	int enterLine(std::string linea);

	FuncionLISP* getFuncion(std::string funcion);

	void setFuncion(std::string nombre, FuncionLISP* funcion);

	virtual ~AmbienteLISP();
};

#endif /* AMBIENTELISP_H_ */
