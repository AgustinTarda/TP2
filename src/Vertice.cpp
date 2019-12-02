/*
 * Vertice.cpp
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */
#include "Vertice.h"

/*Vertice::Vertice(Estacion* elemento, Lista<Arista*>* aristas) {
	this->dato = elemento;
	if (aristas != NULL) {
		this->aristasSalientes = new Lista<Arista*>;
		Arista* aristaActual;
		aristas->iniciarCursor();
		while (aristas->avanzarCursor()) {
			aristaActual = aristas->obtenerCursor();
			if ((aristaActual->obtenerOrigen())->obtenerDato() == this->dato) {
				this->aristasSalientes->agregar(aristaActual);
			}
		}
	}
}*/
Vertice::Vertice(Estacion* estacion){
	this->dato = estacion;
	this->aristasSalientes = new Lista<Arista*>;

}

void Vertice::agregarAdyacencia(Arista* aristaAgregada) {
	this->aristasSalientes->agregar(aristaAgregada);
}

Estacion* Vertice::obtenerDato() {
	return dato;
}
void Vertice::agregarDato(Estacion* estacion){
	this-> dato = estacion;
}

Vertice::~Vertice() {
	delete this->aristasSalientes;
}

