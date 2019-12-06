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

	/*
	 * pos: crea una instancia de Vertice
	 */
	Arista(Vertice *origen, Vertice *destino, int peso);

	/*
	 * pos: devuelve el vertice del origen
	 */
	Vertice* obtenerOrigen();

	/*
	 * pos: devuelve el vertice del destino
	 */
	Vertice* obtenerDestino();

	/*
	 * pos: devuelve el peso/coste de la arista
	 */
	int obtenerPeso();

	/*
	 * pos: devuelve si el destino es "vertice"
	 */
	bool elDestinoEs(Vertice *vertice);
};

#endif /* SRC_ARISTA_H_ */
