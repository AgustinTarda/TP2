/*
 * Grafo.cpp
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#include "Grafo.h"

Grafo::Grafo() {

	this->vertices = new Lista<Vertice*>;

}

bool Grafo::estaVacio() {

	return (this->tamanio() == 0);

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

void Grafo::insertarVertice(Estacion *estacion) {

	Vertice* nuevoVertice = new Vertice(estacion);
	this->vertices->agregar(nuevoVertice);
}

void Grafo::insertarVertice(Estacion *estacion, Vertice *verticeAnterior,
		double peso) {

	Vertice *nuevoVertice = NULL;
	nuevoVertice = obtenerVerticeQueContiene(estacion);

	if (nuevoVertice == NULL) {
		nuevoVertice = new Vertice(estacion);
		Arista *nuevaArista = new Arista(verticeAnterior, nuevoVertice, peso);
		verticeAnterior->agregarAdyacencia(nuevaArista);
		vertices->agregar(nuevoVertice);
	} else if (!verticeAnterior->tieneCaminoCon(nuevoVertice)) {
		Arista *nuevaArista = new Arista(verticeAnterior, nuevoVertice, peso);
		verticeAnterior->agregarAdyacencia(nuevaArista);
	}
}

Lista<Estacion*>* Grafo::obtenerMejorCaminoConDijkstra(Vertice* verticeDestino,
		Vertice* verticeDeSalida) {

	//Armo la matriz de pesos
	Lista<Lista<double*>*>* pesos = this->crearMatrizDePesos();

	//Creo la lista de candidatos
	Lista<Vertice*> *candidatos = this->crearListaDeCandidatos();

	//Creo la lista de costes y sus modificadores
	Lista<double*> *costes = new Lista<double*>;
	Lista<Vertice*> *ultimosCandidatosQueModificaronElCoste =
			new Lista<Vertice*>;
	this->crearListaDeCostesYModificadoresPara(candidatos, costes,
			ultimosCandidatosQueModificaronElCoste, verticeDeSalida);

	//Aplico el algoritmo
	int cantidadDeCandidatos = candidatos->contarElementos();
	while (cantidadDeCandidatos > 0) {

		//Busco el candidato de menor coste no visitado
		int posicionDelVerticeAProcesar =
				this->obtenerPosicionDelSiguienteCandidatoAProcesar(candidatos,
						costes);
		Vertice *verticeAProcesar = candidatos->obtener(
				posicionDelVerticeAProcesar);
		verticeAProcesar->marcarVisitado();

		//Utilizo el candidato

		this->procesarCostesCon(verticeAProcesar, posicionDelVerticeAProcesar,
				costes, pesos, candidatos,
				ultimosCandidatosQueModificaronElCoste);

		cantidadDeCandidatos--;
	}

	//Extraigo el mejor camino
	Lista<Estacion*>* estacionesDelViajeFinal = this->extraerElCaminoHasta(
			verticeDestino, verticeDeSalida, candidatos,
			ultimosCandidatosQueModificaronElCoste);

	//Elimino la lista de costes y ultimos candidatos que modificaron el coste
	this->eliminarCostes(costes);
	delete ultimosCandidatosQueModificaronElCoste;

	//Elimino la lista de candidatos
	delete candidatos;

	//ELimino la matriz de pesos
	this->eliminarMatrizDePesos(pesos);
	return estacionesDelViajeFinal;
}

Lista<Lista<double*>*>* Grafo::crearMatrizDePesos() {

	Lista<Lista<double*>*>* pesos = new Lista<Lista<double*>*>;

	for (int i = 1; i <= this->tamanio(); i++) {
		Lista<double*>* listaPesos = new Lista<double*>;
		pesos->agregar(listaPesos);
		for (int j = 1; j <= this->tamanio(); j++) {
			Vertice *verticeDeSalida = this->vertices->obtener(i);
			Vertice *verticeDeLlegada = this->vertices->obtener(j);
			double* peso = new double(
					this->obtenerPesoEntre(verticeDeSalida, verticeDeLlegada));
			pesos->obtener(i)->agregar(peso, j);
		}
	}

	return pesos;
}

void Grafo::eliminarMatrizDePesos(Lista<Lista<double*>*>* pesos) {
	while (!pesos->estaVacia()) {
		Lista<double*>* listaPesos = pesos->obtener(1);
		while (!listaPesos->estaVacia()) {
			double* peso = listaPesos->obtener(1);
			delete peso;
			listaPesos->remover(1);
		}
		delete listaPesos;
		pesos->remover(1);
	}
	delete pesos;
}
Lista<Vertice*>* Grafo::crearListaDeCandidatos() {
	Lista<Vertice*> *candidatos = new Lista<Vertice*>;

	candidatos->agregar(*(this->vertices));
	candidatos->remover(1);

	return candidatos;
}

void Grafo::crearListaDeCostesYModificadoresPara(Lista<Vertice*>* candidatos,
		Lista<double*>* costes,
		Lista<Vertice*>* ultimosCandidatosQueModificaronElCoste,
		Vertice* verticeDeSalida) {
	for (unsigned int i = 1; i <= candidatos->contarElementos(); i++) {
		double *peso = new double(
				this->obtenerPesoEntre(verticeDeSalida,
						candidatos->obtener(i)));
		costes->agregar(peso, i);
		ultimosCandidatosQueModificaronElCoste->agregar(verticeDeSalida, i);
	}
}

int Grafo::obtenerPosicionDelSiguienteCandidatoAProcesar(
		Lista<Vertice*>* candidatos, Lista<double*>* costes) {
	int posicionDelVerticeAProcesar = 1;
	int posicionDelCandidato = 1;
	double pesoMinimo = PESO_MAXIMO;

	candidatos->iniciarCursor();
	while (candidatos->avanzarCursor()) {
		Vertice *candidatoAnalizado = candidatos->obtenerCursor();
		double *costoDelCandidato = costes->obtener(posicionDelCandidato);
		if (!candidatoAnalizado->fueVisitado()
				&& *costoDelCandidato < pesoMinimo) {
			pesoMinimo = *costoDelCandidato;
			posicionDelVerticeAProcesar = posicionDelCandidato;
		}
		posicionDelCandidato++;
	}

	return posicionDelVerticeAProcesar;
}

void Grafo::procesarCostesCon(Vertice* verticeAProcesar,
		int posicionDelVerticeAProcesar, Lista<double*>* costes,
		Lista<Lista<double*>*>* pesos, Lista<Vertice*>* candidatos,
		Lista<Vertice*>* ultimosCandidatosQueModificaronElCoste) {

	for (int posicionDelVerticeAnalizado = 1;
			posicionDelVerticeAnalizado <= costes->contarElementos();
			posicionDelVerticeAnalizado++) {

		double costeActual = *(costes->obtener(posicionDelVerticeAnalizado));
		double nuevoCoste = *(costes->obtener(posicionDelVerticeAProcesar))
				+ *(pesos->obtener(posicionDelVerticeAProcesar + 1)->obtener(
						posicionDelVerticeAnalizado + 1));
		if (posicionDelVerticeAnalizado != posicionDelVerticeAProcesar
				&& nuevoCoste < costeActual
				&& !candidatos->obtener(posicionDelVerticeAnalizado)->fueVisitado()) {
			double *viejoCoste = costes->obtener(posicionDelVerticeAnalizado);
			*viejoCoste = nuevoCoste;
			ultimosCandidatosQueModificaronElCoste->asignar(verticeAProcesar,
					posicionDelVerticeAnalizado);

		}
	}
}

void Grafo::eliminarCostes(Lista<double*>* costes) {
	while (!costes->estaVacia()) {
		double *pesoAEliminar = costes->obtener(1);
		delete pesoAEliminar;
		costes->remover(1);
	}
	delete costes;
}
Lista<Estacion*>* Grafo::extraerElCaminoHasta(Vertice* verticeDestino,
		Vertice* verticeDeSalida, Lista<Vertice*>* candidatos,
		Lista<Vertice*>* ultimosCandidatosQueModificaronElCoste) {

	Lista<Estacion*>* estacionesDelViajeFinal = new Lista<Estacion*>;
	estacionesDelViajeFinal->agregar(verticeDestino->obtenerDato());
	Vertice* modificadorAnterior = verticeDestino;

	do {
		bool seEncontroVertice = false;
		int posicionDelVertice = 0;
		candidatos->iniciarCursor();
		while (!seEncontroVertice && candidatos->avanzarCursor()) {
			posicionDelVertice++;
			seEncontroVertice = (candidatos->obtenerCursor()
					== modificadorAnterior);
		}
		modificadorAnterior = ultimosCandidatosQueModificaronElCoste->obtener(
				posicionDelVertice);
		estacionesDelViajeFinal->agregar(modificadorAnterior->obtenerDato());
	} while (modificadorAnterior != verticeDeSalida);

	return estacionesDelViajeFinal;
}
double Grafo::obtenerPesoEntre(Vertice *verticeDeSalida,
		Vertice *verticeDeLlegada) {
	double peso = PESO_MAXIMO;
	Arista *aristaBuscada = verticeDeSalida->obtenerAristaQueConecta(
			verticeDeLlegada);
	if (verticeDeSalida == verticeDeLlegada) {
		peso = 0;
	} else if (aristaBuscada != NULL) {
		peso = aristaBuscada->obtenerPeso();
	}

	return peso;
}

int Grafo::tamanio() {
	return vertices->contarElementos();
}

Grafo::~Grafo() {

	while (!this->vertices->estaVacia()) {
		Vertice *verticeAnalizado = this->vertices->obtener(1);
		delete verticeAnalizado;
		this->vertices->remover(1);
	}
	delete this->vertices;
}

