/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"

BuscadorDeViaje::BuscadorDeViaje(Coordenadas coordenadaInicial, Coordenadas coordenadaFinal, Lista<Parada> * paradas) {

	Lista<Parada> paradasCercanasInicio;
	Lista<Parada> paradasCercanasDestino;
	Lista<Parada> viajesPosibles;

	buscarParadasCercanas(paradasCercanasInicio, paradasCercanasDestino, coordenadaInicial, coordenadaFinal, paradas);

	if ((!paradasCercanasInicio.estaVacia()) && (!paradasCercanasDestino.estaVacia())) {

		buscarViajesDirectosPosibles(paradasCercanasInicio, paradasCercanasDestino,
				viajesPosibles);

		if (!viajesPosibles.estaVacia()) {
			//Mostramos este viaje
		}

		buscarCombinacionesPosibles(paradasCercanasInicio, paradasCercanasDestino);

	} else {

		//Si no hay paradas cerca del destino y/o final, mostramos el camino caminando

	}

}

void BuscadorDeViaje::buscarCombinacionesPosibles(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino){

	/*
	Lista<Recorridos> recorridos;
	Lista<Parada> combinacionParadas;
	Parada paradaActualDeRecorridoInicial;
	Parada paradaActualDeRecorridoFinal;

	paradasCercanasInicio.iniciarCursor();
	while (paradasCercanasInicio.avanzarCursor()) {

		Parada paradaCercanaAInicio = paradasCercanasInicio.obtenerCursor();

		recorridos.iniciarCursor();
		bool lineaDeInicioEncontrada = false;
		while (recorridos.avanzarCursor() && !lineaDeInicioEncontrada) {

			Recorridos recorridoInicialActual = recorridos.obtenerCursor();
			if (recorridoInicialActual.obtenerLinea()== paradaCercanaAInicio.obtenerLinea()) {
				lineaDeInicioEncontrada = true;

				recorridoInicialActual.paradas.iniciarCursor();
				while (recorridoInicialActual.paradas.avanzarCursor()) {
					paradaActualDeRecorridoInicial = recorridoInicialActual.paradas.obtenerCursor();

					paradasCercanasDestino.iniciarCursor();
					while (paradasCercanasDestino.avanzarCursor()) {
						Parada paradaCercanaADestino = paradasCercanasDestino.obtenerCursor();

						recorridos.iniciarCursor();
						bool lineaDeDestinoEncontrada = false;
						while (recorridos.avanzarCursor() && !lineaDeDestinoEncontrada) {
							Recorridos recorridoFinalActual = recorridos.obtenerCursor();
							if (recorridoFinalActual.obtenerLinea() == paradaCercanaADestino.obtenerLinea()) {

								lineaDeDestinoEncontrada = true;
								recorridoFinalActual.paradas.iniciarCursor();
								while (recorridoActual.paradas.avanzarCursor()) {
									paradaActualDeRecorridoFinal = recorridoActual.paradas.obtenerCursor();
									if (paradaActualDeRecorridoInicial.coordenadas.calcularDistancia(paradaActualDeRecorridoFinal.obtenerCoordenadas()) < 300) {
										//ES UNA COMBINACION, GUARDAMOS LA PARADA INICIAL, LAS 2 PARADAS DE TRANSBORDO Y LA FINAL?
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

void BuscadorDeViaje::buscarParadasCercanas(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino, Coordenadas coordenadaInicial, Coordenadas coordenadaFinal, Lista<Parada>* paradas) {
	paradas->iniciarCursor();
	while (paradas->avanzarCursor()) {
		Parada paradaActual = paradas->obtenerCursor();

		if (coordenadaInicial.calcularDistancia(paradaActual.obtenerCoordenadas())< 300) {
			paradasCercanasInicio.agregar(paradaActual);

		} else if (coordenadaFinal.calcularDistancia(paradaActual.obtenerCoordenadas())
				< 300) {

			paradasCercanasDestino.agregar(paradaActual);

		}
	}
}

void BuscadorDeViaje::buscarViajesDirectosPosibles(Lista<Parada> paradasCercanasInicio,
		Lista<Parada> paradasCercanasDestino, Lista<Parada> viajesPosibles) {
	paradasCercanasInicio.iniciarCursor();
	paradasCercanasDestino.iniciarCursor();

	while (paradasCercanasInicio.avanzarCursor()) {
		Parada paradaCercanaAInicio = paradasCercanasInicio.obtenerCursor();

		while (paradasCercanasDestino.avanzarCursor()) {
			Parada paradaCercanaADestino = paradasCercanasDestino.obtenerCursor();
			if (paradaCercanaAInicio.obtenerLinea() == paradaCercanaADestino.obtenerLinea()) {
				viajesPosibles.agregar(paradaCercanaAInicio);
				viajesPosibles.agregar(paradaCercanaADestino);
			}
		}
	}
}

