/*
 * InterpreteLISP.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "InterpreteLISP.h"
#include "FuncionLISP.h"

InterpreteLISP::InterpreteLISP(std::string linea) : linea(linea){
}

void InterpreteLISP::run() {
	std::list<std::string> lista;
	std::string comando;

	lista = InterpreteLISP::parseCommand(linea);
	InterpreteLISP::procesarComandoLISP(lista);
}

std::list<std::string> InterpreteLISP::parseCommand(std::string comando){
	std::string comandoLISP;
	std::string *argumento = new std::string();
	std::list<std::string> comandoParseado;

	std::string::iterator it=linea.begin();
	it++;	//para salvarme del primer "("
	for (; (*it!=' ') && (*it!=')'); ++it){
		argumento->append(1, *it);
	}
	comandoParseado.push_back(*argumento);
	argumento = new std::string();
	int parentesisAbiertos = 1;
	while (parentesisAbiertos != 0) {
		if (*it==')') {
			parentesisAbiertos--;
		} else if (*it=='(') {
			parentesisAbiertos++;
		}
		if (parentesisAbiertos == 1) {
			//voy creando argumentos separando por espacio
			if (*it == ' ') {
				if (argumento->compare("") != 0) {
					comandoParseado.push_back(*argumento);
					argumento = new std::string();
				}
			} else {
				argumento->append(1, *it);
			}
		}
		if (parentesisAbiertos > 1) {
			argumento->append(1, *it);
		}
		++it;
	}
	if (argumento->compare("") != 0) {
		comandoParseado.push_back(*argumento);
	}
	std::cout << "El comando fue: " << comandoLISP << "\n";
	std::cout << "y sus parametros:\n";
	for (std::list<std::string>::iterator it=comandoParseado.begin(); it != comandoParseado.end(); ++it){
		std::cout << '-' << *it << "\n";
	}
	return comandoParseado;
}

std::list<std::string> InterpreteLISP::procesarComandoLISP(std::list<std::string> comando){
	std::string palabra;
	for (std::list<std::string>::iterator it=comando.begin(); it != comando.end(); ++it){
		std::cout << '-' << *it << "\n";
	}
	return comando;
}

bool InterpreteLISP::esSync() {
	return (linea.compare("(sync)") == 0);
}

bool InterpreteLISP::lineaValida() {
	int cantOpenParentesis = 0;
	int cantCloseParentesis = 0;
	for (std::string::iterator it=linea.begin(); it!=linea.end(); ++it) {
		if (*it == '(') cantOpenParentesis++;
		if (*it == ')') cantCloseParentesis++;
		if (cantOpenParentesis < cantCloseParentesis) {
			return false;
		}
	}
	if (cantCloseParentesis == 0) {
		return false;
	}
	return true;
}

InterpreteLISP::~InterpreteLISP() {
}

