/*
 * Arista.cpp
 *
 *  Created on: 30 nov. 2019
 *      Author: miguel
 */

#include "Arista.h"

Arista::Arista(NodoGrafo* origen, NodoGrafo* destino, int peso){
	this->origen = origen;
	this->destino = destino;
	this->peso = peso;
}

NodoGrafo* Arista::obtenerOrigen(){
	return this->origen;
}

NodoGrafo* Arista::obtenerDestino(){
	return this->destino;
}

int Arista::obtenerPeso(){
	return this->peso;
}
