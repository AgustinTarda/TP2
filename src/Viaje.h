/*
 * Viaje.h
 *
 *  Created on: 30 oct. 2019
 *      Author: rochi
 */
#ifndef SRC_VIAJE_H_
#define SRC_VIAJE_H_

#include "Estacion.h"

class Viaje {
public:
	enum TipoDeViaje {
		DIRECTO, COMBINACION_SIMPLE
	};
private:

	unsigned int distanciaTotalACaminar;
	Estacion estacionInicio;
	Estacion estacionDestino;
	Estacion estacionBajadaDeCombinacion;
	Estacion estacionSubidaDeCombinacion;
	TipoDeViaje tipoDeViaje;

public:
	Viaje();
	Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio,
			Estacion EstacionDestino);
	Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio,
			Estacion EstacionDestino, Estacion estacionBajadaDeCombinacion,
			Estacion estacionSubidaDeCombinacion);
	Viaje(const Viaje &otroViaje);

};

#endif /* SRC_VIAJE_H_ */
