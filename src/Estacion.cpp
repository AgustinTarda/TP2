/*
 * ParadasCercanas.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */
//
#include "Estacion.h"
using namespace std;

Estacion::Estacion(Coordenadas coordenadas,
		TipoDeTransporte tipoDeTransporte, string linea, string direccionDeParada) {
	this->coordenadas = coordenadas;
	this->linea = linea;
	this->tipoDeTransporte = tipoDeTransporte;
	this->direccion = direccionDeParada;

}
Estacion::Estacion(Coordenadas* coordenadas, TipoDeTransporte tipoDeTransporte){
	this->coordenadas = *coordenadas;
	this->tipoDeTransporte = tipoDeTransporte;
}

Estacion::Estacion(const Estacion &otraParada) {
	this->coordenadas = otraParada.coordenadas;
	this->linea = otraParada.linea;
	this->tipoDeTransporte = otraParada.tipoDeTransporte;
	this->direccion = otraParada.direccion;

}

Coordenadas Estacion::obtenerCoordenadas() {
	return this->coordenadas;
}
string Estacion::obtenerLinea() {
	return this->linea;
}
Estacion::TipoDeTransporte Estacion::obtenerTipoDeTransporte() {
	return this->tipoDeTransporte;
}
string Estacion::obtenerDireccion() {
	return this->direccion;
}
string Estacion::imprimirTipoDeTransporte() {

	string tipoDeTransporte;

	if (this->tipoDeTransporte == SUBTE) {
		tipoDeTransporte = "Subte";
	} else if (this->tipoDeTransporte == COLECTIVO) {
		tipoDeTransporte = "Colectivo";
	} else if (this->tipoDeTransporte == METROBUS) {
		tipoDeTransporte = "Metrobus";
	} else if (this->tipoDeTransporte == FERROCARRIL) {
		tipoDeTransporte = "Ferrocarril";
	} else if (this->tipoDeTransporte == GARAGE) {
		tipoDeTransporte = "Garage";
	}
	return tipoDeTransporte;
}

Estacion::~Estacion() {

}

