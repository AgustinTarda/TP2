/*
 * Dijkstra.h
 *
 *  Created on: 29 nov. 2019
 *      Author: miguel
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Grafo.h"

class CaminosMinimos{
private:
	int* pesos[];
	Grafo grafo;
	int cantidadDeNodos;
public:
	CaminosMinimos(){
		this->grafo = new Grafo;
		pesos = 0;
		cantidadDeNodos = 0;
	}
	void agregarNodo(NodoGrafo* elemento){
		this->grafo->agregarVertice(elemento);
		cantidadDeNodos++;
	}
	void agregarArista(NodoGrafo* inicio, NodoGrafo* fin, int peso){
		this->grafo(inicio, fin);
	}
	void buscarCaminosMinimos(NodoGrafo* inicio, NodoGrafo* fin, Lista<Arista*>* resultado){

	}
	~CaminosMinimos(){
		delete this->grafo;
		if(this->pesos != 0){
			delete this->pesos;
		}
	}
};

#endif /* DIJKSTRA_H_ */
