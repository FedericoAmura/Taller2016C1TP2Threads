/*
 * VariableLISP.h
 *
 *  Created on: Apr 11, 2016
 *      Author: freddy
 */

#ifndef VARIABLELISP_H_
#define VARIABLELISP_H_

#include <string>
#include <vector>

#include "Mutex.h"
#include "Lock.h"


class VariableLISP {
private:
	Mutex m; //mutex para no permitir que se superpongan lecturas/escrituras
	std::vector<std::string>* variable;

public:
	//constructor de los objetos variables
	explicit VariableLISP(std::vector<std::string> *valor);

	//getter
	std::vector<std::string>* getVariable();

	//setter
	void setVariable(std::vector<std::string> *valor);

	//destructor
	virtual ~VariableLISP();
};

#endif /* VARIABLELISP_H_ */
