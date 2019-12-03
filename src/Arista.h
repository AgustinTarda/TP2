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
	Vertice *origen;
	Vertice *destino;
	double peso;
public:
	Arista(Vertice *origen, Vertice *destino, int peso);
	Vertice* obtenerOrigen();
	Vertice* obtenerDestino();
	int obtenerPeso();

	/*
	 * pos: devuelve si el destino es "vertice"
	 */
	bool elDestinoEs(Vertice *vertice);
};

#endif /* SRC_ARISTA_H_ */
