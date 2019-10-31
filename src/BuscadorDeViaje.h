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
#include "DibujadorDeMapa.h"
#include "Estacion.h"
#include "Lista.h"
#include "AdministradorDeRecorridos.h"
#include "Recorrido.h"
#include "Viaje.h"

class BuscadorDeViaje {
private:
	DibujadorDeMapa* dibujador;
public:
	BuscadorDeViaje();

	int buscarViaje(Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos administradorDeRecorridos);

	void buscarCombinacionesPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			AdministradorDeRecorridos administradorDeRecorridos,
			Lista<Viaje> viajesPosibles);

	void buscarEstacionesCercanas(Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			AdministradorDeRecorridos administradorDeRecorridos);
	void buscarEstacionesCercanas(Lista<Estacion>& estacionesCercanasInicio,
			Lista<Estacion> &estacionesCercanasDestino,
			Coordenadas coordenadaInicial, Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesDelRecorrido);

	void buscarViajesDirectosPosibles(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal,
			Lista<Estacion> estacionesCercanasInicio,
			Lista<Estacion> estacionesCercanasDestino,
			Lista<Viaje> viajesPosibles);

	~BuscadorDeViaje();
};

#endif /* SRC_BUSCADORDEVIAJE_H_ */
