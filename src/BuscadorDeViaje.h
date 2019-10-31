/*
 * BuscadorDeViaje.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#ifndef SRC_BUSCADORDEVIAJE_H_
#define SRC_BUSCADORDEVIAJE_H_

#include <string>
#include <iostream>
#include "Coordenadas.h"
#include "Estacion.h"
#include "Lista.h"
#include "AdministradorDeRecorridos.h"
#include "Recorrido.h"
#include "Viaje.h"

class BuscadorDeViaje {
private:
public:
	BuscadorDeViaje();

	void buscarViaje(Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos &administradorDeRecorridos,
			Lista<Viaje> &viajes);

	void buscarCombinacionesPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			AdministradorDeRecorridos &administradorDeRecorridos,
			Lista<Viaje> &viajesPosibles);

	void buscarEstacionesCercanas(Lista<Estacion> &estacionesCercanasInicio,
			Lista<Estacion> &estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos &administradorDeRecorridos);
	void buscarEstacionesCercanas(Lista<Estacion> &estacionesCercanasInicio,
			Lista<Estacion> &estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			Lista<Estacion*> *estacionesDelRecorrido);

	void buscarViajesDirectosPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Lista<Viaje> &viajesPosibles);
};

#endif /* SRC_BUSCADORDEVIAJE_H_ */
