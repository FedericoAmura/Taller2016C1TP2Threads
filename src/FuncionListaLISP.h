/*
 * FuncionListaLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONLISTALISP_H_
#define FUNCIONLISTALISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionListaLISP : public FuncionLISP {
public:
	FuncionListaLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionListaLISP();
};

#endif /* FUNCIONLISTALISP_H_ */
