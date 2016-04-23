/*
 * FuncionDivisionLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionDivisionLISP.h"
#include "numeroATexto.cpp"
#include <cstdlib>

FuncionDivisionLISP::FuncionDivisionLISP() {
}

std::vector<std::string> FuncionDivisionLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
		float valorFinal = 1;
		int aux;
		for(std::vector<std::string>::iterator args_iter = args.begin();
		    args_iter != args.end(); args_iter++){
			std::vector<std::string> subArgs =
					interprete.procesarComandoLISP(*args_iter);
			for (std::vector<std::string>::iterator subArgs_iter = subArgs.begin();
					subArgs_iter != subArgs.end(); subArgs_iter++) {
				aux = std::atof((*subArgs_iter).c_str());
				if (args_iter == args.begin()) {
					valorFinal *= aux;
				} else {
					valorFinal /= aux;
				}
			}
		}
		std::string stringFinal;
		stringFinal = numeroATexto(valorFinal);
		retorno.push_back(stringFinal);
		return retorno;
}

FuncionDivisionLISP::~FuncionDivisionLISP() {
}

