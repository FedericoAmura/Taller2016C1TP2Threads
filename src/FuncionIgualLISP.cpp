/*
 * FuncionIgualLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionIgualLISP.h"
#include <cstdlib>

FuncionIgualLISP::FuncionIgualLISP() {
}

std::vector<std::string> FuncionIgualLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	std::vector<std::string> retorno;
	std::vector<std::string> aux;
	//primer numero
	std::string primero = args.front();
	args.erase(args.begin());
	aux = interprete->procesarComandoLISP(primero);
	primero = aux.front();
	//segundo numero
	std::string segundo = args.front();
	aux = interprete->procesarComandoLISP(segundo);
	segundo = aux.front();

	float primeroFloat = std::atof(primero.c_str());
	float segundoFloat = std::atof(segundo.c_str());

	if (primeroFloat == segundoFloat) {
		std::string positivo = "1";
		retorno.insert(retorno.begin(), positivo);
	}
	return retorno;
}

FuncionIgualLISP::~FuncionIgualLISP() {
}
