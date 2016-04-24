/*
 * FuncionCondicionalLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionCondicionalLISP.h"

#include <string>
#include <vector>

FuncionCondicionalLISP::FuncionCondicionalLISP() {
}

std::vector<std::string> FuncionCondicionalLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::vector<std::string> retorno;
	//Veo la condicion a evaluar y la resuelvo
	std::string primerArgumento = args.front();
	args.erase(args.begin());
	std::vector<std::string> argumentoResuelto =
			interprete.procesarComandoLISP(primerArgumento);

	//En caso falso, saco el argumento a analizar si verdadero
	if (argumentoResuelto.empty()) {
		args.erase(args.begin());
	}
	//Resuelvo el primero argumento que quedo y devuelvo el resultado
	primerArgumento = args.front();
	retorno = interprete.procesarComandoLISP(primerArgumento);
	return retorno;
}

FuncionCondicionalLISP::~FuncionCondicionalLISP() {
}

