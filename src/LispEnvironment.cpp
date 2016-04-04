/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "LispEnvironment.h"

LispEnvironment::LispEnvironment() {
	i = 0;
	j = 0;
}

int LispEnvironment::enterLine(std::string linea) {
	InterpreteLISP* lineaLisp = new InterpreteLISP(linea);
	if (!lineaLisp->cumpleSintaxis()) {
		return i+1;
	}

	lines.push_back(lineaLisp);
	lines[i]->start();
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

LispEnvironment::~LispEnvironment() {
	for (int k = 0; k < i; k++) {
		delete lines[i];
	}
}

