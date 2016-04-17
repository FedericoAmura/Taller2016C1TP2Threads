/*
 * LispEnvironment.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef AMBIENTELISP_H_
#define AMBIENTELISP_H_

class FuncionLISP;	//referencias circulares

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include "Thread.h"
#include "InterpreteLISP.h"
#include "FuncionLISP.h"
#include "FuncionNativaLISP.h"
#include "FuncionUsuarioLISP.h"
#include "VariableLISP.h"

#define LINE_OK "0"

class InterpreteLISP;

class AmbienteLISP {
private:
	std::map<std::string, VariableLISP*> variablesAmbiente;
	std::map<std::string, FuncionLISP*> funcionesAmbiente;
	std::vector<InterpreteLISP*> lines;
	int i,j;

public:
	AmbienteLISP();

	std::string procesarLineaLISP(std::string linea);

	virtual ~AmbienteLISP();
};

#endif /* AMBIENTELISP_H_ */
