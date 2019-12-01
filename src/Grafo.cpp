/*
 * Grafo.cpp
 *
 *  Created on: 28 nov. 2019
 *      Author: agustin
 */
/*
#include "Grafo.h"

Grafo::Grafo() {

	primero = NULL;

}

bool Grafo::estaVacio() {

	return (primero == NULL);

}



Vertice* Grafo::obtenerVertice(Estacion* estacion) {

	Vertice *auxiliar;
	bool existe = false;

	auxiliar = primero;
	while (auxiliar != NULL && !existe) {

		if(auxiliar->obtenerEstacion() == estacion){
			existe = true;

		}
	}
	if(existe){

		return auxiliar;
	}else{
		return NULL;
	}

}

void Grafo::insertarVertice(Estacion* estacion, Vertice* verticeAnterior, double peso){

	Vertice* nuevo = new Vertice;
	nuevo = estacion;
	if(estaVacio()){
		this->primero = nuevo;

	}else{


	}


}




*/





