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


template <class T> class Grafo{
private:
	Lista<NodoGrafo<T>*>* vertices;

public:
	Grafo(){
		vertices = new Lista<NodoGrafo<T>*>;
	}
	Grafo(Grafo<T> &otroGrafo){
		vertices = new Lista<NodoGrafo<T>*>;
		vertices = otroGrafo->vertices;
	}
	bool existeVertice(T elemento){
		this->vertices->iniciarCursor();
		bool encontrado = false;
		while(!encontrado && this->vertices->avanzarCursor()){
			encontrado = (this->vertices->obtenerCursor()->obtenerDato() == elemento);
		}
		return encontrado;
	}
	bool existeArista(T elementoInicio, T elementoFin){
		bool encontrado = false;
		this->vertices->iniciarCursor();
		NodoGrafo<T>* nodoActual;
		while(!encontrado && this->vertices->avanzarCursor()){
			nodoActual = this->vertices->obtenerCursor();
			if(nodoActual->obtenerDato == elementoInicio){
				encontrado = nodoActual->esAdyacenteA(elementoFin);
			}
		}
		return encontrado;
	}
	void agregarVertice(T elemento){
		this->vertices->agregar(elemento);
	}
	void agregarArista(T elementoInicio, T elementoFin){
		this->vertices->iniciarCursor();
		NodoGrafo<T>* nodoInicio;
		NodoGrafo<T>* nodoFin;
		this->vertices->avanzarCursor();
		do{
				nodoInicio = this->vertices->obtenerCursor();
		}
		while(this->vertices->avanzarCursor() && nodoInicio->obtenerDato() == elementoInicio);
		this->vertices->iniciarCursor();
		this->vertices->avanzarCursor();
		do{
			nodoFin = this->vertices->obtenerCursor();
		}
		while(this->vertices->avanzarCursor() && nodoFin->obtenerDato() == elementoFin);

		nodoInicio->agregarAdyacencia(nodoFin);
	}
	~Grafo(){
		delete this->vertices;
	}
};



#endif /* GRAFO_H_ */
