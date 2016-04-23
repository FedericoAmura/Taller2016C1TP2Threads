//============================================================================
// Name        : TallerTP2.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : Parallel LISP
//============================================================================

#include <iostream>
#include <string>

#include "AmbienteLISP.h"

#define PROGRAM_NO_ERROR 0
#define PROGRAM_PARAMETER_ERROR 1
#define PROGRAM_LINE_ERROR 2

int main(int argc, char *argv[]) {
	//error si me llaman con argumentos
	if (argc != 1) {
		std::cout << "ERROR: argumentos\n";
		return PROGRAM_PARAMETER_ERROR;
	}

	//declaro variables
	std::string lineError = LINE_OK;
	std::string linea;
	AmbienteLISP lisp;

	//leo cada linea y la proceso en lisp hasta EOF
	while (std::getline(std::cin, linea)) {
		if (!linea.empty()) {
			lineError = lisp.procesarLineaLISP(linea);
			if (lineError.compare(LINE_OK) != 0) {
				std::cout << "ERROR: " << lineError << "\n";
				return PROGRAM_LINE_ERROR;
			}
		}
	}

	return PROGRAM_NO_ERROR;
}
