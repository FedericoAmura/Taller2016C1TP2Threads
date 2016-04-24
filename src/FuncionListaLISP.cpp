/*
 * FuncionListaLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionListaLISP.h"

#include <string>
#include <vector>

FuncionListaLISP::FuncionListaLISP() {
}

std::vector<std::string> FuncionListaLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	//Devuelvo los argumentos como los recibo
	//El parser del interprete ya los convirtio en lista
	return args;
}

FuncionListaLISP::~FuncionListaLISP() {
}

