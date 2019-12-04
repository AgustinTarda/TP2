/*
 * Grafo.cpp
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#include "Grafo.h"

Grafo::Grafo() {

	this->vertices = new Lista<Vertice*>;
	this->tamanio = 0;

}

bool Grafo::estaVacio() {

	return (this->tamanio == 0);

}

Vertice* Grafo::obtenerVerticeQueContiene(Estacion *estacion) {

	Vertice *verticeBuscado = NULL;
	Vertice *verticeAnalizado = NULL;

	vertices->iniciarCursor();
	while (vertices->avanzarCursor() && verticeBuscado == NULL) {

		verticeAnalizado = this->vertices->obtenerCursor();
		if (verticeAnalizado->obtenerDato() == estacion) {
			verticeBuscado = verticeAnalizado;
		}
	}

	return verticeBuscado;
}

void Grafo::insertarVertice(Estacion *estacion){

	Vertice* nuevoVertice = new Vertice(estacion);
	this->vertices->agregar(nuevoVertice);

	this->tamanio +=1;
}

void Grafo::insertarVertice(Estacion *estacion, Vertice *verticeAnterior,
		double peso) {

	Vertice *nuevoVertice = NULL;
	nuevoVertice = obtenerVerticeQueContiene(estacion);

	if (nuevoVertice == NULL) {
		nuevoVertice = new Vertice(estacion);
		Arista *nuevaArista = new Arista(verticeAnterior, nuevoVertice, peso);
		verticeAnterior->agregarAdyacencia(nuevaArista);
	} else if (!verticeAnterior->tieneCaminoCon(nuevoVertice)) {
		Arista *nuevaArista = new Arista(verticeAnterior, nuevoVertice, peso);
		verticeAnterior->agregarAdyacencia(nuevaArista);
	}
}

void Grafo::dijkstra() {
	//Armo la matriz de pesos
	int **pesos = new int*[this->tamanio - 1];
	for (int i = 0; i < this->tamanio; i++) {
		pesos[i] = new int[this->tamanio - 1];

		for (int j = 0; j < this->tamanio; j++) {
			Vertice *verticeDeSalida = this->vertices->obtener(i + 1);
			Vertice *verticeDeLlegada = this->vertices->obtener(j + 1);
			pesos[i][j] = this->obtenerPesoEntre(verticeDeSalida,
					verticeDeLlegada);
		}

	}
	//Creo la lista de candidatos
	Lista<Vertice*> *candidatos = new Lista<Vertice*>(*(this->vertices));
	Vertice *verticeDeSalida = candidatos->obtener(1);
	candidatos->remover(1);

	//Creo la lista de costes
	Lista<double*> *costes = new Lista<double*>;

	for (unsigned int i = 1; i <= candidatos->contarElementos(); i++) {
		double *peso = new double(
				this->obtenerPesoEntre(verticeDeSalida,
						candidatos->obtener(i)));
		costes->agregar(peso, i);
	}

//Elimino la lista de costes
	while (!costes->estaVacia()) {
		double *pesoAEliminar = costes->obtener(1);
		delete pesoAEliminar;
		costes->remover(1);
	}
	delete costes;

//Elimino la lista de candidatos
	delete candidatos;

//ELimino la matriz de pesos
	for (int i = 0; i < this->tamanio; i++) {
		delete[] pesos[i];
	}
	delete[] pesos;
}

double Grafo::obtenerPesoEntre(Vertice *verticeDeSalida,
		Vertice *verticeDeLlegada) {
	double peso = 10000000;
	Arista *aristaBuscada = verticeDeSalida->obtenerAristaQueConecta(
			verticeDeLlegada);

	if (aristaBuscada != NULL) {
		peso = aristaBuscada->obtenerPeso();
	}

	return peso;
}

Grafo::~Grafo() {

	while (!this->vertices->estaVacia()) {
		Vertice *verticeAnalizado = this->vertices->obtener(1);
		delete verticeAnalizado;
		this->vertices->remover(1);
	}
	delete this->vertices;
}

