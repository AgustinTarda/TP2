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
	std::string archivoDeFerrocarril = "datos/estaciones-de-ferrocarril.csv";
	std::string archivoColectivos = "datos/paradas-de-colectivo.csv";
	std::string archivoSubte = "datos/bocas-de-subte.csv";
	std::string archivoGarajes = "datos/garajes-comerciales.csv";
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus, paradas);
	lectora.leerEstacionesDeFerrocarril(archivoDeFerrocarril, paradas);
	lectora.leerEstacionesDeColectivo(archivoColectivos, paradas);
	lectora.leerEstacionesDeSubte(archivoSubte, paradas);
	lectora.leerGarajes(archivoGarajes, paradas);

	paradas.iniciarCursor();
	while (paradas.avanzarCursor()) {
		interfazDeUsuario.mostrarParada(paradas.obtenerCursor());
	}

	std::cout<<paradas.contarElementos();

}
