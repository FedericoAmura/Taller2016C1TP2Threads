/*
 * FuncionLISP.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#include "FuncionLISP.h"

#define TIPO_FUNCION_NATIVA 0
#define TIPO_FUNCION_USUARIO 1

FuncionLISP::FuncionLISP() : tipo(0){
}

std::list<std::string> FuncionLISP::resolve(std::list<std::string> args) {
	std::list<std::string> lista;
	return lista;
}

FuncionLISP::~FuncionLISP() {
}

