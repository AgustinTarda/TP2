/*
 * Coordenadas.cpp
 *
 *  Created on: Oct 21, 2019
 *      Author: lucas
 */

#include "Coordenadas.h"

Coordenadas::Coordenadas(double latitudSalida, double longitudSalida,
						double latitudDestino, double longitudDestino) {

	this->latitudSalida = latitudSalida;
	this->longitudSalida = longitudSalida;
	this->latitudDestino = latitudDestino;
	this->longitudDestino = longitudDestino;
}

Coordenadas::Coordenadas(const Coordenadas &otrasCoordenadas) {

	this->latitudSalida = otrasCoordenadas.latitudSalida;
	this->longitudSalida = otrasCoordenadas.longitudSalida;
	this->latitudDestino = otrasCoordenadas.latitudDestino;
	this->longitudDestino = otrasCoordenadas.longitudDestino;
}


Coordenadas::Coordenadas() {

	this->latitudSalida = 0;
	this->longitudSalida = 0;
	this->latitudDestino = 0;
	this->longitudDestino = 0;
}

double Coordenadas::getLatitudSalida() {
	return latitudSalida;
}

double Coordenadas::getLongitudSalida() {
	return longitudSalida;
}

double Coordenadas::getLatitudDestino() {
	return latitudDestino;
}

double Coordenadas::getLongitudDestino() {
	return longitudDestino;
}




