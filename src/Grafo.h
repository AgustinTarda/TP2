/*
 * Grafo.h
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#ifndef SRC_GRAFO_H_
#define SRC_GRAFO_H_

#include "Estacion.h"
#include "Lista.h"
#include "Vertice.h"
#include "Arista.h"
static const int PESO_MAXIMO = 10000000;

class Grafo {
private:

	Lista<Vertice*> *vertices;

public:

	/*
	 * post: una instancia de grafo vacia
	 */
	Grafo();

	/*
	 * post: devuelve si el grafo esta vacio o no
	 */
	bool estaVacio();

	/*
	 * pre: recibe la estacion de origen
	 * post: la inserta en el grafo como la raiz
	 */
	void insertarVertice(Estacion *estacion);

	/*
	 * pre: recibe una estacion y el vertice anterior a donde debera ser ligada, junto con el peso
	 * post: agrega la estacion como vertice al grafo conectandolo con una nueva arista al vertice anterior
	 */
	void insertarVertice(Estacion *estacion, Vertice *verticeAnterior,
			double peso);

	/*
	 * pre: recibe una estacion
	 * post: devuelve el vertice que contiene a esa estacion
	 */
	Vertice* obtenerVerticeQueContiene(Estacion *estacion);

	/*
	 * pos: aplica el algoritmo de dijkstra para encontrar el mejor camino hacia destino
	 */
	Lista<Estacion*>* obtenerMejorCaminoConDijkstra(Vertice* verticeDestino, Vertice* verticeOrigen);

	/*
	 * post: devuelve el peso entre verticeDeSalida y verticeDeLlegada, si no
	 * tienen una arista que los una devuelve 10000000
	 */
	double obtenerPesoEntre(Vertice *verticeDeSalida,
			Vertice *verticeDeLlegada);

	/*
	 * pos: devuelve la cantidad de vertices del grafo
	 */
	int tamanio();

	/*
	 * post: elimina la instancia de Grafo
	 */
	~Grafo();

private:
	/*
	 * post: crea una matriz con los pesos de las aristas
	 */
	Lista<Lista<double*>*>* crearMatrizDePesos();

	/*
	 * pre: recibe una matriz de pesos existente
	 * post: elimina la matriz
	 */
	void eliminarMatrizDePesos(Lista<Lista<double*>*>* pesos);

	/*
	 * post: crea una lista de los posibles candidatos
	 */
	Lista<Vertice*>* crearListaDeCandidatos();

	/*
	 * pre: recibe una lista de candidatos, costes, los ultimos candidatos que modificaron el costo y el vertice de destino
	 * post: crea una lista de costes y modificadores para el vertice de salida
	 */
	void crearListaDeCostesYModificadoresPara(Lista<Vertice*> * candidatos,
			Lista<double*> * costes,
			Lista<Vertice*> *ultimosCandidatosQueModificaronElCoste,
			Vertice* verticeDeSalida);

	/*
	 * post: devuelve la posicion del siguiente candidato a procesar
	 */
	int obtenerPosicionDelSiguienteCandidatoAProcesar(
			Lista<Vertice*>* candidatos, Lista<double*>* costes);

	/*
	 * pre: recibe un vertice a procesar, su posicion, la lista de costes, la matriz de pesos, los candidatos
	 * y los ultimos candidatos que modificaron el coste
	 * post: procesa los costos con el vertice a procesar
	 */
	void procesarCostesCon(Vertice* verticeAProcesar,
			int posicionDelVerticeAProcesar, Lista<double*>* costes,
			Lista<Lista<double*>*>* pesos, Lista<Vertice*>* candidatos,
			Lista<Vertice*>* ultimosCandidatosQueModificaronElCoste);

	/*
	 *  post: elimina la lista de costos
	 */
	void eliminarCostes(Lista<double*>* costes);

	/*
	 * pre: recibe los vertices de destino y el de salida, los candidatos y los cantidatos que
	 * modificaron por ultima vez el costo
	 *  post: devuelve la lista de estaciones del camino mas optimo
	 */
	Lista<Estacion*>* extraerElCaminoHasta(Vertice* verticeDestino,
			Vertice* verticeDeSalida, Lista<Vertice*>* candidatos,
			Lista<Vertice*>* ultimosCandidatosQueModificaronElCoste);
};

#endif /* SRC_GRAFO_H_ */
