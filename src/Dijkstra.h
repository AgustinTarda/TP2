/*
 * Dijkstra.h
 *
 *  Created on: 29 nov. 2019
 *      Author: miguel
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Grafo.h"

template<class T> class Dijkstra{
private:
	int* pesos[];
	Grafo<T> grafo;
	int cantidadDeNodos;
public:
	Dijkstra(){
		this->grafo = new Grafo<T>;
		pesos = NULL;
		cantidadDeNodos = 0;
	}
	void agregarNodo(T elemento){
		this->grafo->agragarVertice(elemento);
		cantidadDeNodos++;
	}
	void agregarArista(T inicio, T fin, int peso){
		this->grafo(inicio, fin);
	}
	Lista<T>* buscarCaminosMinimos(T inicio, T fin){

	}
	~Dijkstra(){
		delete this->grafo;
		if(this->pesos != NULL){
			delete this->pesos;
		}
	}
};

#endif /* DIJKSTRA_H_ */
