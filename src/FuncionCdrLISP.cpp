/*
 * FuncionCdrLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionCdrLISP.h"

#include <string>
#include <vector>

FuncionCdrLISP::FuncionCdrLISP() {
}

std::vector<std::string> FuncionCdrLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno = args;
	do {	//Mientras el primer argumento sea un comando, lo resuelvo
		std::string primerArgumento = retorno.front();
		retorno = interprete.procesarComandoLISP(primerArgumento);
	} while (retorno.front().at(0) == '(');
	if (!retorno.empty())	//saco el primero y que quede el resto para devolver
		retorno.erase(retorno.begin());
	return retorno;
}

FuncionCdrLISP::~FuncionCdrLISP() {
}

