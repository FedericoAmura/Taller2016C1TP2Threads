/*
 * FuncionIgualLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONIGUALLISP_H_
#define FUNCIONIGUALLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

//Funcion que compara dos numeros
//Devuelve "1" si son iguales, lista vacia en otro caso
class FuncionIgualLISP : public FuncionLISP {
public:
	FuncionIgualLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionIgualLISP();
};

#endif /* FUNCIONIGUALLISP_H_ */
