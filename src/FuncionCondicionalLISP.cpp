/*
 * FuncionCondicionalLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionCondicionalLISP.h"

FuncionCondicionalLISP::FuncionCondicionalLISP() {
	tipo = CODIGO_FUNCION_NATIVA;
}

std::vector<std::string> FuncionCondicionalLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	std::string argumentoRetornado;
	std::vector<std::string> retorno;
	std::string primerArgumento = args.front();
	args.erase(args.begin());
	std::vector<std::string> argumentoResuelto =
			interprete->procesarComandoLISP(primerArgumento);
	if (argumentoResuelto.empty()) {
		args.erase(args.begin());
	}
	primerArgumento = args.front();
	retorno = interprete->procesarComandoLISP(primerArgumento);
	return retorno;
}

FuncionCondicionalLISP::~FuncionCondicionalLISP() {
}

