/*
 * FuncionLISP.h
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#ifndef FUNCIONLISP_H_
#define FUNCIONLISP_H_

#include <string>
#include <list>

#include "codigosFuncionesLISP.h"

class FuncionLISP {
protected:
	int tipo;
public:
	FuncionLISP();

	virtual std::list<std::string> resolve(std::list<std::string> args);

	virtual ~FuncionLISP() = 0;
};

#endif /* FUNCIONLISP_H_ */
