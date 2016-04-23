/*
 * numeroATexto.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: freddy
 */

#include <sstream>

template <typename T>
std::string numeroATexto(T numero) {
	std::stringstream ss;
	ss << numero;
	return ss.str();
}
