/*
 * LispEnvironment.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef AMBIENTELISP_H_
#define AMBIENTELISP_H_

class FuncionLISP;	//referencias circulares

#include <map>
#include <vector>
#include <string>
#include "InterpreteLISP.h"
#include "FuncionLISP.h"
#include "VariableLISP.h"
#include "Mutex.h"

#define LINE_OK "0"

class InterpreteLISP;

class AmbienteLISP {
private:
	//coleccion de variables guardadas
	std::map<std::string, VariableLISP*> variablesAmbiente;
	//coleccion de funciones disponibles (nativas y definidas por el usuario)
	std::map<std::string, FuncionLISP*> funcionesAmbiente;
	//lineas (e hilos) ingresadas
	std::vector<InterpreteLISP*> lines;
	//indices para el manejo de hilos
	int i,j;

public:
	AmbienteLISP();

	//acepta una nueva linea y la procesa en un nuevo hilo
	std::string procesarLineaLISP(const std::string &linea);

	virtual ~AmbienteLISP();
};

#endif /* AMBIENTELISP_H_ */
