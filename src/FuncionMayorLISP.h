/*
 * FuncionMayorLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONMAYORLISP_H_
#define FUNCIONMAYORLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

//Funcion que compara dos numeros
//Devuelve "1" si el primero es mayor, lista vacia en otro caso
class FuncionMayorLISP : public FuncionLISP {
public:
	FuncionMayorLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionMayorLISP();
};

#endif /* FUNCIONMAYORLISP_H_ */
