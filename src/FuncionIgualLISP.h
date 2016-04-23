/*
 * FuncionIgualLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONIGUALLISP_H_
#define FUNCIONIGUALLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionIgualLISP : public FuncionLISP {
public:
	FuncionIgualLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionIgualLISP();
};

#endif /* FUNCIONIGUALLISP_H_ */
