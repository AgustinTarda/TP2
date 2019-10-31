/*
 * Viaje.cpp
 *
 *  Created on: 30 oct. 2019
 *      Author: rochi
 */
#include "Viaje.h"


Viaje::Viaje() {

}
Viaje::Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio, Estacion EstacionDestino) {
	this->tipoDeViaje = DIRECTO;
	this->distanciaTotalACaminar = distanciaTotalACaminar;
	this->estacionInicio = estacionInicio;
	this->estacionDestino = EstacionDestino;
}

Viaje::Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio, Estacion EstacionDestino, Estacion estacionBajadaDeCombinacion, Estacion estacionSubidaDeCombinacion) {
	this->tipoDeViaje = COMBINACION_SIMPLE;
	this->distanciaTotalACaminar = distanciaTotalACaminar;
	this->estacionInicio = estacionInicio;
	this->estacionDestino = EstacionDestino;
	this->estacionBajadaDeCombinacion = estacionBajadaDeCombinacion;
	this->estacionSubidaDeCombinacion = estacionSubidaDeCombinacion;

}
