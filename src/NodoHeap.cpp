/*
 * NodoHeap.cpp
 *
 *  Created on: 1 dic. 2019
 *      Author: miguel
 */

#include "NodoHeap.h"

NodoHeap::NodoHeap(Arista* dato){
	this->dato = dato;
	this->hijoDerecho = NULL;
	this->hijoIzquierdo = NULL;
}

NodoHeap* NodoHeap::obtenerHijoIzquierdo(){
	return this->hijoIzquierdo;
}

NodoHeap* NodoHeap::obtenerHijoDerecho(){
	return this->hijoDerecho;
}

void NodoHeap::cambiarHijoDerecho(NodoHeap* nuevoHijo){
	this->hijoDerecho = nuevoHijo;
}

void NodoHeap::cambiarHijoIzquierdo(NodoHeap* nuevoHijo){
	this->hijoIzquierdo = nuevoHijo;
}

Arista* NodoHeap::obtenerDato(){
	return this->dato;
}

