/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "AmbienteLISP.h"
#include <string>
#include <list>
#include <sstream>
#include <map>

std::list<std::string> print(std::list<std::string> args,
		InterpreteLISP* interprete) {
	for(std::list<std::string>::iterator args_iter = args.begin();
			args_iter != args.end(); args_iter++){
		if (args_iter != args.begin()) std::cout << " ";
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		if (subArgs.size() != 1) std::cout << "(";
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			if (subArgs_iter != subArgs.begin()) std::cout << " ";
			std::cout << *subArgs_iter;
		}
		if (subArgs.size() != 1) std::cout << ")";
	}
	std::cout << std::endl;
	std::list<std::string> retorno;
	return retorno;
}

template <typename T>
std::string numeroATexto(T numero) {
	std::stringstream ss;
	ss << numero;
	return ss.str();
}

std::list<std::string> suma(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	int valorFinal = 0;
	int aux;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = atoi((*subArgs_iter).c_str());
			valorFinal += aux;
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

std::list<std::string> resta(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	int valorFinal = 0;
	int aux;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = atoi((*subArgs_iter).c_str());
			if (args_iter == args.begin()) {
				valorFinal += aux;
			} else {
				valorFinal -= aux;
			}
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

std::list<std::string> producto(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	int valorFinal = 1;
	int aux;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = atoi((*subArgs_iter).c_str());
			valorFinal *= aux;
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

std::list<std::string> division(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	float valorFinal = 1;
	int aux;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			aux = std::atof((*subArgs_iter).c_str());
			if (args_iter == args.begin()) {
				valorFinal *= aux;
			} else {
				valorFinal /= aux;
			}
		}
	}
	std::string stringFinal;
	stringFinal = numeroATexto(valorFinal);
	retorno.push_back(stringFinal);
	return retorno;
}

std::list<std::string> mayor(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	std::list<std::string> aux;
	//primer numero
	std::string primero = args.front();
	args.pop_front();
	aux = interprete->procesarComandoLISP(primero);
	primero = aux.front();
	//segundo numero
	std::string segundo = args.front();
	aux = interprete->procesarComandoLISP(segundo);
	segundo = aux.front();

	float mayorFloat = std::atof(primero.c_str());
	float menorFloat = std::atof(segundo.c_str());

	if (mayorFloat > menorFloat) {
		std::string positivo = "1";
		retorno.push_front(positivo);
	}
	return retorno;
}

std::list<std::string> menor(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	std::list<std::string> aux;
	//primer numero
	std::string primero = args.front();
	args.pop_front();
	aux = interprete->procesarComandoLISP(primero);
	primero = aux.front();
	//segundo numero
	std::string segundo = args.front();
	aux = interprete->procesarComandoLISP(segundo);
	segundo = aux.front();

	float mayorFloat = std::atof(primero.c_str());
	float menorFloat = std::atof(segundo.c_str());

	if (mayorFloat < menorFloat) {
		std::string positivo = "1";
		retorno.push_front(positivo);
	}
	return retorno;
}

std::list<std::string> igual(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	std::list<std::string> aux;
	//primer numero
	std::string primero = args.front();
	args.pop_front();
	aux = interprete->procesarComandoLISP(primero);
	primero = aux.front();
	//segundo numero
	std::string segundo = args.front();
	aux = interprete->procesarComandoLISP(segundo);
	segundo = aux.front();

	float primeroFloat = std::atof(primero.c_str());
	float segundoFloat = std::atof(segundo.c_str());

	if (primeroFloat == segundoFloat) {
		std::string positivo = "1";
		retorno.push_front(positivo);
	}
	return retorno;
}

std::list<std::string> lista(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			retorno.push_back(*subArgs_iter);
		}
	}
	return retorno;
}

std::list<std::string> cdr(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			retorno.push_back(*subArgs_iter);
		}
	}
	if (!retorno.empty()) retorno.pop_front();
	return retorno;
}

std::list<std::string> car(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	std::string primerArgumento = args.front();
	std::list<std::string> primerArgumentoResuelto =
			interprete->procesarComandoLISP(primerArgumento);
	retorno.push_back(primerArgumentoResuelto.front());
	return retorno;
}

std::list<std::string> condicional(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::string argumentoRetornado;
	std::list<std::string> retorno;
	std::string primerArgumento = args.front();
	args.pop_front();
	std::list<std::string> argumentoResuelto =
			interprete->procesarComandoLISP(primerArgumento);
	if (argumentoResuelto.empty()) {
		args.pop_front();
	}
	primerArgumento = args.front();
	retorno = interprete->procesarComandoLISP(primerArgumento);
	return retorno;
}

std::list<std::string> setq(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::string nombreVariable;

	//el primer parametro no es algo evaluable
	nombreVariable = args.front();
	args.pop_front();

	std::string argumento = args.front();
	std::list<std::string> *valorVariable = new std::list<std::string>();
	*valorVariable = interprete->procesarComandoLISP(argumento);

	VariableLISP *variable = new VariableLISP(valorVariable);
	interprete->agregarVariable(nombreVariable, variable);

	std::list<std::string> retorno;
	return retorno;
}

std::list<std::string> defun(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::string nombreFuncion;
	std::string *cuerpoFuncion = new std::string();

	std::string argumento = args.front();
	args.pop_front();
	std::list<std::string> argumentoResuelto =
			interprete->procesarComandoLISP(argumento);
	nombreFuncion = argumentoResuelto.front();

	args.pop_front();

	*cuerpoFuncion = args.front();	//no puede ser algo que se evalue

	FuncionLISP *funcion = new FuncionUsuarioLISP(cuerpoFuncion);
	interprete->agregarFuncion(nombreFuncion, funcion);

	std::list<std::string> retorno;
	return retorno;
}

std::list<std::string> append(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	for(std::list<std::string>::iterator args_iter = args.begin();
	    args_iter != args.end(); args_iter++){
		std::list<std::string> subArgs =
				interprete->procesarComandoLISP(*args_iter);
		for (std::list<std::string>::iterator subArgs_iter = subArgs.begin();
				subArgs_iter != subArgs.end(); subArgs_iter++) {
			retorno.push_back(*subArgs_iter);
		}
	}
	return retorno;
}

std::list<std::string> sync(std::list<std::string> args,
		InterpreteLISP* interprete) {
	std::list<std::string> retorno;
	//solo con fines de cumplir con el ciclo, no hace nada
	return retorno;
}

AmbienteLISP::AmbienteLISP() {
	i = 0;
	j = 0;
	//agrego funciones nativas
	FuncionLISP* funcionPrint = new FuncionNativaLISP(&print);
	funcionesAmbiente["print"] = funcionPrint;
	FuncionLISP* funcionSuma = new FuncionNativaLISP(&suma);
	funcionesAmbiente["+"] = funcionSuma;
	FuncionLISP* funcionResta = new FuncionNativaLISP(&resta);
	funcionesAmbiente["-"] = funcionResta;
	FuncionLISP* funcionProducto = new FuncionNativaLISP(&producto);
	funcionesAmbiente["*"] = funcionProducto;
	FuncionLISP* funcionDivision = new FuncionNativaLISP(&division);
	funcionesAmbiente["/"] = funcionDivision;
	FuncionLISP* funcionMayor = new FuncionNativaLISP(&mayor);
	funcionesAmbiente[">"] = funcionMayor;
	FuncionLISP* funcionMenor = new FuncionNativaLISP(&menor);
	funcionesAmbiente["<"] = funcionMenor;
	FuncionLISP* funcionIgual = new FuncionNativaLISP(&igual);
	funcionesAmbiente["="] = funcionIgual;
	FuncionLISP* funcionLista = new FuncionNativaLISP(&lista);
	funcionesAmbiente["list"] = funcionLista;
	FuncionLISP* funcionCDR = new FuncionNativaLISP(&cdr);
	funcionesAmbiente["cdr"] = funcionCDR;
	FuncionLISP* funcionCAR = new FuncionNativaLISP(&car);
	funcionesAmbiente["car"] = funcionCAR;
	FuncionLISP* funcionIF = new FuncionNativaLISP(&condicional);
	funcionesAmbiente["if"] = funcionIF;
	FuncionLISP* funcionSetQ = new FuncionNativaLISP(&setq);
	funcionesAmbiente["setq"] = funcionSetQ;
	FuncionLISP* funcionDefun = new FuncionNativaLISP(&defun);
	funcionesAmbiente["defun"] = funcionDefun;
	FuncionLISP* funcionAppend = new FuncionNativaLISP(&append);
	funcionesAmbiente["append"] = funcionAppend;
	FuncionLISP* funcionSync = new FuncionNativaLISP(&sync);
	funcionesAmbiente["sync"] = funcionSync;
}

std::string AmbienteLISP::procesarLineaLISP(std::string linea) {
	InterpreteLISP* lineaLisp = new InterpreteLISP(linea,
			&variablesAmbiente, &funcionesAmbiente);
	if (!lineaLisp->lineaValida()) {
		delete lineaLisp;
		return linea;
	}
	lines.push_back(lineaLisp);
	if(lines[i]->esSync()) {
		while (j<i) {
			lines[j]->join();
			j++;
		}
	}
	lines[i]->start();
	i++;
	return LINE_OK;
}

AmbienteLISP::~AmbienteLISP() {
	for (int k = 0; k < i; k++) {
		lines[k]->join();
		delete lines[k];
	}
	for (std::map<std::string, FuncionLISP*>::iterator func_iter =
			funcionesAmbiente.begin(); func_iter != funcionesAmbiente.end();
			func_iter++) {
		delete ((*func_iter).second);
	}
	for (std::map<std::string, VariableLISP*>::iterator var_iter =
			variablesAmbiente.begin(); var_iter != variablesAmbiente.end();
			var_iter++) {
		delete ((*var_iter).second);
	}
}

