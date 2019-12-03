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
#include "Arista.h"

class Grafo {
	friend class Arista;
	friend class Vertice;
private:

	Lista<Vertice*> *vertices;
	int tamanio;

public:

	Grafo();
	bool estaVacio();
	void insertarVertice(Estacion *estacion, Vertice *verticeAnterior,
			double peso);
	Vertice* obtenerVerticeQueContiene(Estacion *estacion);

	/*
	 * pos: aplica el algoritmo de dijkstra para encontrar el mejor camino;
	 */
	void dijkstra();

	/*
	 * pos: devuelve el peso entre verticeDeSalida y verticeDeLlegada, si no
	 * tienen una arista que los una devuelve 10000000
	 */
	double obtenerPesoEntre(Vertice *verticeDeSalida,
			Vertice *verticeDeLlegada);

	/*
	 * pos: elimina la instancia de Grafo
	 */
	~Grafo();

};

#endif /* SRC_GRAFO_H_ */
