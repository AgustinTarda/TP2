/*
 * AlgoMaps.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_ALGOMAPS_H_
#define SRC_ALGOMAPS_H_

#include <string>

#include "Estacion.h"
#include "Lista.h"
#include "Interfaz.h"
#include "LectoraDeArchivos.h"

class AlgoMaps {
private:
	Interfaz interfazDeUsuario;
	Lista<Estacion> paradas;

public:
	AlgoMaps();

};

#endif /* SRC_ALGOMAPS_H_ */
