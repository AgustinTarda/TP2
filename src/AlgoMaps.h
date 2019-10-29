/*
 * AlgoMaps.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_ALGOMAPS_H_
#define SRC_ALGOMAPS_H_

#include <string>
#include "Lista.h"
#include "Metrobus.h"
#include "ferrocarril.h"
#include "colectivos.h"
#include "subte.h"
#include "garage.h"
#include "Interfaz.h"
#include "LectoraDeArchivos.h"

class AlgoMaps {
private:
	Interfaz interfazDeUsuario;
	Lista<EstacionMetrobus> estacionesDeMetrobus;
	Lista<EstacionFerrocarril> estacionesDeFerrocarril;
	Lista<EstacionColectivo> estacionesDeColectivo;
	Lista<EstacionSubte> estacionesDeSubte;
	Lista<Garage> garages;

public:
	AlgoMaps();

};

#endif /* SRC_ALGOMAPS_H_ */
