/*
 * FuncionLISP.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#include "FuncionLISP.h"
#include <string>
#include <list>

#define TIPO_FUNCION_NATIVA 0
#define TIPO_FUNCION_USUARIO 1

FuncionLISP::FuncionLISP() : tipo(0){
}

std::list<std::string> FuncionLISP::resolver(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> lista;
	throw -1;
	return lista;
}

FuncionLISP::~FuncionLISP() {
}

