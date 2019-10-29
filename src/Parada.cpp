/*
 * ParadasCercanas.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "Parada.h"
using namespace std;

Parada:: Parada(Coordenadas coordenada, string linea, string tipoDeTransporte, string direccionDeParada){
	this-> coordenada = coordenada;
	this-> linea = linea;
	this-> tipoDeTransporte = tipoDeTransporte;
	this-> direccionDeParada = direccionDeParada;

}
Parada:: Parada(){

}
