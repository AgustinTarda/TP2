/*
 * Arista.h
 *
 *  Created on: 30 nov. 2019
 *      Author: miguel
 */

#ifndef SRC_ARISTA_H_
#define SRC_ARISTA_H_

#include "NodoGrafo.h"

class NodoGrafo;

class Arista {
private:
	NodoGrafo* origen;
	NodoGrafo* destino;
	int peso;
public:
	Arista(NodoGrafo* origen, NodoGrafo* destino, int peso);
	NodoGrafo* obtenerOrigen();
	NodoGrafo* obtenerDestino();
	int obtenerPeso();
};


#endif /* SRC_ARISTA_H_ */
