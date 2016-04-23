/*
 * FuncionMayorLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionMayorLISP.h"
#include <cstdlib>

FuncionMayorLISP::FuncionMayorLISP() {
	tipo = CODIGO_FUNCION_NATIVA;
}

std::vector<std::string> FuncionMayorLISP::resolver(
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

		float mayorFloat = std::atof(primero.c_str());
		float menorFloat = std::atof(segundo.c_str());

		if (mayorFloat > menorFloat) {
			std::string positivo = "1";
			retorno.insert(retorno.begin(), positivo);
		}
		return retorno;
}

FuncionMayorLISP::~FuncionMayorLISP() {
}

