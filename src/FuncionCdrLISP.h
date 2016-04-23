/*
 * FuncionCdrLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONCDRLISP_H_
#define FUNCIONCDRLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionCdrLISP : public FuncionLISP {
public:
	FuncionCdrLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionCdrLISP();
};

#endif /* FUNCIONCDRLISP_H_ */
