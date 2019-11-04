/*
 * ParadasCercanas.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */
//
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
std::string Estacion::imprimirTipoDeTransporte(){

	std::string tipoDeTransporte;

	if(this->tipoDeTransporte == SUBTE){
		tipoDeTransporte = "Subte";
	}else if(this->tipoDeTransporte == COLECTIVO){
		tipoDeTransporte = "Colectivo";
	}else if(this->tipoDeTransporte == METROBUS){
		tipoDeTransporte = "Metrobus";
	} else if(this->tipoDeTransporte == FERROCARRIL){
		tipoDeTransporte = "Ferrocarril";
	}else if(this->tipoDeTransporte == GARAGE){
		tipoDeTransporte = "Garage";
	}
	return tipoDeTransporte;
}

