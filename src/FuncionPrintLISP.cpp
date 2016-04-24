/*
 * FuncionPrintLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionPrintLISP.h"

#include <string>
#include <vector>

FuncionPrintLISP::FuncionPrintLISP() {
}

void FuncionPrintLISP::printRecursivo(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	//Itero por los argumentos ingresados
	for(std::vector<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		if (args_iter != args.begin()) std::cout << " ";
		//Resuelvo el argumento
		std::vector<std::string> subArgs =
				interprete.procesarComandoLISP(*args_iter);
		if (subArgs.size() == 0) {
			//Lista vacia
			std::cout << "()";
		} else if (subArgs.size() == 1 && subArgs.front().at(0) != '(') {
			//Unico elemento, no lista y no es un comando
			std::cout << subArgs.front();
		} else {
			//Es una lista o un comando
			std::cout << "(";
			printRecursivo(subArgs, interprete);
			std::cout << ")";
		}
	}
}

std::vector<std::string> FuncionPrintLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	//Lleno el std::out recursivamente con todo lo que tengo que imprimir
	printRecursivo(args, interprete);
	//Finalmente le marco el fin de linea y lo imprimo
	std::cout << std::endl;
	//Devuelvo lista vacia
	std::vector<std::string> retorno;
	return retorno;
}

FuncionPrintLISP::~FuncionPrintLISP() {
}

