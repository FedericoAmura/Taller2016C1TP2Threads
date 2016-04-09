/*
 * InterpreteLISP.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "InterpreteLISP.h"

InterpreteLISP::InterpreteLISP(std::string linea, std::map<std::string, std::string*> *variablesAmbiente, std::map<std::string, FuncionLISP*> *funcionesAmbiente) : linea(linea), variablesAmbiente(variablesAmbiente), funcionesAmbiente(funcionesAmbiente) {
}

void InterpreteLISP::run() {
	procesarComandoLISP(linea);
}

std::list<std::string> InterpreteLISP::parseCommand(std::string comando){
	std::string *argumento = new std::string();
	std::list<std::string> comandoParseado;

	std::string::iterator it=comando.begin();
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
	return comandoParseado;
}

std::list<std::string> InterpreteLISP::procesarComandoLISP(std::string input){
	std::list<std::string> comando;
	std::string palabra;
	if (input.at(0) =='(') {
		comando = parseCommand(input);
		/*std::cout << "Vamos a procesar\n";
		for (std::list<std::string>::iterator it=comando.begin(); it != comando.end(); ++it){
			std::cout << '-' << *it << "\n";
		}*/

		std::string nombreFuncion;
		nombreFuncion = comando.front();
		comando.pop_front();
		FuncionLISP* funcion = (*funcionesAmbiente)[nombreFuncion];
		comando = funcion->resolver(comando, this);
	} else {
		if ((*variablesAmbiente)[input] != NULL) {
			comando.push_back(*(*variablesAmbiente)[input]);
		} else {
			comando.push_back(input);
		}
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

