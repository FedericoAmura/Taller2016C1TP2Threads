/*
 * FuncionPrintLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONPRINTLISP_H_
#define FUNCIONPRINTLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionPrintLISP : public FuncionLISP {
public:
	FuncionPrintLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionPrintLISP();

private:
	void printRecursivo(std::vector<std::string> args,
			const InterpreteLISP &interprete);
};

#endif /* FUNCIONPRINTLISP_H_ */
