/*
 * FuncionMenorLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionMenorLISP.h"
#include <cstdlib>

FuncionMenorLISP::FuncionMenorLISP() {
}

std::vector<std::string> FuncionMenorLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
		std::vector<std::string> aux;
		//primer numero
		std::string primero = args.front();
		args.erase(args.begin());
		aux = interprete.procesarComandoLISP(primero);
		primero = aux.front();
		//segundo numero
		std::string segundo = args.front();
		aux = interprete.procesarComandoLISP(segundo);
		segundo = aux.front();

		float mayorFloat = std::atof(primero.c_str());
		float menorFloat = std::atof(segundo.c_str());

		if (mayorFloat < menorFloat) {
			std::string positivo = "1";
			retorno.insert(retorno.begin(), positivo);
		}
		return retorno;
}

FuncionMenorLISP::~FuncionMenorLISP() {
}

