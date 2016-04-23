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

	std::vector<std::string> procesarComandoLISP(const std::string &linea)const;

	void agregarVariable(const std::string &nombre, VariableLISP *valor) const;

	VariableLISP* conseguirVariable(const std::string &nombre) const;

	void agregarFuncion(const std::string &nombre, FuncionLISP *valor) const;

	bool esSync() const;

	bool lineaValida() const;

	virtual ~InterpreteLISP();

private:
	int verificarSintaxis();
	std::vector<std::string> parseCommand(const std::string &comando) const;
};

#endif /* INTERPRETELISP_H_ */
