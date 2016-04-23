/*
 * InterpreteLISP.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "InterpreteLISP.h"
#include <string>
#include <vector>
#include <map>

InterpreteLISP::InterpreteLISP(std::string linea,
		std::map<std::string, VariableLISP*> *variablesAmbiente,
		std::map<std::string, FuncionLISP*> *funcionesAmbiente)
		: linea(linea), variablesAmbiente(variablesAmbiente),
		  funcionesAmbiente(funcionesAmbiente) {
}

void InterpreteLISP::run() {
	procesarComandoLISP(linea);
}

std::vector<std::string> InterpreteLISP::parseCommand(std::string comando){
	std::string *argumento = new std::string();
	std::vector<std::string> comandoParseado;

	std::string::iterator it=comando.begin();
	it++;	//para salvarme del primer "("
	for (; (*it!=' ') && (*it!=')'); ++it){
		argumento->append(1, *it);
	}
	comandoParseado.push_back(*argumento);
	argumento->clear();
	int parentesisAbiertos = 1;
	while (parentesisAbiertos != 0 && it!=comando.end()) {
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
					argumento->clear();
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
	delete (argumento);
	return comandoParseado;
}

std::vector<std::string> InterpreteLISP::procesarComandoLISP(std::string input){
	std::vector<std::string> comando;
	std::string palabra;
	if (input.empty()) return comando;
	if (input.at(0) =='(') {
		comando = parseCommand(input);

		std::string nombreFuncion;
		nombreFuncion = comando.front();
		comando.erase(comando.begin());
		FuncionLISP* funcion = (*funcionesAmbiente)[nombreFuncion];
		comando = funcion->resolver(comando, this);
	} else {
		if ((*variablesAmbiente)[input] != NULL) {
			return *((*variablesAmbiente)[input])->getVariable();
		} else {
			comando.push_back(input);
		}
	}
	return comando;
}

void InterpreteLISP::agregarVariable(std::string nombre, VariableLISP *valor) {
	(*variablesAmbiente)[nombre] = valor;
}

void InterpreteLISP::agregarFuncion(std::string nombre, FuncionLISP *valor) {
	(*funcionesAmbiente)[nombre] = valor;
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
	if (cantOpenParentesis!=cantCloseParentesis) {
		return false;
	}
	return true;
}

InterpreteLISP::~InterpreteLISP() {
}

