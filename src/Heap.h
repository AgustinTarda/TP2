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
	void intercambio(unsigned int posicion, unsigned int otraPosicion);
public:
	Heap(Lista<Arista*>* aristas);
	void acolar(Arista* elemento);
	Arista* desacolar();
	~Heap();
};

#endif /* SRC_HEAP_H_ */
