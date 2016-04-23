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
	Mutex *m;
	std::vector<std::string>* variable;

public:
	explicit VariableLISP(std::vector<std::string> *valor);

	std::vector<std::string>* getVariable();

	void setVariable(std::vector<std::string> *valor);

	virtual ~VariableLISP();
};

#endif /* VARIABLELISP_H_ */
