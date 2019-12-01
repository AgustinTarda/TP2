/*
 * NodoGrafo.h
 *
 *  Created on: 26 nov. 2019
 *      Author: miguel
 */

#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

#include "Lista.h"
#include "Arista.h"
#include "Estacion.h"

class Arista;

class NodoGrafo {
private:
	Estacion* dato;
	Lista<Arista*>* aristasSalientes;

public:
	NodoGrafo(Estacion* elemento, Lista<Arista*>* aristas = NULL);
	void agregarAdyacencia(Arista* aristaAgregada);
	Estacion* obtenerDato();
	~NodoGrafo();
};

#endif /* NODOGRAFO_H_ */
