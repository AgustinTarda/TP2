/*
 * Vertice.cpp
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */
#include "Vertice.h"

Vertice::Vertice(Estacion *estacion) {
	this->dato = estacion;
	this->aristas = new Lista<Arista*>;
	this->visitado = false;

}

void Vertice::agregarAdyacencia(Arista *aristaAgregada) {
	this->aristas->agregar(aristaAgregada);
}

Estacion* Vertice::obtenerDato() {
	return dato;
}
void Vertice::agregarDato(Estacion *estacion) {
	this->dato = estacion;
}

bool Vertice::tieneCaminoCon(Vertice *vertice) {
	bool tieneCamino = false;

	this->aristas->iniciarCursor();
	while (this->aristas->avanzarCursor() && !tieneCamino) {
		Arista *aristaAAnalizar = aristas->obtenerCursor();
		tieneCamino = aristaAAnalizar->elDestinoEs(vertice);
	}

	return tieneCamino;
}

Arista* Vertice::obtenerAristaQueConecta(Vertice *otroVertice) {
	Arista *aristaBuscada = NULL;

	this->aristas->iniciarCursor();
	while (this->aristas->avanzarCursor() && aristaBuscada == NULL) {
		Arista *aristaAAnalizar = aristas->obtenerCursor();
		if (aristaAAnalizar->elDestinoEs(otroVertice)) {
			aristaBuscada = aristaAAnalizar;
		}
	}

	return aristaBuscada;
}

bool Vertice::fueVisitado() {
	return this->visitado;
}

void Vertice::marcarVisitado() {
	this->visitado = true;
}

Vertice::~Vertice() {
	while (!aristas->estaVacia()) {
		Arista *aristaAnalizada = this->aristas->obtener(1);
		delete aristaAnalizada;
		this->aristas->remover(1);
	}
	delete this->aristas;
}

