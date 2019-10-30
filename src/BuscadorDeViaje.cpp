/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"

BuscadorDeViaje::BuscadorDeViaje(Coordenadas coordenadaInicial,
		Coordenadas coordenadaFinal, Lista<Estacion> *estaciones) {

	Lista<Estacion> estacionesCercanasInicio;
	Lista<Estacion> estacionesCercanasDestino;
	Lista<Estacion> viajesPosibles;

	buscarEstacionesCercanas(estacionesCercanasInicio,
			estacionesCercanasDestino, coordenadaInicial, coordenadaFinal,
			estaciones);

	if ((!estacionesCercanasInicio.estaVacia())
			&& (!estacionesCercanasDestino.estaVacia())) {

		buscarViajesDirectosPosibles(estacionesCercanasInicio,
				estacionesCercanasDestino, viajesPosibles);

		if (!viajesPosibles.estaVacia()) {
			//Mostramos este viaje
		}

		buscarCombinacionesPosibles(estacionesCercanasInicio,
				estacionesCercanasDestino);

	} else {

		//Si no hay estaciones cerca del destino y/o final, mostramos el camino caminando

	}

}

void BuscadorDeViaje::buscarCombinacionesPosibles(
		Lista<Estacion> estacionesCercanasInicio,
		Lista<Estacion> estacionesCercanasDestino) {

	/*
	 Lista<Recorridos> recorridos;
	 Lista<Estacion> combinacionestaciones;
	 Estacion estacionActualDeRecorridoInicial;
	 Estacion estacionActualDeRecorridoFinal;buscarestacionesCercanas


	 estacionesCercanasInicio.iniciarCursor();
	 while (estacionesCercanasInicio.avanzarCursor()) {

	 Parada paradaCercanaAInicio = estacionesCercanasInicio.obtenerCursor();

	 recorridos.iniciarCursor();
	 bool lineaDeInicioEncontrada = false;
	 while (recorridos.avanzarCursor() && !lineaDeInicioEncontrada) {

	 Recorridos recorridoInicialActual = recorridos.obtenerCursor();
	 if (recorridoInicialActual.obtenerLinea()== paradaCercanaAInicio.obtenerLinea()) {
	 lineaDeInicioEncontrada = true;

	 recorridoInicialActual.estaciones.iniciarCursor();
	 while (recorridoInicialActual.estaciones.avanzarCursor()) {
	 paradaActualDeRecorridoInicial = recorridoInicialActual.estaciones.obtenerCursor();

	 estacionesCercanasDestino.iniciarCursor();
	 while (estacionesCercanasDestino.avanzarCursor()) {
	 Parada paradaCercanaADestino = estacionesCercanasDestino.obtenerCursor();

	 recorridos.iniciarCursor();
	 bool lineaDeDestinoEncontrada = false;
	 while (recorridos.avanzarCursor() && !lineaDeDestinoEncontrada) {
	 Recorridos recorridoFinalActual = recorridos.obtenerCursor();
	 if (recorridoFinalActual.obtenerLinea() == paradaCercanaADestino.obtenerLinea()) {

	 lineaDeDestinoEncontrada = true;
	 recorridoFinalActual.estaciones.iniciarCursor();
	 while (recorridoActual.estaciones.avanzarCursor()) {
	 paradaActualDeRecorridoFinal = recorridoActual.estaciones.obtenerCursor();
	 if (paradaActualDeRecorridoInicial.coordenadas.calcularDistancia(paradaActualDeRecorridoFinal.obtenerCoordenadas()) < 300) {
	 //ES UNA COMBINACION, GUARDAMOS LA PARADA INICIAL, LAS 2 estaciones DE TRANSBORDO Y LA FINAL?
	 }
	 }
	 }
	 }
	 }
	 }
	 }
	 }
	 }
	 */
}

void BuscadorDeViaje::buscarEstacionesCercanas(
		Lista<Estacion> estacionesCercanasInicio,
		Lista<Estacion> estacionesCercanasDestino,
		Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
		Lista<Estacion> *estaciones) {
	estaciones->iniciarCursor();
	while (estaciones->avanzarCursor()) {
		Estacion estacionActual = estaciones->obtenerCursor();

		if (coordenadaInicial.calcularDistancia(
				estacionActual.obtenerCoordenadas()) < 300) {
			estacionesCercanasInicio.agregar(estacionActual);

		} else if (coordenadaFinal.calcularDistancia(
				estacionActual.obtenerCoordenadas()) < 300) {

			estacionesCercanasDestino.agregar(estacionActual);

		}
	}
}

void BuscadorDeViaje::buscarViajesDirectosPosibles(
		Lista<Estacion> estacionesCercanasInicio,
		Lista<Estacion> estacionesCercanasDestino,
		Lista<Estacion> viajesPosibles) {

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
				viajesPosibles.agregar(estacionCercanaAInicio);
				viajesPosibles.agregar(estacionCercanaADestino);
			}
		}
	}
}

