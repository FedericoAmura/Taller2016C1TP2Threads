/*
 * FuncionSetqLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionSetqLISP.h"

#include <string>
#include <vector>

FuncionSetqLISP::FuncionSetqLISP() {
}

std::vector<std::string> FuncionSetqLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::string nombreVariable;

	//el primer parametro no es algo evaluable
	nombreVariable = args.front();
	args.erase(args.begin());

	std::string argumento = args.front();
	std::vector<std::string> *valorVariable = new std::vector<std::string>();
	*valorVariable = interprete.procesarComandoLISP(argumento);

	//Busco si la variable ya esta cargada
	VariableLISP *variable = interprete.conseguirVariable(nombreVariable);
	if (variable == 0) {
		//la variable no existe
		variable = new VariableLISP(valorVariable);
	} else {
		//modifico el valor de la variable existente
		delete(variable->getVariable());
		variable->setVariable(valorVariable);
	}
	//La vuelvo a cargar en el ambiente
	interprete.agregarVariable(nombreVariable, variable);

	//Devuelvo lista vacia
	std::vector<std::string> retorno;
	return retorno;
}

FuncionSetqLISP::~FuncionSetqLISP() {
}

