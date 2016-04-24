/*
 * FuncionDefunLISP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include "FuncionDefunLISP.h"
#include "FuncionUsuarioLISP.h"

#include <string>
#include <vector>

FuncionDefunLISP::FuncionDefunLISP() {
}

std::vector<std::string> FuncionDefunLISP::resolver(
		std::vector<std::string> args,
		const InterpreteLISP &interprete) {
	std::string nombreFuncion;
	std::string cuerpoFuncion;

	std::string argumento = args.front();
	args.erase(args.begin());
	std::vector<std::string> argumentoResuelto =
			interprete.procesarComandoLISP(argumento);
	nombreFuncion = argumentoResuelto.front();

	args.erase(args.begin());

	cuerpoFuncion = args.front();	//no puede ser algo que se evalue

	//Genero puntero al nuevo functor y lo agrego al ambiente
	FuncionLISP *funcion = new FuncionUsuarioLISP(cuerpoFuncion);
	interprete.agregarFuncion(nombreFuncion, funcion);

	//Devuelvo lista vacia
	std::vector<std::string> retorno;
	return retorno;
}

FuncionDefunLISP::~FuncionDefunLISP() {
}

