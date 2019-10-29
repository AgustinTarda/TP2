/*
 * ParadasCercanas.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#ifndef SRC_PARADA_H_
#define SRC_PARADA_H_

#include "Coordenadas.h"
#include <string>

class Parada {
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

	Parada(Coordenadas coordenadas, std::string linea,
			TipoDeTransporte tipoDeTransporte, std::string direccionDeParada);
	Parada(const Parada &otraParada);
	Parada();
	Coordenadas obtenerCoordenadas();
	std::string obtenerLinea();
	TipoDeTransporte obtenerTipoDeTransporte();
	std::string obtenerDireccion();

};

#endif /* SRC_PARADA_H_ */
