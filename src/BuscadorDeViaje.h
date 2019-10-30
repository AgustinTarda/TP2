/*
 * BuscadorDeViaje.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#ifndef SRC_BUSCADORDEVIAJE_H_
#define SRC_BUSCADORDEVIAJE_H_

#include <string>
#include "Coordenadas.h"
#include "Estacion.h"
#include "Lista.h"

class BuscadorDeViaje {

	BuscadorDeViaje(Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			Lista<Estacion> *estaciones);

	void buscarCombinacionesPosibles(Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino);

	void buscarEstacionesCercanas(Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			Lista<Estacion> *estaciones);

	void buscarViajesDirectosPosibles(Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Lista<Estacion> viajesPosibles);

};

#endif /* SRC_BUSCADORDEVIAJE_H_ */
