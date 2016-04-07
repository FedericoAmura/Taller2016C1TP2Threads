/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "AmbienteLISP.h"

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

AmbienteLISP::AmbienteLISP() {
	i = 0;
	j = 0;
	FuncionLISP* funcionPrint = new FuncionNativaLISP(&print);
	environmentFunctions["print"] = funcionPrint;
}

int AmbienteLISP::enterLine(std::string linea) {
	InterpreteLISP* lineaLisp = new InterpreteLISP(linea);
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

