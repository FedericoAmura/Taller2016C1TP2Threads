/*
 * InterpreteLISP.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef INTERPRETELISP_H_
#define INTERPRETELISP_H_

#include <iostream>
#include <string>
#include <list>
#include "Thread.h"
#include "AmbienteLISP.h"
#include "FuncionLISP.h"

class AmbienteLISP;	//por referencias circulares

class InterpreteLISP: public Thread {
private:
	std::string linea;
	AmbienteLISP *lisp;

public:
	InterpreteLISP(std::string linea, AmbienteLISP *lisp);

	virtual void run();

	bool esSync();

	bool lineaValida();

	virtual ~InterpreteLISP();

private:
	int verificarSintaxis();
	std::list<std::string> parseCommand(std::string comando);
	std::list<std::string> procesarComandoLISP(std::list<std::string> comando);

};

#endif /* INTERPRETELISP_H_ */
