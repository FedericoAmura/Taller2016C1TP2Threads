/*
 * FuncionNativaLISP.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#include "FuncionNativaLISP.h"

FuncionNativaLISP::FuncionNativaLISP(funcionLISP_t codigo) : codigoFuncion(codigo) {
	tipo = CODIGO_FUNCION_NATIVA;
}

std::list<std::string> FuncionNativaLISP::resolver(std::list<std::string> args, InterpreteLISP* interprete) {
	std::list<std::string> lista;
	lista = codigoFuncion(args, interprete);
	return lista;
}

FuncionNativaLISP::~FuncionNativaLISP() {
}

