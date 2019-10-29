/*
 * ParadasCercanas.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "Parada.h"
using namespace std;

Parada::Parada(Coordenadas coordenadas, string linea,
		TipoDeTransporte tipoDeTransporte, string direccionDeParada) {
	this->coordenadas = coordenadas;
	this->linea = linea;
	this->tipoDeTransporte = tipoDeTransporte;
	this->direccion = direccionDeParada;

}
Parada::Parada(const Parada &otraParada) {
	this->coordenadas = otraParada.coordenadas;
	this->linea = otraParada.linea;
	this->tipoDeTransporte = otraParada.tipoDeTransporte;
	this->direccion = otraParada.direccion;

}
Parada::Parada() {

}
Coordenadas Parada::obtenerCoordenadas() {
	return this->coordenadas;
}
std::string Parada::obtenerLinea() {
	return this->linea;
}
Parada::TipoDeTransporte Parada::obtenerTipoDeTransporte() {
	return this->tipoDeTransporte;
}
std::string Parada::obtenerDireccion() {
	return this->direccion;
}
