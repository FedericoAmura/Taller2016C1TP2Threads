/*
 * FuncionSyncLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONSYNCLISP_H_
#define FUNCIONSYNCLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

class FuncionSyncLISP : public FuncionLISP {
public:
	FuncionSyncLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionSyncLISP();
};

#endif /* FUNCIONSYNCLISP_H_ */
