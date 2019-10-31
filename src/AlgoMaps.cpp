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
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus,
			this->administradorDeRecorridos);

	std::string archivoDeFerrocarril = "datos/estaciones-de-ferrocarril.csv";
	lectora.leerEstacionesDeFerrocarril(archivoDeFerrocarril,
			this->administradorDeRecorridos);

	std::string archivoColectivos = "datos/paradas-de-colectivo.csv";
	lectora.leerEstacionesDeColectivo(archivoColectivos,
			this->administradorDeRecorridos);

	std::string archivoSubte = "datos/bocas-de-subte.csv";
	lectora.leerEstacionesDeSubte(archivoSubte,
			this->administradorDeRecorridos);

	//std::string archivoGarajes = "datos/garajes-comerciales.csv";
	//lectora.leerGarajes(archivoGarajes, this->administradorDeRecorridos);

	interfazDeUsuario.imprimirRecorridos(
			administradorDeRecorridos.obtenerRecorridos());
}

void AlgoMaps::iniciarViaje() {

	/*Coordenadas coordenadasDeInicio =
	 interfazDeUsuario.pedirCoordenadasDeInicio();
	 Coordenadas coordenadasDeDestino =
	 interfazDeUsuario.pedirCoordenadasDeDestino();*/

	Coordenadas coordenadasDeInicio(-34.6021056176248, -58.3840678491549);
	Coordenadas coordenadasDeDestino(-34.5952234173066, -58.4028219030811);

	std::cout << coordenadasDeInicio.calcularDistancia(coordenadasDeDestino)
			<< std::endl;

	int numeroDeViajes = buscadorDeViajes.buscarViaje(coordenadasDeInicio,
			coordenadasDeDestino, administradorDeRecorridos);
	std::cout << "Numero de viajes: " << numeroDeViajes << std::endl;
}
