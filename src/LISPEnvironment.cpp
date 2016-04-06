/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "LISPEnvironment.h"

#include "InterpreteLISP.h"
#include "FuncionLISP.h"
#include "FuncionNativaLISP.h"

std::list<std::string> print(std::list<std::string> args) {
	for(std::list<std::string>::iterator list_iter = args.begin();
	    list_iter != args.end(); list_iter++){
	    std::cout << *list_iter;
	}
	std::cout << "\n";
	std::list<std::string> retorno;
	return retorno;
}

LISPEnvironment::LISPEnvironment() {
	i = 0;
	j = 0;
	FuncionLISP* funcionPrint = new FuncionNativaLISP(&print);
	environmentFunctions["print"] = funcionPrint;
}

int LISPEnvironment::enterLine(std::string linea) {
	InterpreteLISP* lineaLisp = new InterpreteLISP(linea);
	if (!lineaLisp->cumpleSintaxis()) {
		return i+1;
	}

	lines.push_back(lineaLisp);
	//lines[i]->start();
	lines[i]->run();
	if(lines[i]->esSync()) {
		while (j<=i) {
			lines[j]->join();
			j++;
		}
		std::cout << "Espero a todos\n";
	}
	i++;
	return LINE_OK;
}

LISPEnvironment::~LISPEnvironment() {
	for (int k = 0; k < i; k++) {
		delete lines[i];
	}
}

