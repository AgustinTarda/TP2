/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"

BuscadorDeViaje::BuscadorDeViaje(Coordenadas coordenadaInicial,
		Coordenadas coordenadaFinal, Lista<Parada> * paradas) {

	Lista<Parada> paradasCercanasInicio;
	Lista<Parada> paradasCercanasDestino;
	Lista<Parada> viajesPosibles;

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

void BuscadorDeViaje::buscarCombinaciones(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino){

	Lista<Parada> combinacionParadas;
	//paradasCercanasInicio-> iniciarCursor();
	while(paradasCercanasInicio.avanzarCursor()){

	}

}

void BuscadorDeViaje::buscarParadasCercanas(Lista<Parada> paradasCercanasInicio,
		Lista<Parada> paradasCercanasDestino, Coordenadas coordenadaInicial,
		Coordenadas coordenadaFinal, Lista<Parada>* paradas) {
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

void BuscadorDeViaje::buscarViajesPosibles(Lista<Parada> paradasCercanasInicio,
		Lista<Parada> paradasCercanasDestino, Lista<Parada> viajesPosibles) {
	paradasCercanasInicio.iniciarCursor();
	paradasCercanasDestino.iniciarCursor();

	while (paradasCercanasInicio.avanzarCursor()) {
		Parada paradaCercanaAInicio = paradasCercanasInicio.obtenerCursor();

		while (paradasCercanasDestino.avanzarCursor()) {
			Parada paradaCercanaADestino =
					paradasCercanasDestino.obtenerCursor();
			if (paradaCercanaAInicio.obtenerLinea() == paradaCercanaADestino.obtenerLinea()) {
				viajesPosibles.agregar(paradaCercanaAInicio);
				viajesPosibles.agregar(paradaCercanaADestino);
			}
		}
	}
}

