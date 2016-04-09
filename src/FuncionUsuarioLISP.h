/*
 * FuncionUsuarioLISP.h
 *
 *  Created on: Apr 9, 2016
 *      Author: freddy
 */

#ifndef FUNCIONUSUARIOLISP_H_
#define FUNCIONUSUARIOLISP_H_

#include "FuncionLISP.h"
#include "codigosFuncionesLISP.h"
#include "InterpreteLISP.h"

#include <string>

class FuncionUsuarioLISP : public FuncionLISP {
private:
	std::string *codigo;

public:
	FuncionUsuarioLISP(std::string *codigo);

	std::list<std::string> resolver(std::list<std::string> args, InterpreteLISP* interprete);

	virtual ~FuncionUsuarioLISP();
};

#endif /* FUNCIONUSUARIOLISP_H_ */
