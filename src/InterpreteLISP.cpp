/*
 * InterpreteLISP.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "InterpreteLISP.h"

InterpreteLISP::InterpreteLISP(std::string linea) : linea(linea){
}

void InterpreteLISP::run() {
	//TODO este es el punto donde se empieza a procesar una linea
	std::cout << linea << "\n";
}

int InterpreteLISP::resolveCommand(std::string comando){
	//este es el que tiene que procesar la linea en cuestion y poder ser recursivo
	std::cout << linea << "\n";
}

bool InterpreteLISP::esSync() {
	return (linea.compare("(sync)") == 0);
}

bool InterpreteLISP::cumpleSintaxis() {
	int cantOpenParentesis = 0;
	int cantCloseParentesis = 0;
	for (std::string::iterator it=linea.begin(); it!=linea.end(); ++it) {
		if (*it == '(') cantOpenParentesis++;
		if (*it == ')') cantCloseParentesis++;
		if (cantOpenParentesis < cantCloseParentesis) {
			return false;
		}
	}
	if (cantCloseParentesis == 0) {
		return false;
	}
	return true;
}

InterpreteLISP::~InterpreteLISP() {
}

