/*
 * FuncionDefunLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONDEFUNLISP_H_
#define FUNCIONDEFUNLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionDefunLISP : public FuncionLISP {
public:
	FuncionDefunLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionDefunLISP();
};

#endif /* FUNCIONDEFUNLISP_H_ */
