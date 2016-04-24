/*
 * InterpreteLISP.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef INTERPRETELISP_H_
#define INTERPRETELISP_H_

class FuncionLISP;	//referencias circular

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Thread.h"
#include "FuncionLISP.h"
#include "VariableLISP.h"

class InterpreteLISP: public Thread {
private:
	//Linea original ingresada a LISP
	std::string linea;
	//Punteros a las variables y funciones que hay en el ambiente
	std::map<std::string, VariableLISP*> *variablesAmbiente;
	std::map<std::string, FuncionLISP*> *funcionesAmbiente;

public:
	InterpreteLISP(const std::string linea,
			std::map<std::string, VariableLISP*> *variablesAmbiente,
			std::map<std::string, FuncionLISP*> *funcionesAmbiente);

	virtual void run();

	//Procesa un elemento (comando, variable o literal) de LISP
	std::vector<std::string> procesarComandoLISP(const std::string &linea)const;

	//Agrega una variable a las variables del ambiente
	void agregarVariable(const std::string &nombre, VariableLISP *valor) const;

	//Consigue una variable de las variables del ambiente
	VariableLISP* conseguirVariable(const std::string &nombre) const;

	//Agrega una funcion en runtime a las funciones del ambiente
	void agregarFuncion(const std::string &nombre, FuncionLISP *valor) const;

	//Indica si la linea ingresada es un sync
	bool esSync() const;

	//Indica si la linea tiene un formato valido y puede ser procesada
	bool lineaValida() const;

	virtual ~InterpreteLISP();

private:
	//Verifica la sintaxis de la linea ingresada
	int verificarSintaxis();
	//Desglosa la linea de LISP en una lista (vector) de su funcion y argumentos
	std::vector<std::string> parseCommand(const std::string &comando) const;
};

#endif /* INTERPRETELISP_H_ */
