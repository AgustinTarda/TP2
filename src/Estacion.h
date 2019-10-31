/*
 * ParadasCercanas.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#ifndef SRC_ESTACION_H_
#define SRC_ESTACION_H_

#include "Coordenadas.h"
#include <string>

class Estacion {
public:
	enum TipoDeTransporte {
		SUBTE, COLECTIVO, METROBUS, FERROCARRIL, GARAGE
	};

private:
	Coordenadas coordenadas;
	std::string linea;
	TipoDeTransporte tipoDeTransporte;
	std::string direccion;

public:

	Estacion(Coordenadas coordenadas, std::string linea,
			TipoDeTransporte tipoDeTransporte, std::string direccion);
	Estacion(const Estacion &otraParada);
	Estacion();
	Coordenadas obtenerCoordenadas();
	std::string obtenerLinea();
	TipoDeTransporte obtenerTipoDeTransporte();
	std::string obtenerDireccion();
	std::string imprimirTipoDeTransporte();
};

#endif /* SRC_ESTACION_H_ */
