/*
 * FuncionCarLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONCARLISP_H_
#define FUNCIONCARLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionCarLISP : public FuncionLISP {
public:
	FuncionCarLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionCarLISP();
};

#endif /* FUNCIONCARLISP_H_ */
