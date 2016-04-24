/*
 * FuncionIgualLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionIgualLISP.h"

#include <string>
#include <vector>
#include <cstdlib>

FuncionIgualLISP::FuncionIgualLISP() {
}

std::vector<std::string> FuncionIgualLISP::resolver(
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

	float primeroFloat = std::atof(primerValor.c_str());
	float segundoFloat = std::atof(segundoValor.c_str());

	//Hago comparacion
	if (primeroFloat == segundoFloat) {
		std::string positivo = "1";
		retorno.insert(retorno.begin(), positivo);
	}
	return retorno;
}

FuncionIgualLISP::~FuncionIgualLISP() {
}

