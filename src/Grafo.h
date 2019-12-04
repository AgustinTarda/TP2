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
	/*
	 * pre: recibe la estacion de origen
	 * post: la inserta en el grafo como la raiz
	 */
	void insertarVertice(Estacion *estacion);
	void insertarVertice(Estacion *estacion, Vertice *verticeAnterior,
			double peso);
	Vertice* obtenerVerticeQueContiene(Estacion *estacion);

	/*
	 * post: aplica el algoritmo de dijkstra para encontrar el mejor camino;
	 */
	void dijkstra();

	/*
	 * post: devuelve el peso entre verticeDeSalida y verticeDeLlegada, si no
	 * tienen una arista que los una devuelve 10000000
	 */
	double obtenerPesoEntre(Vertice *verticeDeSalida,
			Vertice *verticeDeLlegada);

	/*
	 * post: elimina la instancia de Grafo
	 */
	~Grafo();

};

#endif /* SRC_GRAFO_H_ */
