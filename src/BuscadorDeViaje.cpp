/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"
BuscadorDeViaje::BuscadorDeViaje() {

}


void BuscadorDeViaje::buscarEstacionesCercanas(
		Lista<Estacion> &estacionesCercanasInicio,
		Lista<Estacion> &estacionesCercanasDestino,
		Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	Lista<Recorrido*> *recorridos;
	recorridos = administradorDeRecorridos.obtenerRecorridos();

	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor()) {
		Recorrido *recorridoActual = recorridos->obtenerCursor();

		Lista<Estacion*> *estacionesDelRecorrido;
		estacionesDelRecorrido = recorridoActual->obtenerEstaciones();
		buscarEstacionesCercanas(estacionesCercanasInicio,
				estacionesCercanasDestino, coordenadaInicial, coordenadaFinal,
				estacionesDelRecorrido);

	}
}

void BuscadorDeViaje::buscarEstacionesCercanas(
		Lista<Estacion> &estacionesCercanasInicio,
		Lista<Estacion> &estacionesCercanasDestino,
		Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
		Lista<Estacion*> *estacionesDelRecorrido) {
	while (estacionesDelRecorrido->avanzarCursor()) {
		Estacion *estacionActual = estacionesDelRecorrido->obtenerCursor();

		if (coordenadaInicial.calcularDistancia(
				estacionActual->obtenerCoordenadas()) < 300) {
			estacionesCercanasInicio.agregar(*estacionActual);

		}
		if (coordenadaFinal.calcularDistancia(
				estacionActual->obtenerCoordenadas()) < 300) {

			estacionesCercanasDestino.agregar(*estacionActual);

		}
	}

}

/*
 void BuscadorDeViaje::buscarCombinacionesPosibles(Coordenadas coordenadaInicial,
 Coordenadas coordenadaFinal, Lista<Estacion> estacionesCercanasInicio,
 Lista<Estacion> estacionesCercanasDestino,
 AdministradorDeRecorridos administradorDeRecorridos,
 Lista<Viaje> viajesPosibles) {

 Recorrido recorridoDeEstacionInicial;
 Recorrido recorridoDeEstacionFinal;
 Lista<Recorrido> recorridosFinales;
 Estacion estacionActualDeRecorridoInicial;
 Estacion estacionActualDeRecorridoFinal;

 estacionesCercanasInicio.iniciarCursor();
 while (estacionesCercanasInicio.avanzarCursor()) {

 Estacion estacionCercanaAInicio =
 estacionesCercanasInicio.obtenerCursor();
 recorridoDeEstacionInicial =
 administradorDeRecorridos.obtenerRecorridoAlQuePertenece(
 estacionCercanaAInicio);
 Lista<Estacion> estacionesDelRecorridoInicial;
 estacionesDelRecorridoInicial =
 recorridoDeEstacionInicial.obtenerEstaciones();

 estacionesDelRecorridoInicial.iniciarCursor();
 while (estacionesDelRecorridoInicial.avanzarCursor()) {

 Estacion estacionActualDeRecorridoInicial =
 estacionesDelRecorridoInicial.obtenerCursor();

 estacionesCercanasDestino.iniciarCursor();
 while (estacionesCercanasDestino.avanzarCursor()) {
 Estacion estacionCercanaADestino =
 estacionesCercanasDestino.obtenerCursor();
 recorridoDeEstacionFinal =
 administradorDeRecorridos.obtenerRecorridoAlQuePertenece(
 estacionCercanaADestino);
 Lista<Estacion> estacionesDelRecorridoFinal;
 estacionesDelRecorridoFinal =
 recorridoDeEstacionFinal.obtenerEstaciones();

 estacionesDelRecorridoFinal.iniciarCursor();
 while (estacionesDelRecorridoFinal.avanzarCursor()) {

 Estacion estacionActualDeRecorridoFinal =
 estacionesDelRecorridoFinal.obtenerCursor();

 Coordenadas coordenadasEstacionActualInicial =
 estacionActualDeRecorridoInicial.obtenerCoordenadas();
 unsigned int distanciaEntreCombinacion =
 coordenadasEstacionActualInicial.calcularDistancia(
 estacionActualDeRecorridoFinal.obtenerCoordenadas());
 if (distanciaEntreCombinacion < 300) {

 unsigned int distanciaACaminar =
 coordenadaInicial.calcularDistancia(
 estacionCercanaAInicio.obtenerCoordenadas())
 + coordenadaFinal.calcularDistancia(
 estacionCercanaADestino.obtenerCoordenadas())
 + distanciaEntreCombinacion;

 Viaje viajeActual(distanciaACaminar,
 estacionCercanaAInicio, estacionCercanaADestino,
 estacionActualDeRecorridoInicial,
 estacionActualDeRecorridoInicial);

 viajesPosibles.agregar(viajeActual);
 }
 }
 }
 }
 }
 }
 */

void BuscadorDeViaje::buscarViajesDirectosPosibles(
		Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
		Lista<Estacion> estacionesCercanasInicio,
		Lista<Estacion> estacionesCercanasDestino,
		Lista<Viaje> &viajesPosibles) {

	estacionesCercanasInicio.iniciarCursor();
	estacionesCercanasDestino.iniciarCursor();

	while (estacionesCercanasInicio.avanzarCursor()) {
		Estacion estacionCercanaAInicio =
				estacionesCercanasInicio.obtenerCursor();

		while (estacionesCercanasDestino.avanzarCursor()) {

			Estacion estacionCercanaADestino =
					estacionesCercanasDestino.obtenerCursor();

			if (estacionCercanaAInicio.obtenerLinea()
					== estacionCercanaADestino.obtenerLinea()) {

				unsigned int distanciaACaminar =
						coordenadaInicial.calcularDistancia(
								estacionCercanaAInicio.obtenerCoordenadas())
								+ coordenadaFinal.calcularDistancia(
										estacionCercanaADestino.obtenerCoordenadas());
				Viaje viajeActual(distanciaACaminar, estacionCercanaAInicio,
						estacionCercanaADestino);
				;

				viajesPosibles.agregar(viajeActual);
			}
		}
	}
}

