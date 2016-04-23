/*
 * VariableLISP.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: freddy
 */

#include "VariableLISP.h"
#include <string>
#include <vector>

VariableLISP::VariableLISP(std::vector<std::string> *valor) : variable(valor) {
}

std::vector<std::string>* VariableLISP::getVariable() {
	Lock l(m);
	std::vector<std::string>* copia = variable;
	return copia;
}

void VariableLISP::setVariable(std::vector<std::string> *valor) {
	Lock l(m);
	variable = valor;
}

VariableLISP::~VariableLISP() {
	delete(variable);
}

