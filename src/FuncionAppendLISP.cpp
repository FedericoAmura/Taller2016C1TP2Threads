/*
 * FuncionAppendLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionAppendLISP.h"

FuncionAppendLISP::FuncionAppendLISP() {
}

std::vector<std::string> FuncionAppendLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
	for(std::vector<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		std::vector<std::string> subArgs =
				interprete.procesarComandoLISP(*args_iter);
		for (std::vector<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			retorno.push_back(*subArgs_iter);
		}
	}
	return retorno;
}

FuncionAppendLISP::~FuncionAppendLISP() {
}

