//============================================================================
// Name        : TallerTP2.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "LISPEnvironment.h"

#define PROGRAM_NO_ERROR 0
#define PROGRAM_PARAMETER_ERROR 1
#define PROGRAM_LINE_ERROR 2

using namespace std;

int main(int argc, char *argv[]) {
	//error si me llaman con argumentos
	if (argc != 1) {
		cerr << "ERROR: argumentos\n";
		return PROGRAM_PARAMETER_ERROR;
	}

	//declaro variables
	int lineNumberError = 0;
	string linea;
	LISPEnvironment lisp;

	//leo cada linea y la proceso en lisp hasta EOF
	while (getline(cin, linea)) {
		lineNumberError = lisp.enterLine(linea);
		if (lineNumberError > 0) {
			cerr << "ERROR: " << lineNumberError << "\n";
			return PROGRAM_LINE_ERROR;
		}
	};

	return PROGRAM_NO_ERROR;
}
