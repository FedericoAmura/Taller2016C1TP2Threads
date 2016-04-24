/*
 * FuncionProductoLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionProductoLISP.h"
#include "numeroATexto.cpp"

#include <string>
#include <vector>
#include <cstdlib>

FuncionProductoLISP::FuncionProductoLISP() {
}

std::vector<std::string> FuncionProductoLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
	int valorFinal = 1;
	int aux;
	for(std::vector<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		std::vector<std::string> subArgs =
				interprete.procesarComandoLISP(*args_iter);
		for (std::vector<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = atoi((*subArgs_iter).c_str());
			valorFinal *= aux;
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

FuncionProductoLISP::~FuncionProductoLISP() {
}

