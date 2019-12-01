/*
 * NodoHeap.h
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#ifndef SRC_NODOHEAP_H_
#define SRC_NODOHEAP_H_

#include "Arista.h"

class NodoHeap {
private:
	Arista* dato;
	NodoHeap* hijoDerecho;
	NodoHeap* hijoIzquierdo;
public:
	NodoHeap(Arista* dato);
	NodoHeap* obtenerHijoDerecho();
	NodoHeap* obtenerHijoIzquierdo();
	void cambiarHijoDerecho(NodoHeap* nuevoHijo);
	void cambiarHijoIzquierdo(NodoHeap* nuevoHijo);
	Arista* obtenerDato();
};

#endif /* SRC_NODOHEAP_H_ */
