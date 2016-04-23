/*
 * FuncionSetqLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionSetqLISP.h"

FuncionSetqLISP::FuncionSetqLISP() {
}

std::vector<std::string> FuncionSetqLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	std::string nombreVariable;

	//el primer parametro no es algo evaluable
	nombreVariable = args.front();
	args.erase(args.begin());

	std::string argumento = args.front();
	std::vector<std::string> *valorVariable = new std::vector<std::string>();
	*valorVariable = interprete->procesarComandoLISP(argumento);

	VariableLISP *variable = interprete->conseguirVariable(nombreVariable);
	if (variable == 0) {
		//la variable no existe
		variable = new VariableLISP(valorVariable);
	} else {
		//modifico el valor de la variable
		delete(variable->getVariable());
		variable->setVariable(valorVariable);
	}
	interprete->agregarVariable(nombreVariable, variable);

	std::vector<std::string> retorno;
	return retorno;
}

FuncionSetqLISP::~FuncionSetqLISP() {
}

