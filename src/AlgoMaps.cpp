/*
 * AlgoMaps.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */
//
#include "AlgoMaps.h"
using namespace std;

AlgoMaps::AlgoMaps() {

	this->administradorDeRecorridos = new AdministradorDeRecorridos;

	LectoraDeArchivos lectora;

	string archivoDeMetrobus = "datos/estaciones-de-metrobus.csv";
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus,
			this->administradorDeRecorridos);

	string archivoDeFerrocarril = "datos/estaciones-de-ferrocarril.csv";
	lectora.leerEstacionesDeFerrocarril(archivoDeFerrocarril,
			this->administradorDeRecorridos);

	string archivoColectivos = "datos/paradas-de-colectivo.csv";
	lectora.leerEstacionesDeColectivo(archivoColectivos,
			this->administradorDeRecorridos);

	string archivoSubte = "datos/bocas-de"
			"-subte.csv";
	lectora.leerEstacionesDeSubte(archivoSubte,
			this->administradorDeRecorridos);

	//string archivoGarajes = "datos/garajes-comerciales.csv";
	//lectora.leerGarajes(archivoGarajes, this->administradorDeRecorridos);

	//interfazDeUsuario.imprimirRecorridos(
	//administradorDeRecorridos.obtenerRecorridos());
}

void AlgoMaps::iniciarViaje() {
	interfazDeUsuario.mostrarMensajeDeBienvenida();

	Coordenadas coordenadasDeInicio =
	interfazDeUsuario.pedirCoordenadasDeInicio();
	Coordenadas coordenadasDeDestino =
	interfazDeUsuario.pedirCoordenadasDeDestino();

	//Coordenadas de prueba
	/*Coordenadas coordenadasDeInicio(-34.635670, -58.453803);
	Coordenadas coordenadasDeDestino(-34.617654, -58.369460);*/

	Lista<Viaje*> *viajes = new Lista<Viaje*>;
	buscadorDeViajes.buscarViaje(coordenadasDeInicio, coordenadasDeDestino,
			*(this->administradorDeRecorridos), viajes);
	if (!viajes->estaVacia()) {

		Lista<Viaje*> *mejoresViajes = new Lista<Viaje*>;
		mejoresViajes = filtrarMejoresViajes(viajes);

		interfazDeUsuario.imprimirViajes(coordenadasDeInicio,
				coordenadasDeDestino, this->administradorDeRecorridos,
				mejoresViajes);
	} else {
		interfazDeUsuario.noSeEncontroViajesPosibles();
	}

	while (!viajes->estaVacia()) {
		Viaje *viajeAEliminar = viajes->obtener(1);
		delete viajeAEliminar;
		viajes->remover(1);
	}
	delete viajes;

}
Lista<Viaje*>* AlgoMaps::filtrarMejoresViajes(Lista<Viaje*> *viajesARevisar) {

	Viaje *mejorViajeDirecto = calcularMejorViajeDe(Viaje::DIRECTO,
			viajesARevisar);
	Viaje *mejorViajeConCombinacion = calcularMejorViajeDe(
			Viaje::COMBINACION_SIMPLE, viajesARevisar);

	Lista<Viaje*> *mejoresViajes = new Lista<Viaje*>;

	if (mejorViajeDirecto != NULL) {
		mejoresViajes->agregar(mejorViajeDirecto);
	}
	if (mejorViajeConCombinacion != NULL) {

		mejoresViajes->agregar(mejorViajeConCombinacion);
	}

	return mejoresViajes;

}

Viaje* AlgoMaps::calcularMejorViajeDe(Viaje::TipoDeViaje tipoDeViaje,
		Lista<Viaje*> *viajes) {

	bool seEncontroPrimerViaje = false;
	double minimaDistanciaViaje;
	Viaje *mejorViaje;
	Viaje *viajeAAnalizar;

	viajes->iniciarCursor();
	while (viajes->avanzarCursor()) {
		viajeAAnalizar = viajes->obtenerCursor();

		if (viajeAAnalizar->obtenerTipoDeViaje() == tipoDeViaje
				&& !seEncontroPrimerViaje) {
			mejorViaje = viajeAAnalizar;
			minimaDistanciaViaje = mejorViaje->calcularDistaciaTotalACaminar();
			seEncontroPrimerViaje = true;
		} else if (viajeAAnalizar->obtenerTipoDeViaje() == tipoDeViaje
				&& minimaDistanciaViaje
						> viajeAAnalizar->calcularDistaciaTotalACaminar()) {
			mejorViaje = viajeAAnalizar;
			minimaDistanciaViaje =
					viajeAAnalizar->calcularDistaciaTotalACaminar();
		}

	}
	return mejorViaje;
}

AlgoMaps::~AlgoMaps() {

	delete this->administradorDeRecorridos;
}
