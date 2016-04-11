/*
 * VariableLISP.h
 *
 *  Created on: Apr 11, 2016
 *      Author: freddy
 */

#ifndef VARIABLELISP_H_
#define VARIABLELISP_H_

#include <string>
#include <list>

#include "Mutex.h"
#include "Lock.h"


class VariableLISP {
private:
	Mutex *m;
	std::list<std::string>* variable;

public:
	explicit VariableLISP(std::list<std::string> *valor);

	std::list<std::string>* getVariable();

	void setVariable(std::list<std::string> *valor);

	virtual ~VariableLISP();
};

#endif /* VARIABLELISP_H_ */
