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

std::list<std::string> FuncionNativaLISP::resolve(std::list<std::string> args) {
	std::list<std::string> lista;
	return lista;
}

FuncionNativaLISP::~FuncionNativaLISP() {
}

