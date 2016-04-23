/*
 * FuncionSyncLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionSyncLISP.h"

FuncionSyncLISP::FuncionSyncLISP() {
	tipo = CODIGO_FUNCION_NATIVA;
}

std::vector<std::string> FuncionSyncLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	return args;
}

FuncionSyncLISP::~FuncionSyncLISP() {
}

