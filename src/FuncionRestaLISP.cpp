/*
 * FuncionRestaLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionRestaLISP.h"
#include "numeroATexto.cpp"

#include <string>
#include <vector>
#include <cstdlib>

FuncionRestaLISP::FuncionRestaLISP() {
}

std::vector<std::string> FuncionRestaLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
		int valorFinal = 0;
		int aux;
		for(std::vector<std::string>::iterator args_iter = args.begin();
		    args_iter != args.end(); args_iter++){
			std::vector<std::string> subArgs =
					interprete.procesarComandoLISP(*args_iter);
			for (std::vector<std::string>::iterator subArgs_iter = subArgs.begin();
					subArgs_iter != subArgs.end(); subArgs_iter++) {
				aux = atoi((*subArgs_iter).c_str());
				if (args_iter == args.begin()) {
					//Si el primer argumento es una lista, sumo esos valores
					//(Se supone el primer valor positivo y el resto negativos)
					valorFinal += aux;
				} else {
					valorFinal -= aux;
				}
			}
		}
		std::string stringFinal;
		stringFinal = numeroATexto(valorFinal);
		retorno.push_back(stringFinal);
		return retorno;
}

FuncionRestaLISP::~FuncionRestaLISP() {
}

