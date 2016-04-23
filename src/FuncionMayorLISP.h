/*
 * FuncionMayorLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONMAYORLISP_H_
#define FUNCIONMAYORLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionMayorLISP : public FuncionLISP {
public:
	FuncionMayorLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionMayorLISP();
};

#endif /* FUNCIONMAYORLISP_H_ */
