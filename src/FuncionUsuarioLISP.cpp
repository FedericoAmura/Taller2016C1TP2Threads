/*
 * FuncionUsuarioLISP.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: freddy
 */

#include "FuncionUsuarioLISP.h"

FuncionUsuarioLISP::FuncionUsuarioLISP(std::string *codigo) : codigo(codigo) {
	tipo = CODIGO_FUNCION_USUARIO;
}

std::list<std::string> FuncionUsuarioLISP::resolver(std::list<std::string> args, InterpreteLISP* interprete) {
	std::list<std::string> lista;
	return lista;
}

FuncionUsuarioLISP::~FuncionUsuarioLISP() {
}

