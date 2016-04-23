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
#include <vector>

class FuncionUsuarioLISP : public FuncionLISP {
private:
	std::string *codigo;

public:
	explicit FuncionUsuarioLISP(std::string *codigo);

	std::vector<std::string> resolver(std::vector<std::string> args,
			InterpreteLISP* interprete);

	virtual ~FuncionUsuarioLISP();

private:
	std::string reemplazarAmbiente(std::string ambiente);
};

#endif /* FUNCIONUSUARIOLISP_H_ */
