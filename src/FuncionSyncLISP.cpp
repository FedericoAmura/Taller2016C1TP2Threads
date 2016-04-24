/*
 * FuncionSyncLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionSyncLISP.h"

#include <string>
#include <vector>

FuncionSyncLISP::FuncionSyncLISP() {
}

std::vector<std::string> FuncionSyncLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	//No hago nada, esta funcion solo afecta al comportamiento del ambiente
	return args;
}

FuncionSyncLISP::~FuncionSyncLISP() {
}

