/*
 * Grafo.h
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#ifndef SRC_GRAFO_H_
#define SRC_GRAFO_H_


#include "Estacion.h"
#include "Lista.h"
#include "Vertice.h"

class Grafo {
	friend class Arista;
	friend class Vertice;
private:

	Vertice *primero;

public:

	Grafo();
	bool estaVacio();
	void insertarVertice(Estacion *estacion, Vertice* verticeAnterior, double peso);
	void insertarArista(Vertice *origen, Vertice *destino, double peso);
	void eliminarVertice(Vertice *verticeAEliminar);
	void eliminarArista(Arista *aristaAEliminar);
	bool existeVertice(Vertice *vertice);
	Vertice* obtenerVertice(Estacion *estacion);

};




#endif /* SRC_GRAFO_H_ */
