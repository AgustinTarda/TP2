/*
 * Grafo.h
 *
 *  Created on: 28 nov. 2019
 *      Author: miguel
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Lista.h"
#include "NodoGrafo.h"
#include "Arista.h"
#include "Estacion.h"


class Grafo{
private:
	Lista<NodoGrafo*>* vertices;
	Lista<Arista*>* aristas;

public:
	Grafo();
	Grafo(Grafo* otroGrafo);
	bool existeVertice(Estacion* elemento);
	bool existeArista(NodoGrafo* inicio, NodoGrafo* fin);
	void agregarVertice(NodoGrafo* elemento);
	void agregarArista(NodoGrafo* inicio, NodoGrafo* fin, int peso=0);
	~Grafo();
};



#endif /* GRAFO_H_ */
