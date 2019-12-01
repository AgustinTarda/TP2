/*
 * Grafo.cpp
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#include "Grafo.h"

	Grafo::Grafo(){
		vertices = new Lista<NodoGrafo*>;
		aristas = new Lista<Arista*>;
	}
	Grafo::Grafo(Grafo* otroGrafo){
		vertices = new Lista<NodoGrafo*>;
		vertices = otroGrafo->vertices;
		aristas = new Lista<NodoGrafo*>;
		aristas = otroGrafo->aristas;

	}
	bool Grafo::existeVertice(Estacion* elemento){
		this->vertices->iniciarCursor();
		bool encontrado = false;
		while(!encontrado && this->vertices->avanzarCursor()){
			encontrado = (this->vertices->obtenerCursor()->obtenerDato() == elemento);
		}
		return encontrado;
	}
	bool Grafo::existeArista(NodoGrafo* inicio, NodoGrafo* fin){
		bool encontrado = false;
		this->aristas->iniciarCursor();
		Arista* aristaActual;
		while(!encontrado && this->aristas->avanzarCursor()){
			aristaActual = this->aristas->obtenerCursor();
			encontrado = (aristaActual->obtenerOrigen() == inicio && aristaActual->obtenerDestino() == fin);
		}
		return encontrado;
	}
	void Grafo::agregarVertice(NodoGrafo* elemento){
		this->vertices->agregar(elemento);
	}
	void Grafo::agregarArista(NodoGrafo* inicio, NodoGrafo* fin, int peso=0){
		Arista* nuevaArista(inicio, fin, peso);
		this->aristas->agregar(nuevaArista);
	}
	Grafo::~Grafo(){
		delete this->vertices;
		delete this->aristas;
	}



