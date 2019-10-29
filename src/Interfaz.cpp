/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"

void Interfaz::mostrarEstacionDeMetrobus(EstacionMetrobus estacionDeMetrobus) {

	std::cout << "MetroBus: " << estacionDeMetrobus.obtenerNombre()
			<< std::endl;

}
void Interfaz::mostrarEstacionDeColectivo(
		EstacionColectivo estacionDeColectivo) {

	std::cout << "Colectivo: " << estacionDeColectivo.obtenerNombre()
			<< std::endl;

}
