/*
 * VariableLISP.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: freddy
 */

#include "VariableLISP.h"
#include <string>
#include <list>

VariableLISP::VariableLISP(std::list<std::string> *valor) : variable(valor) {
	Mutex *mutex = new Mutex();
	m = mutex;
}

std::list<std::string>* VariableLISP::getVariable() {
	return variable;
}

void VariableLISP::setVariable(std::list<std::string> *valor) {
	Lock l(*m);
	variable = valor;
}

VariableLISP::~VariableLISP() {
	delete(m);
	delete(variable);
}

