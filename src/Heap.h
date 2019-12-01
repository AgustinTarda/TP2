/*
 * Heap.h
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include "Arista.h"
#include "Lista.h"

class Heap {
private:
	Lista<Arista*>* datos;
	int cantidadDeDatos;
	void heapify();
public:
	Heap(Lista<Arista*>* aristas);
};

#endif /* SRC_HEAP_H_ */
