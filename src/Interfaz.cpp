/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"

void Interfaz::mostrarParada(Parada parada) {

	std::cout << "MetroBus: " << parada.obtenerLinea() << std::endl;

}
