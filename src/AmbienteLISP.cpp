/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "AmbienteLISP.h"

std::list<std::string> print(std::list<std::string> args, InterpreteLISP* interprete) {
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs = interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			std::cout << *subArgs_iter << " ";
		}
		//std::cout << *args_iter << " ";
	}
	std::cout << std::endl;
	std::list<std::string> retorno;
	return retorno;
}

AmbienteLISP::AmbienteLISP() {
	i = 0;
	j = 0;
	FuncionLISP* funcionPrint = new FuncionNativaLISP(&print);
	funcionesAmbiente["print"] = funcionPrint;
	std::string *a = new std::string();
	*a = "5";
	variablesAmbiente["a"] = a;
}

int AmbienteLISP::enterLine(std::string linea) {
	InterpreteLISP* lineaLisp = new InterpreteLISP(linea, &variablesAmbiente, &funcionesAmbiente);
	if (!lineaLisp->lineaValida()) {
		delete lineaLisp;
		return i+1;
	}

	lines.push_back(lineaLisp);
	if(lines[i]->esSync()) {
		while (j<=i) {
			lines[j]->join();
			j++;
		}
		std::cout << "Espero a todos\n";
	} else {
		//lines[i]->start();
		lines[i]->run(); //veamos si sin el start en los sync funciona igual, si no los corremos y que sync sea una funcion definida
	}
	i++;
	return LINE_OK;
}

AmbienteLISP::~AmbienteLISP() {
	for (int k = 0; k < i; k++) {
		delete lines[i];
	}
}

