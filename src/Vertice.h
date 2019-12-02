/*
 * Vertice.h
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_

#include "Lista.h"
#include "Arista.h"
#include "Estacion.h"

class Arista;

class Vertice {
private:
	Estacion* dato;
	Lista<Arista*>* aristasSalientes;

public:
	//Vertice(Estacion* elemento, Lista<Arista*>* aristas);
	Vertice(Estacion* estacion);
	void agregarAdyacencia(Arista* aristaAgregada);
	Estacion* obtenerDato();
	void agregarDato(Estacion* estacion);
	~Vertice();
};

#endif /* SRC_VERTICE_H_ */
