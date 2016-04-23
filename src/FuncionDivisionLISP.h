/*
 * FuncionDivisionLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONDIVISIONLISP_H_
#define FUNCIONDIVISIONLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionDivisionLISP : public FuncionLISP {
public:
	FuncionDivisionLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionDivisionLISP();
};

#endif /* FUNCIONDIVISIONLISP_H_ */
