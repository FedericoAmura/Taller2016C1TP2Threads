/*
 * FuncionCondicionalLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONCONDICIONALLISP_H_
#define FUNCIONCONDICIONALLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionCondicionalLISP : public FuncionLISP {
public:
	FuncionCondicionalLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionCondicionalLISP();
};

#endif /* FUNCIONCONDICIONALLISP_H_ */
