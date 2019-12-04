/*
 * Arista.cpp
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#include "Arista.h"

Arista::Arista(Vertice *origen, Vertice *destino, int peso) {
	this->origen = origen;
	this->destino = destino;
	this->peso = peso;
}

Vertice* Arista::obtenerOrigen() {
	return this->origen;
}

Vertice* Arista::obtenerDestino() {
	return this->destino;
}

int Arista::obtenerPeso() {
	return this->peso;
}

bool Arista::elDestinoEs(Vertice *vertice) {
	return (this->destino == vertice);
}

