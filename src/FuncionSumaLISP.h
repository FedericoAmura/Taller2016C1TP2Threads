/*
 * FuncionSumaLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONSUMALISP_H_
#define FUNCIONSUMALISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionSumaLISP : public FuncionLISP {
public:
	FuncionSumaLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionSumaLISP();
};

#endif /* FUNCIONSUMALISP_H_ */
