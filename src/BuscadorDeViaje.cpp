/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"

BuscadorDeViaje::BuscadorDeViaje(Coordenadas coordenadaInicial,
		Coordenadas coordenadaFinal, Lista<Estacion> * paradas) {

	Lista<Estacion> paradasCercanasInicio;
	Lista<Estacion> paradasCercanasDestino;
	Lista<Estacion> viajesPosibles;

	buscarParadasCercanas(paradasCercanasInicio, paradasCercanasDestino,
			coordenadaInicial, coordenadaFinal, paradas);

	if ((!paradasCercanasInicio.estaVacia()) && (!paradasCercanasDestino.estaVacia())) {
		buscarViajesPosibles(paradasCercanasInicio, paradasCercanasDestino,
				viajesPosibles);

		if (!viajesPosibles.estaVacia()) {
			//Mostramos este viaje
		}

		buscarCombinaciones(paradasCercanasInicio, paradasCercanasDestino);

	} else {

		//Si no hay paradas cerca del destino y/o final, mostramos el camino caminando
//Lista de linea con su transporte, y una lista de Paradas, con calles y coordenadas

	}

}

void BuscadorDeViaje::buscarCombinaciones(Lista<Estacion> paradasCercanasInicio, Lista<Estacion> paradasCercanasDestino){

	Lista<Estacion> combinacionParadas;
	//paradasCercanasInicio-> iniciarCursor();
	while(paradasCercanasInicio.avanzarCursor()){

	}

}

void BuscadorDeViaje::buscarParadasCercanas(Lista<Estacion> paradasCercanasInicio,
		Lista<Estacion> paradasCercanasDestino, Coordenadas coordenadaInicial,
		Coordenadas coordenadaFinal, Lista<Estacion>* paradas) {
	paradas->iniciarCursor();
	while (paradas->avanzarCursor()) {
		Estacion paradaActual = paradas->obtenerCursor();

		if (coordenadaInicial.calcularDistancia(paradaActual.obtenerCoordenadas())< 300) {
			paradasCercanasInicio.agregar(paradaActual);

		} else if (coordenadaFinal.calcularDistancia(paradaActual.obtenerCoordenadas())
				< 300) {

			paradasCercanasDestino.agregar(paradaActual);

		}
	}
}

void BuscadorDeViaje::buscarViajesPosibles(Lista<Estacion> paradasCercanasInicio,
		Lista<Estacion> paradasCercanasDestino, Lista<Estacion> viajesPosibles) {
	paradasCercanasInicio.iniciarCursor();
	paradasCercanasDestino.iniciarCursor();

	while (paradasCercanasInicio.avanzarCursor()) {
		Estacion paradaCercanaAInicio = paradasCercanasInicio.obtenerCursor();

		while (paradasCercanasDestino.avanzarCursor()) {
			Estacion paradaCercanaADestino =
					paradasCercanasDestino.obtenerCursor();
			if (paradaCercanaAInicio.obtenerLinea() == paradaCercanaADestino.obtenerLinea()) {
				viajesPosibles.agregar(paradaCercanaAInicio);
				viajesPosibles.agregar(paradaCercanaADestino);
			}
		}
	}
}

