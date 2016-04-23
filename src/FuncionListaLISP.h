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

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionListaLISP : public FuncionLISP {
public:
	FuncionListaLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionListaLISP();
};

#endif /* FUNCIONLISTALISP_H_ */
