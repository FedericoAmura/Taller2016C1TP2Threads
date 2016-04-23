/*
 * FuncionProductoLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONPRODUCTOLISP_H_
#define FUNCIONPRODUCTOLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

class FuncionProductoLISP : public FuncionLISP {
public:
	FuncionProductoLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				InterpreteLISP* interprete);

	virtual ~FuncionProductoLISP();
};

#endif /* FUNCIONPRODUCTOLISP_H_ */
