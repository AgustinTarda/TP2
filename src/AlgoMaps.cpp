/*
 * AlgoMaps.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */
//
#include "AlgoMaps.h"

AlgoMaps::AlgoMaps() {

	this->administradorDeRecorridos = new AdministradorDeRecorridos;

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

	std::string archivoSubte = "datos/bocas-de"
			"-subte.csv";
	lectora.leerEstacionesDeSubte(archivoSubte,
			this->administradorDeRecorridos);

	//std::string archivoGarajes = "datos/garajes-comerciales.csv";
	//lectora.leerGarajes(archivoGarajes, this->administradorDeRecorridos);

	//interfazDeUsuario.imprimirRecorridos(
	//administradorDeRecorridos.obtenerRecorridos());
}

void AlgoMaps::iniciarViaje() {
	interfazDeUsuario.mostrarMensajeDeBienvenida();

	//Coordenadas coordenadasDeInicio =
			//interfazDeUsuario.pedirCoordenadasDeInicio();
	//Coordenadas coordenadasDeDestino =
			//interfazDeUsuario.pedirCoordenadasDeDestino();

	Coordenadas coordenadasDeInicio(-34.6021056176248, -58.3840678491549);
	Coordenadas coordenadasDeDestino(-34.5952234173066, -58.4028219030811);

	Lista<Viaje*>* viajes = new Lista<Viaje*>;
	buscadorDeViajes.buscarViaje(coordenadasDeInicio, coordenadasDeDestino,
			*(this->administradorDeRecorridos), viajes);

	interfazDeUsuario.imprimirViajes( coordenadasDeInicio, coordenadasDeDestino, *(this -> administradorDeRecorridos), viajes);

	//interfazDeUsuario.imprimirViajes(viajes);

	while (!viajes->estaVacia()) {
			Viaje *viajeAEliminar = viajes->obtener(1);
			delete viajeAEliminar;
			viajes->remover(1);
		}
	delete viajes;

}

AlgoMaps::~AlgoMaps(){

	delete this->administradorDeRecorridos;
}
