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

			Coordenadas coordenadaFinal, Lista<Parada> * Paradas);
	void buscarCombinacionesPosibles(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino);
	void buscarParadasCercanas(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino, Coordenadas coordenadaInicial, Coordenadas coordenadaFinal, Lista<Parada>* paradas);
	void buscarViajesDirectosPosibles(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino, Lista<Parada> viajesPosibles);


};




#endif /* SRC_BUSCADORDEVIAJE_H_ */
