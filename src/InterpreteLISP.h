/*
 * InterpreteLISP.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef INTERPRETELISP_H_
#define INTERPRETELISP_H_

class FuncionLISP;	//referencias circular

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Thread.h"
#include "FuncionLISP.h"
#include "VariableLISP.h"

class InterpreteLISP: public Thread {
private:
	std::string linea;
	std::map<std::string, VariableLISP*> *variablesAmbiente;
	std::map<std::string, FuncionLISP*> *funcionesAmbiente;

public:
	InterpreteLISP(const std::string linea,
			std::map<std::string, VariableLISP*> *variablesAmbiente,
			std::map<std::string, FuncionLISP*> *funcionesAmbiente);

	virtual void run();

	std::vector<std::string> procesarComandoLISP(const std::string linea);

	void agregarVariable(const std::string nombre, VariableLISP *valor);

	VariableLISP* conseguirVariable(const std::string nombre);

	void agregarFuncion(const std::string nombre, FuncionLISP *valor);

	bool esSync();

	bool lineaValida();

	virtual ~InterpreteLISP();

private:
	int verificarSintaxis();
	std::vector<std::string> parseCommand(std::string comando);
};

#endif /* INTERPRETELISP_H_ */
