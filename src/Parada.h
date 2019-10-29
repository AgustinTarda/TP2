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

class Parada{

private:
	Coordenadas coordenadas;
	std::string linea;
	std::string tipoDeTransporte;
	std::string direccionDeParada;


public:
	Parada(Coordenadas coordenadas, std::string linea, std::string tipoDeTransporte, std::string direccionDeParada);
	Parada();
};



#endif /* SRC_PARADA_H_ */
