/*
 * FuncionLISP.h
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#ifndef FUNCIONLISP_H_
#define FUNCIONLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionLISP {
protected:
	int tipo;
public:
	FuncionLISP();

	virtual std::vector<std::string> resolver(std::vector<std::string> args,
			InterpreteLISP* interprete) = 0;

	virtual ~FuncionLISP();
};

#endif /* FUNCIONLISP_H_ */
