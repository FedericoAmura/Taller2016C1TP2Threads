/*
 * FuncionMenorLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionMenorLISP.h"

#include <string>
#include <vector>
#include <cstdlib>

FuncionMenorLISP::FuncionMenorLISP() {
}

std::vector<std::string> FuncionMenorLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
	std::vector<std::string> aux;
	//primer numero
	std::string primerValor = args.front();
	aux = interprete.procesarComandoLISP(primerValor);
	primerValor = aux.front();

	args.erase(args.begin());
	//segundo numero
	std::string segundoValor = args.front();
	aux = interprete.procesarComandoLISP(segundoValor);
	segundoValor = aux.front();

	float mayorFloat = std::atof(primerValor.c_str());
	float menorFloat = std::atof(segundoValor.c_str());

	//Hago comparacion
	if (mayorFloat < menorFloat) {
		//Devuelvo un "1" si es verdadero, convencion
		std::string positivo = "1";
		retorno.insert(retorno.begin(), positivo);
	}
	return retorno;
}

FuncionMenorLISP::~FuncionMenorLISP() {
}

