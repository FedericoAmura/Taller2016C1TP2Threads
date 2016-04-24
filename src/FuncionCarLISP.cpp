/*
 * FuncionCarLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionCarLISP.h"

#include <string>
#include <vector>

FuncionCarLISP::FuncionCarLISP() {
}

std::vector<std::string> FuncionCarLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	if (args.size() == 0) return args;	//caso vacio, vuelve vacio
	std::vector<std::string> retorno;
	std::string valor;
	if (args.size() == 1) {	//caso argumento unico, lo resuelvo a lista
		std::vector<std::string> resolver =
				interprete.procesarComandoLISP(args.front());
		valor = resolver.front();
	} else {
		//varios argumentos, devuelvo solo el primero
		valor = args.front();
	}
	if (valor.substr(0,2) == "(l") {
		//Si el primero es una lista, lo paso al formato lista
		retorno = interprete.procesarComandoLISP(valor);
	} else {
		retorno.push_back(valor);
	}
	return retorno;
}

FuncionCarLISP::~FuncionCarLISP() {
}

