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
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus,
			this->administradorDeRecorridos);
	lectora.leerEstacionesDeFerrocarril(archivoDeFerrocarril,
			this->administradorDeRecorridos);
	lectora.leerEstacionesDeColectivo(archivoColectivos,
			this->administradorDeRecorridos);
	lectora.leerEstacionesDeSubte(archivoSubte,
			this->administradorDeRecorridos);
	lectora.leerGarajes(archivoGarajes, this->administradorDeRecorridos);
}

void AlgoMaps::iniciarViaje() {
	interfazDeUsuario.mostrarMensajeDeBienvenida();
	Coordenadas coordenadasDeInicio = interfazDeUsuario.pedirCoordenadasDeInicio();
	Coordenadas coordenadasDeDestino = interfazDeUsuario.pedirCoordenadasDeDestino();

	int largoLista = buscadorDeViajes.buscarViaje(coordenadasDeInicio, coordenadasDeDestino, administradorDeRecorridos);
	interfazDeUsuario.mostrarLargoListaViajes(largoLista);
}
