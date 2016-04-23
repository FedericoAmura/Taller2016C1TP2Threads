/*
 * FuncionAppendLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONAPPENDLISP_H_
#define FUNCIONAPPENDLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionAppendLISP : public FuncionLISP {
public:
	FuncionAppendLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionAppendLISP();
};

#endif /* FUNCIONAPPENDLISP_H_ */
