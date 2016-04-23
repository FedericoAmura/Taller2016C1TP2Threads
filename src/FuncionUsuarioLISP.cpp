/*
 * FuncionUsuarioLISP.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: freddy
 */

#include "FuncionUsuarioLISP.h"
#include <string>
#include <vector>

FuncionUsuarioLISP::FuncionUsuarioLISP(const std::string codigo) : codigo(codigo) {
}

std::string FuncionUsuarioLISP::reemplazarAmbiente(std::string ambiente) {
	std::string nuevoCodigo = codigo;
	size_t index = 0;
	while (true) {
		index = nuevoCodigo.find("ENV", index);
		if (index == std::string::npos) break;

		nuevoCodigo.erase(index, 3);	//saco el ENV
		nuevoCodigo.insert(index, ambiente);	//pongo el ambiente
		index++;	//para evitar ciclo infinito si nos hacen ambiente=ENV
	}
	return nuevoCodigo;
}

std::vector<std::string> FuncionUsuarioLISP::resolver(
		std::vector<std::string> args,
		InterpreteLISP* interprete) {
	std::vector<std::string> lista;
	std::string ambiente = args.front();
	std::string nuevoCodigo = FuncionUsuarioLISP::reemplazarAmbiente(ambiente);
	lista = interprete->procesarComandoLISP(nuevoCodigo);
	return lista;
}

FuncionUsuarioLISP::~FuncionUsuarioLISP() {
}

