/*
 * Grafo.h
 *
 *  Created on: 28 nov. 2019
 *      Author: agustin
 */
/*
 *
 *

#ifndef SRC_GRAFO_H_
#define SRC_GRAFO_H_
#include "Estacion.h"
#include "Lista.h"

class Arista;
class Grafo;
class Vertice;

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

class Arista {

	Vertice *adyacente;
	double peso;
	friend class Grafo;

};

class Vertice {

private:

	Lista<Arista*> *adyacentes;
	Estacion *estacion;
	friend class Grafo;

public:

	Estacion* obtenerEstacion();
};

#endif /* SRC_GRAFO_H_ */


