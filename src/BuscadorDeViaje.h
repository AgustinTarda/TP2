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

class BuscadorDeViaje{

	BuscadorDeViaje(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal, Lista<Estacion> * Paradas);
	void buscarCombinaciones(Lista<Estacion> paradasCercanasInicio, Lista<Estacion> paradasCercanasDestino);
	void buscarParadasCercanas(Lista<Estacion> paradasCercanasInicio, Lista<Estacion> paradasCercanasDestino, Coordenadas coordenadaInicial, Coordenadas coordenadaFinal, Lista<Estacion>* paradas);
	void buscarViajesPosibles(Lista<Estacion> paradasCercanasInicio, Lista<Estacion> paradasCercanasDestino, Lista<Estacion> viajesPosibles);

};




#endif /* SRC_BUSCADORDEVIAJE_H_ */
