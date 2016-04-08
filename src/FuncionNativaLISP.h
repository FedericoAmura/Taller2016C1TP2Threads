/*
 * FuncionNativaLISP.h
 *
 *  Created on: Apr 6, 2016
 *      Author: freddy
 */

#ifndef FUNCIONNATIVALISP_H_
#define FUNCIONNATIVALISP_H_

#include "FuncionLISP.h"
#include "codigosFuncionesLISP.h"

typedef std::list<std::string> (*funcionLISP_t)(std::list<std::string>);

class FuncionNativaLISP : public FuncionLISP {
private:
	funcionLISP_t codigoFuncion;

public:
	FuncionNativaLISP(funcionLISP_t codigo);

	std::list<std::string> resolver(std::list<std::string> args);

	virtual ~FuncionNativaLISP();
};

#endif /* FUNCIONNATIVALISP_H_ */
