/*
 * NodoGrafo.cpp
 *
 *  Created on: 30 nov. 2019
 *      Author: miguel
 */

#include "NodoGrafo.h"

	NodoGrafo::NodoGrafo(Estacion* elemento, Lista<Arista*>* aristas = NULL){
		this->dato = elemento;
		if (aristas != NULL){
			this->aristasSalientes = new Lista<Arista*>;
			Arista* aristaActual;
			aristas->iniciarCursor();
			while(aristas->avanzarCursor()){
				aristaActual = aristas->obtenerCursor();
				if(aristaActual->obtenerOrigen() == this->dato){
					this->aristasSalientes->agregar(aristaActual);
				}
			}
		}
	}

	void NodoGrafo::agregarAdyacencia(Arista* aristaAgregada){
		this->aristasSalientes->agregar(aristaAgregada);
	}

	Estacion* NodoGrafo::obtenerDato(){
		return dato;
	}

	NodoGrafo::~NodoGrafo(){
		delete this->aristasSalientes;
	}



