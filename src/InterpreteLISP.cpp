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

InterpreteLISP::InterpreteLISP(const std::string linea,
		std::map<std::string, VariableLISP*> *variablesAmbiente,
		std::map<std::string, FuncionLISP*> *funcionesAmbiente)
		: linea(linea), variablesAmbiente(variablesAmbiente),
		  funcionesAmbiente(funcionesAmbiente) {
	//Construimos el objeto
}

void InterpreteLISP::run() {
	//Inicia la ejecucion en un nuevo hilo
	procesarComandoLISP(linea);
}

std::vector<std::string> InterpreteLISP::parseCommand(
		const std::string &comando) const{
	std::string argumento;
	std::vector<std::string> comandoParseado;

	std::string::const_iterator it=comando.begin();
	it++;	//para salvarme del primer "("
	for (; (*it!=' ') && (*it!=')'); ++it){
		argumento.append(1, *it);
	} //leemos toda la primera palabra, comando
	comandoParseado.push_back(argumento);
	argumento.clear();

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
				if (argumento.compare("") != 0) {
					comandoParseado.push_back(argumento);
					argumento.clear();
				}
			} else {
				argumento.append(1, *it);
			}
		}
		if (parentesisAbiertos > 1) {
			argumento.append(1, *it);
		}
		++it;
	} //vamos leyendo todas las palabras que quedan, argumentos
	if (argumento.compare("") != 0) {
		comandoParseado.push_back(argumento);
	}
	return comandoParseado;
}

//Ingresa un string que puede ser tanto un comando, una variable o un literal
//por lo que se procesa y devuelve resuelto, si corresponde, en formato de lista
std::vector<std::string> InterpreteLISP::procesarComandoLISP(
		const std::string &input) const {
	std::vector<std::string> comando;
	std::string palabra;
	if (input.empty()) return comando;
	if (input.at(0) =='(') {
		//el string ingresado es comando LISP
		comando = parseCommand(input);

		std::string nombreFuncion;
		nombreFuncion = comando.front();
		comando.erase(comando.begin());
		FuncionLISP* funcion = (*funcionesAmbiente)[nombreFuncion];
		comando = funcion->resolver(comando, *this);
	} else {
		//el string ingresado es un simbolo
		if ((*variablesAmbiente)[input] != NULL) {
			//el simbolo es una variable definida anteriormente
			return *((*variablesAmbiente)[input])->getVariable();
		} else {
			//el simbolo ingresado es un literal
			comando.push_back(input);
		}
	}
	return comando;
}

void InterpreteLISP::agregarVariable(const std::string &nombre,
		VariableLISP *valor) const {
	(*variablesAmbiente)[nombre] = valor;
}

VariableLISP* InterpreteLISP::conseguirVariable(const std::string &nombre)const{
	return (*variablesAmbiente)[nombre];
}

void InterpreteLISP::agregarFuncion(const std::string &nombre,
		FuncionLISP *valor) const {
	(*funcionesAmbiente)[nombre] = valor;
}

bool InterpreteLISP::esSync() const {
	return (linea.compare("(sync)") == 0);
}

bool InterpreteLISP::lineaValida() const {
	//Verifica que haya un numero identico de ambos parentesis
	//y que esten en orden correcto
	int cantOpenParentesis = 0;
	int cantCloseParentesis = 0;
	for (std::string::const_iterator it=linea.begin(); it!=linea.end(); ++it) {
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

