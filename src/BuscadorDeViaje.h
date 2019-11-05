/*
 * BuscadorDeViaje.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */
//
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
	int distanciaMaximaACaminar = 300;
public:
	BuscadorDeViaje();

	/*
	 * pre: recibe las coordenadas, el administrador de recorridos y una lista de viajes vacia.
	 * post: busca un viaje directo y un viaje con combinacion simple y los agrega a la lista viajes.
	 */
	void buscarViaje(Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos &administradorDeRecorridos,
			Lista<Viaje> &viajes);

	/*
	 * pre: recibe las coordenadas, las estaciones cercanas al inicio y al destino, el administrador de recorridos
	 *  y una lista de viajes vacia.
	 *  post: busca si hay combinaciones posibles entre las coordenadas dadas, y si hay las agrega a la lista de viajes.
	 */
	void buscarCombinacionesPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			AdministradorDeRecorridos &administradorDeRecorridos,
			Lista<Viaje> &viajesPosibles);

	/*
	 * pre: recibe las estaciones cercanas al inicio y al destino, las coordenadas y el administrador de recorridos.
	 * post: busca estaciones cercanas chequeando cada recorrido del administrador de recorridos.
	 */
	void buscarEstacionesCercanas(Lista<Estacion> &estacionesCercanasInicio,
			Lista<Estacion> &estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos &administradorDeRecorridos);

	/*
	 * pre: recibe las estaciones cercanas al inicio y al destino, las coordenadas inicial y final,
	 * y una lista con todas las estaciones del recorrido.
	 * post: busca estaciones cercanas y las agrega a estaciones del recorrido.
	 */
	void buscarEstacionesCercanas(Lista<Estacion> &estacionesCercanasInicio,
			Lista<Estacion> &estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			Lista<Estacion*> *estacionesDelRecorrido);

	/*
	 * pre: recibe las coordenadas iniciales y finales, las estaciones cercanas al inicio y al destino,
	 * y una lista de viajes posibles vacia.
	 * post: busca si hay viajes directos entre las dos coordenadas, y si hay las agrega a la lista de viajes posibles.
	 */
	void buscarViajesDirectosPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Lista<Viaje> &viajesPosibles);

};

#endif /* SRC_BUSCADORDEVIAJE_H_ */
