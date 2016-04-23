/*
 * FuncionSumaLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionSumaLISP.h"
#include "numeroATexto.cpp"
#include <cstdlib>

FuncionSumaLISP::FuncionSumaLISP() {
	tipo = CODIGO_FUNCION_NATIVA;
}

std::vector<std::string> FuncionSumaLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	std::vector<std::string> retorno;
	int valorFinal = 0;
	int aux;
	for(std::vector<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		std::vector<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::vector<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = atoi((*subArgs_iter).c_str());
			valorFinal += aux;
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

FuncionSumaLISP::~FuncionSumaLISP() {
}

