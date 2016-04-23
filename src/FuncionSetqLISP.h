/*
 * FuncionSetqLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONSETQLISP_H_
#define FUNCIONSETQLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionSetqLISP : public FuncionLISP {
public:
	FuncionSetqLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionSetqLISP();
};

#endif /* FUNCIONSETQLISP_H_ */
