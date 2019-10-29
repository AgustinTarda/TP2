/*
 * AlgoMaps.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include "AlgoMaps.h"

AlgoMaps::AlgoMaps() {

	LectoraDeArchivos lectora;
	std::string archivoDeMetrobus = "datos/estaciones-de-metrobus.csv";
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus, estacionesDeMetrobus);

	estacionesDeMetrobus.iniciarCursor();
	while (estacionesDeMetrobus.avanzarCursor()) {
		EstacionMetrobus estacionDeMetrobus(
				estacionesDeMetrobus.obtenerCursor());
		interfazDeUsuario.mostrarEstacionDeMetrobus(estacionDeMetrobus);
	}
	std::string archivoDeColectivos = "datos/paradas-de-colectivo.csv";
	lectora.leerEstacionesDeColectivo(archivoDeColectivos,
			estacionesDeColectivo);
	estacionesDeColectivo.iniciarCursor();
	while (estacionesDeColectivo.avanzarCursor()) {
		EstacionColectivo estacionDeColectivo(
				estacionesDeColectivo.obtenerCursor());
		interfazDeUsuario.mostrarEstacionDeColectivo(estacionDeColectivo);
	}

}
