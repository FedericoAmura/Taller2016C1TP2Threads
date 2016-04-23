/*
 * FuncionRestaLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONRESTALISP_H_
#define FUNCIONRESTALISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionRestaLISP : public FuncionLISP {
public:
	FuncionRestaLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionRestaLISP();
};

#endif /* FUNCIONRESTALISP_H_ */
