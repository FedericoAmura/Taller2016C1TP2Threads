/*
 * numeroATexto.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include <sstream>
#include <string>

//Funcion para convertir un tipo de dato generico a string
template <typename T>
std::string numeroATexto(T numero) {
	std::stringstream ss;
	ss << numero;
	return ss.str();
}
