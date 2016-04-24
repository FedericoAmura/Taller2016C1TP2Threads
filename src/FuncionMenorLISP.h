/*
 * FuncionMenorLISP.h
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#ifndef FUNCIONMENORLISP_H_
#define FUNCIONMENORLISP_H_

#include <string>
#include <vector>

class InterpreteLISP;	//referencias circulares

#include "InterpreteLISP.h"

//Funcion que compara dos numeros
//Devuelve "1" si el primero es menor, lista vacia en otro caso
class FuncionMenorLISP : public FuncionLISP {
public:
	FuncionMenorLISP();

	std::vector<std::string> resolver(std::vector<std::string> args,
				const InterpreteLISP &interprete);

	virtual ~FuncionMenorLISP();
};

#endif /* FUNCIONMENORLISP_H_ */
