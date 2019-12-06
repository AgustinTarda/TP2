/*
 * Vertice.h
 *
 *  Created on: 2 dic. 2019
 *      Author: rochi
 */

#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_

#include "Lista.h"
#include "Arista.h"
#include "Estacion.h"

class Arista;

class Vertice {
private:
	Estacion *dato;
	Lista<Arista*> *aristas;
	bool visitado;

public:
	/*
	 * pre: recibe un puntero a una estacion
	 * pos: crea una instancia de vertice con la estacion de dato
	 */
	Vertice(Estacion *estacion);

	/*
	 * pre: recibe un puntero a una arista
	 * pos: agrega la arista adyacente
	 */
	void agregarAdyacencia(Arista *aristaAgregada);

	/*
	 * pos: devuelve el dato del vertice
	 */
	Estacion* obtenerDato();

	/*
	 * pre: recibe un puntero a una estacion
	 * pos: agrega la estacion al vertice
	 */
	void agregarDato(Estacion *estacion);

	/*
	 * pos: devuelve si forma una arista con vertice
	 */
	bool tieneCaminoCon(Vertice *vertice);

	/*
	 * pos: devuelve la arista que conecta con otroVertice devuelve NULL si no existe la arista
	 */
	Arista* obtenerAristaQueConecta(Vertice *otroVertice);

	/*
	 * pos: devuelve si esta marcado
	 */
	bool fueVisitado();

	/*
	 * pos: marca el vertice como visitado
	 */
	void marcarVisitado();

	/*
	 * pos: elimina la instancia
	 */
	~Vertice();
};

#endif /* SRC_VERTICE_H_ */
