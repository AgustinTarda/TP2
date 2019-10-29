/*
 * Coordenadas.cpp
 *
 *  Created on: Oct 21, 2019
 *      Author: lucas
 */

#include "Coordenadas.h"

Coordenadas::Coordenadas(double latitud, double longitud) {

	this->latitud = latitud;
	this->longitud = longitud;
}

Coordenadas::Coordenadas(const Coordenadas &otrasCoordenadas) {

	this->latitud = otrasCoordenadas.latitud;
	this->longitud = otrasCoordenadas.longitud;
}


Coordenadas::Coordenadas() {

	this->latitud = 0;
	this->longitud = 0;
}

double Coordenadas::getLatitud() {
	return latitud;
}

double Coordenadas::getLongitud() {
	return longitud;
}

unsigned int Coordenadas::calcularDistancia(const Coordenadas coordenadasFinal){

	double convertidorGradoARadianes = PI / 180;
	double latitudInicio = this->latitud * convertidorGradoARadianes;
	double longitudInicio = this->longitud * convertidorGradoARadianes;
	double latitudFinal = coordenadasFinal.latitud * convertidorGradoARadianes;
	double longitudFinal = coordenadasFinal.longitud * convertidorGradoARadianes;

	double radioTierra = 6378.137;
	double diferenciaEntreLongitudes = longitudFinal - longitudInicio;
	double distanciaEntreCoordenadas = acos(sin(latitudInicio) * sin(latitudFinal)
			+ cos(latitudInicio) * sin(latitudFinal) * cos(diferenciaEntreLongitudes) * radioTierra);


	return distanciaEntreCoordenadas * 1000;
}




