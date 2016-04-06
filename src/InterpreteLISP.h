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

class InterpreteLISP: public Thread {
private:
	std::string linea;

public:
	InterpreteLISP(std::string linea);

	virtual void run();

	bool esSync();

	bool cumpleSintaxis();

	virtual ~InterpreteLISP();

private:
	int verificarSintaxis();
	std::list<std::string> parseCommand(std::string comando);

};

#endif /* INTERPRETELISP_H_ */
