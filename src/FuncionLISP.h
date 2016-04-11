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

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionLISP {
protected:
	int tipo;
public:
	FuncionLISP();

	virtual std::list<std::string> resolver(std::list<std::string> args,
			InterpreteLISP* interprete);

	virtual ~FuncionLISP();
};

#endif /* FUNCIONLISP_H_ */
