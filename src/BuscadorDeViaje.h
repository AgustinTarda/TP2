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
#include "Lista.h"
#include "Parada.h"

class BuscadorDeViaje{

	BuscadorDeViaje(Coordenadas coordenadaInicial,
			Coordenadas coordenadaFinal, Lista<Parada> * Paradas);
	void buscarCombinaciones(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino);
	void buscarParadasCercanas(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino, Coordenadas coordenadaInicial, Coordenadas coordenadaFinal, Lista<Parada>* paradas);
	void buscarViajesPosibles(Lista<Parada> paradasCercanasInicio, Lista<Parada> paradasCercanasDestino, Lista<Parada> viajesPosibles);

};




#endif /* SRC_BUSCADORDEVIAJE_H_ */
