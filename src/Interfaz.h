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
#include "Recorrido.h"
#include "Viaje.h"

class Interfaz {
private:
public:
	void mostrarMensajeDeBienvenida();
	Coordenadas pedirCoordenadasDeInicio();
	Coordenadas pedirCoordenadasDeDestino();
	double pedirLongitud();
	double pedirLatitud();
	void mostrarParada(Estacion parada);
	void imprimirRecorridos(Lista<Recorrido*> *recorridos);
	void imprimirEstaciones(Lista<Estacion*> *estaciones);
	void imprimirViajes(Lista<Viaje> viajes);
	void imprimirViajeDirecto(Viaje viajeDirecto);
	void imprimirViajeConCombinacionSimple(Viaje viajeConCombinacionSimple);

};

#endif /* SRC_INTERFAZ_H_ */
