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
#include <list>
#include <map>
#include "Thread.h"
#include "FuncionLISP.h"

class InterpreteLISP: public Thread {
private:
	std::string linea;
	std::map<std::string, std::string*> *variablesAmbiente;
	std::map<std::string, FuncionLISP*> *funcionesAmbiente;

public:
	InterpreteLISP(std::string linea, std::map<std::string, std::string*> *variablesAmbiente, std::map<std::string, FuncionLISP*> *funcionesAmbiente);

	virtual void run();

	std::list<std::string> procesarComandoLISP(std::string linea);

	bool esSync();

	bool lineaValida();

	virtual ~InterpreteLISP();

private:
	int verificarSintaxis();
	std::list<std::string> parseCommand(std::string comando);

};

#endif /* INTERPRETELISP_H_ */
