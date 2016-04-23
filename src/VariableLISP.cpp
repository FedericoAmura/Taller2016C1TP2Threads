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
	Mutex *mutex = new Mutex();
	m = mutex;
}

std::vector<std::string>* VariableLISP::getVariable() {
	return variable;
}

void VariableLISP::setVariable(std::vector<std::string> *valor) {
	Lock l(*m);
	variable = valor;
}

VariableLISP::~VariableLISP() {
	delete(m);
	delete(variable);
}

