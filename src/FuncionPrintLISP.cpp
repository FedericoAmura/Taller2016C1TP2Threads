/*
 * FuncionPrintLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionPrintLISP.h"

FuncionPrintLISP::FuncionPrintLISP() {
}

std::vector<std::string> FuncionPrintLISP::printRecursivo(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	for(std::vector<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		if (args_iter != args.begin()) std::cout << " ";
		std::vector<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		if (subArgs.size() == 0) {
			std::cout << "()";
		} else if (subArgs.size() == 1 && subArgs.front().at(0) != '(') {
			std::cout << subArgs.front();
		} else {
			std::cout << "(";
			printRecursivo(subArgs, interprete);
			std::cout << ")";
		}
	}
	std::vector<std::string> retorno;
	return retorno;
}

std::vector<std::string> FuncionPrintLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	printRecursivo(args, interprete);
	std::cout << std::endl;
	std::vector<std::string> retorno;
	return retorno;
}

FuncionPrintLISP::~FuncionPrintLISP() {
}

