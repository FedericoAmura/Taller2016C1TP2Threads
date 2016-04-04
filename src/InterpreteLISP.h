/*
 * InterpreteLISP.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef INTERPRETELISP_H_
#define INTERPRETELISP_H_

#include <iostream>
#include "Thread.h"
#include <string>

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
	int resolveCommand(std::string comando);

};

#endif /* INTERPRETELISP_H_ */
