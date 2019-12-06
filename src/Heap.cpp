/*
 * Heap.cpp
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#include "Heap.h"

Heap::Heap(Lista<Arista*>* aristas){
	this->datos = new Lista<Arista*>;
	aristas->iniciarCursor();
	while (aristas->avanzarCursor()){
		this->acolar(aristas->obtenerCursor());
	}
}

void Heap::acolar(Arista* elemento){
	this->datos->agregar(elemento);
	unsigned int posicionActual = (this->datos->contarElementos()/2);
	while (posicionActual > 1){
		if (this->datos->obtener(posicionActual/2)->obtenerPeso() < this->datos->obtener(posicionActual)->obtenerPeso()){
			this->datos->intercambio(posicionActual, posicionActual/2);
		}
	}
}

Arista* Heap::desacolar(){
	if (this->datos->estaVacia()){
		throw std::string("no se puede desacloar de una cola vacia");
	}
	Arista* elementoDesacolado;
	elementoDesacolado = this->datos->obtener(1);
	this->datos->asignar(this->datos->obtener(this->datos->contarElementos()), 1);
	this->datos->remover(this->datos->contarElementos());
	unsigned int elementoActual = 1;
	bool ubicado = false;
	while (elementoActual*2 < this->datos->contarElementos() && !ubicado){
		if (this->datos->obtener(elementoActual*2)->obtenerPeso() < this->datos->obtener(elementoActual*2+1)){
			if (this->datos->obtener(elementoActual*2)->obtenerPeso() < this->datos->obtener(elementoActual)->obtenerPeso()){
				intercambio(elementoActual, elementoActual*2);
			}else{
				ubicado = true;
			}
			elementoActual = elementoActual*2;
		}else{
			if (this->datos->obtener(elementoActual*2+1)->obtenerPeso() < this->datos->obtener(elementoActual)->obtenerPeso()){
				intercambio(elementoActual, elementoActual*2+1);
			}else{
				ubicado = true;
			}
			elementoActual = elementoActual*2+1;
		}
	}
	return elementoDesacolado;
}

Heap::~Heap(){
	delete this->datos;
}

