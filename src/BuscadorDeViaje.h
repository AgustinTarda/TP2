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
#include "Grafo.h"

static const int DISTANCIA_MAXIMA_A_CAMINAR = 200;

class BuscadorDeViaje {
private:

public:
	BuscadorDeViaje();

	/*
	 * pre: recibe las coordenadas, el administrador de recorridos y una lista de viajes vacia.
	 * post: busca un viaje directo y un viaje con combinacion simple y los agrega a la lista viajes.
	 */
	void buscarViaje(Coordenadas *coordenadaInicial,
			Coordenadas *coordenadaFinal,
			AdministradorDeRecorridos *administradorDeRecorridos,
			Lista<Viaje*> *viajes);

	/*
	 * pre: recibe las coordenadas, las estaciones cercanas al inicio y al destino, el administrador de recorridos
	 *  y una lista de viajes vacia.
	 *  post: busca si hay combinaciones posibles entre las coordenadas dadas, y si hay las agrega a la lista de viajes.
	 */
	void buscarCombinacionesPosibles(Coordenadas *coordenadaInicial,
			Coordenadas *coordenadaFinal,
			Lista<Estacion*> *estacionesCercanasInicio,
			Lista<Estacion*> *estacionesCercanasDestino,
			AdministradorDeRecorridos *administradorDeRecorridos,
			Lista<Viaje*> *viajesPosibles);
	/*
	 *  post: analiza si posibleViajeConCombinacion tiene alguna combinacion con los
	 *  recorridos de las estaciones estacionesCercanasDestino
	 */
	void analizarSiTieneCombinacionConDestino(
			AdministradorDeRecorridos *administradorDeRecorridos,
			Lista<Estacion*> *estacionesCercanasDestino,
			Viaje &posibleViajeConCombinacion, Lista<Viaje*> *viajesPosibles);
	/*
	 *  post: analiza si posibleViajeConCombinacion tiene alguna combinacion con
	 *  estacionesDelRecorridoFinal, de tener una combinacion guarda el viaje en viajesPosibles
	 */
	void analizarCombinacionEntreEstaciones(Viaje &posibleViajeConCombinacion,
			Lista<Estacion*> *estacionesDelRecorridoFinal,
			Lista<Viaje*> *viajesPosibles, bool *combinacionEncontrada);

	/*
	 * pre: recibe las estaciones cercanas al inicio y al destino, las coordenadas y el administrador de recorridos.
	 * post: busca estaciones cercanas chequeando cada recorrido del administrador de recorridos.
	 */
	void buscarEstacionesCercanas(Lista<Estacion*> *estacionesCercanasInicio,
			Lista<Estacion*> *estacionesCercanasDestino,
			Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
			AdministradorDeRecorridos *administradorDeRecorridos);

	/*
	 * pre: recibe las estaciones cercanas al inicio y al destino, las coordenadas inicial y final,
	 * y una lista con todas las estaciones del recorrido.
	 * post: busca estaciones cercanas y las agrega a estaciones del recorrido.
	 */
	void buscarEstacionesCercanas(Lista<Estacion*> *estacionesCercanasInicio,
			Lista<Estacion*> *estacionesCercanasDestino,
			Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
			Lista<Estacion*> *estacionesDelRecorrido);

	/*
	 * pre: recibe las coordenadas iniciales y finales, las estaciones cercanas al inicio y al destino,
	 * y una lista de viajes posibles vacia.
	 * post: busca si hay viajes directos entre las dos coordenadas, y si hay las agrega a la lista de viajes posibles.
	 */
	void buscarViajesDirectosPosibles(Coordenadas *coordenadaInicial,
			Coordenadas *coordenadaFinal,
			Lista<Estacion*> *estacionesCercanasInicio,
			Lista<Estacion*> *estacionesCercanasDestino,
			Lista<Viaje*> *viajesPosibles);

	/*
	 * pre: recibe una lista de viajes no vacia
	 * post: busca el mejor viaje con grafos
	 */
	Viaje* mejorViajeConGrafo(Lista<Viaje*>* viajes);

	/*
	 * pre: recibe la lista de estaciones del mejor viaje y las coordenadas de origen y destino
	 * post: una instancia de viaje
	 */
	Viaje* ordenarEstacionesMejorViaje(Lista<Estacion*>* estacionesMejorViaje,
			Coordenadas* coordenadasOrigen, Coordenadas* coordenadasDestino);

	/*
	 * pre: recibe una instancia de grafo, y las estaciones de origen, destino y la inicial y final
	 * post: inserta los vertices de las estaciones correspondientes en el grafo
	 */
	void agregarViajeDirectoAGrafo(Grafo* grafo, Estacion* estacionFinal,
			Estacion* estacionInicial, Estacion* origen, Estacion* destino);

	/*
	 * pre: recibe el viaje, una instancia de grafo, y las estaciones de origen, destino y la inicial y final
	 * post: inserta los vertices de las estaciones correspondientes en el grafo
	 */
	void agregarViajeCombinadoAGrafo(Viaje* viajeActual, Grafo* grafo,
			Estacion* estacionFinal, Estacion* estacionInicial,
			Estacion* origen, Estacion* destino);
};

#endif /* SRC_BUSCADORDEVIAJE_H_ */
