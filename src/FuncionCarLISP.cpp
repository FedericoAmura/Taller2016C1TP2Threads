/*
 * FuncionCarLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionCarLISP.h"

FuncionCarLISP::FuncionCarLISP() {
}

std::vector<std::string> FuncionCarLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	if (args.size() == 0) return args;
	std::vector<std::string> retorno;
	std::string valor;
	if (args.size() == 1) {
		std::vector<std::string> resolver =
				interprete.procesarComandoLISP(args.front());
		valor = resolver.front();
	} else {
		valor = args.front();
	}
	if (valor.substr(0,2) == "(l") {
		retorno = interprete.procesarComandoLISP(valor);
	} else {
		retorno.push_back(valor);
	}
	return retorno;
}

FuncionCarLISP::~FuncionCarLISP() {
}

