/*
 * NodoGrafo.h
 *
 *  Created on: 26 nov. 2019
 *      Author: miguel
 */

#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

#include "Lista.h"

class NodoGrafo {
private:
	T dato;
	Lista<NodoGrafo*>* nodosAdyacentes;

public:
	NodoGrafo(T elemento){
		this->dato = elemento;
		this->nodosAdyacentes = new Lista<NodoGrafo*>;
	}

	NodoGrafo(T elemento, Lista<NodoGrafo*>* adyacencias){
		this->dato = elemento;
		this->nodosAdyacentes = new Lista<NodoGrafo*>(adyacencias);
	}

	void agregarAdyacencia(NodoGrafo* nodoAdyacente){
		this->nodosAdyacentes->agregar(nodoAdyacente);
	}

	T obtenerDato(){
		return dato;
	}

	bool esAdyacenteA(T candidato){
		bool encontrado = false;
		this->nodosAdyacentes->iniciarCursor();

		while(this->nodosAdyacentes->avanzarCursor() && !encontrado){
			encontrado = (this->nodosAdyacentes->obtenerCursor() == candidato);
		}

		return encontrado;
	}

	~NodoGrafo(){
		delete this->nodosAdyacentes;
	}

};

#endif /* NODOGRAFO_H_ */
