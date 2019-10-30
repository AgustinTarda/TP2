/*
 * ParadasCercanas.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "Estacion.h"
using namespace std;

Estacion::Estacion(Coordenadas coordenadas, string linea,
		TipoDeTransporte tipoDeTransporte, string direccionDeParada) {
	this->coordenadas = coordenadas;
	this->linea = linea;
	this->tipoDeTransporte = tipoDeTransporte;
	this->direccion = direccionDeParada;

}
Estacion::Estacion(const Estacion &otraParada) {
	this->coordenadas = otraParada.coordenadas;
	this->linea = otraParada.linea;
	this->tipoDeTransporte = otraParada.tipoDeTransporte;
	this->direccion = otraParada.direccion;

}
Estacion::Estacion() {

}
Coordenadas Estacion::obtenerCoordenadas() {
	return this->coordenadas;
}
std::string Estacion::obtenerLinea() {
	return this->linea;
}
Estacion::TipoDeTransporte Estacion::obtenerTipoDeTransporte() {
	return this->tipoDeTransporte;
}
std::string Estacion::obtenerDireccion() {
	return this->direccion;
}
