/*
 * LispEnvironment.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "AmbienteLISP.h"
#include "FuncionAppendLISP.h"
#include "FuncionCarLISP.h"
#include "FuncionCdrLISP.h"
#include "FuncionCondicionalLISP.h"
#include "FuncionDefunLISP.h"
#include "FuncionDivisionLISP.h"
#include "FuncionIgualLISP.h"
#include "FuncionListaLISP.h"
#include "FuncionMayorLISP.h"
#include "FuncionMenorLISP.h"
#include "FuncionPrintLISP.h"
#include "FuncionProductoLISP.h"
#include "FuncionRestaLISP.h"
#include "FuncionSetqLISP.h"
#include "FuncionSumaLISP.h"
#include "FuncionSyncLISP.h"

#include <string>
#include <vector>
#include <map>

AmbienteLISP::AmbienteLISP() {
	i = 0;
	j = 0;
	//agrego funciones nativas
	funcionesAmbiente["+"] = (FuncionLISP*) new FuncionSumaLISP();
	funcionesAmbiente["-"] = (FuncionLISP*) new FuncionRestaLISP();
	funcionesAmbiente["*"] = (FuncionLISP*) new FuncionProductoLISP();
	funcionesAmbiente["/"] = (FuncionLISP*) new FuncionDivisionLISP();
	funcionesAmbiente["="] = (FuncionLISP*) new FuncionIgualLISP();
	funcionesAmbiente[">"] = (FuncionLISP*) new FuncionMayorLISP();
	funcionesAmbiente["<"] = (FuncionLISP*) new FuncionMenorLISP();
	funcionesAmbiente["append"] = (FuncionLISP*) new FuncionAppendLISP();
	funcionesAmbiente["defun"] = (FuncionLISP*) new FuncionDefunLISP();
	funcionesAmbiente["car"] = (FuncionLISP*) new FuncionCarLISP();
	funcionesAmbiente["cdr"] = (FuncionLISP*) new FuncionCdrLISP();
	funcionesAmbiente["if"] = (FuncionLISP*) new FuncionCondicionalLISP();
	funcionesAmbiente["list"] = (FuncionLISP*) new FuncionListaLISP();
	funcionesAmbiente["print"] = (FuncionLISP*) new FuncionPrintLISP();
	funcionesAmbiente["setq"] = (FuncionLISP*) new FuncionSetqLISP();
	funcionesAmbiente["sync"] = (FuncionLISP*) new FuncionSyncLISP();
}

std::string AmbienteLISP::procesarLineaLISP(const std::string linea) {
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

