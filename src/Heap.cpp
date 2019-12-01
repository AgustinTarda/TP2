/*
 * Heap.cpp
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#include "Heap.h"

Heap::Heap(Lista<Arista*>* aristas){
	this->datos = new Lista<Arista*>(aristas);
	this->cantidadDeDatos = aristas->contarElementos();
}
