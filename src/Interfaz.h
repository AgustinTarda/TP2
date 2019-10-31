/*
 * Interfaz.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include<iostream>

#include "Estacion.h"

class Interfaz {
private:
public:
	void mostrarMensajeDeBienvenida();
	Coordenadas pedirCoordenadasDeInicio();
	Coordenadas pedirCoordenadasDeDestino();
	double pedirLongitud();
	double pedirLatitud();
	void mostrarParada(Estacion parada);
	void mostrarLargoListaViajes(int cantidad);

};

#endif /* SRC_INTERFAZ_H_ */
