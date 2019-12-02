/*
 * Arista.h
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#ifndef SRC_ARISTA_H_
#define SRC_ARISTA_H_


#include "Vertice.h"

class Vertice;

class Arista {
private:
	Vertice* origen;
	Vertice* destino;
	int peso;
public:
	Arista(Vertice* origen, Vertice* destino, int peso);
	Vertice* obtenerOrigen();
	Vertice* obtenerDestino();
	int obtenerPeso();
};



#endif /* SRC_ARISTA_H_ */
