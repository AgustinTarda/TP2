/*
 * Viaje.cpp
 *
 *  Created on: 30 oct. 2019
 *      Author: rochi
 */
#include "Viaje.h"
//
Viaje::Viaje() {

}
Viaje::Viaje(unsigned int distanciaTotalACaminar, Estacion* estacionInicio,
		Estacion* EstacionDestino) {
	this->tipoDeViaje = DIRECTO;
	this->distanciaTotalACaminar = distanciaTotalACaminar;
	this->estacionInicio = estacionInicio;
	this->estacionDestino = EstacionDestino;
}

Viaje::Viaje(unsigned int distanciaTotalACaminar, Estacion* estacionInicio,
		Estacion* EstacionDestino, Estacion* estacionBajadaDeCombinacion,
		Estacion* estacionSubidaDeCombinacion) {
	this->tipoDeViaje = COMBINACION_SIMPLE;
	this->distanciaTotalACaminar = distanciaTotalACaminar;
	this->estacionInicio = estacionInicio;
	this->estacionDestino = EstacionDestino;
	this->estacionBajadaDeCombinacion = estacionBajadaDeCombinacion;
	this->estacionSubidaDeCombinacion = estacionSubidaDeCombinacion;

}

Viaje::Viaje(const Viaje &otroViaje) {
	this->tipoDeViaje = otroViaje.tipoDeViaje;
	this->distanciaTotalACaminar = otroViaje.distanciaTotalACaminar;
	this->estacionInicio = otroViaje.estacionInicio;
	this->estacionDestino = otroViaje.estacionDestino;
	this->estacionBajadaDeCombinacion = otroViaje.estacionBajadaDeCombinacion;
	this->estacionSubidaDeCombinacion = otroViaje.estacionSubidaDeCombinacion;
}
bool Viaje::esDirecto() {
	return (this->tipoDeViaje == DIRECTO);
}
Viaje::TipoDeViaje Viaje::obtenerTipoDeViaje(){
	return this->tipoDeViaje;
}
bool Viaje::esConCombinacionSimple() {
	return (this->tipoDeViaje == COMBINACION_SIMPLE);
}
Estacion* Viaje::obtenerEstacionInicial() {
	return this->estacionInicio;
}
Estacion* Viaje::obtenerEstacionDestino() {
	return this->estacionDestino;
}

Estacion* Viaje::obtenerEstacionBajadaDeCombinacion() {
	return this->estacionBajadaDeCombinacion;
}

Estacion* Viaje::obtenerEstacionSubidaDeCombinacion() {
	return this->estacionSubidaDeCombinacion;
}

void Viaje::agregarCoordenadasInicio(Coordenadas coordenadaInicial) {
	this->coordenadasIniciales = coordenadaInicial;
}

void Viaje::agregarCoordenadasDestino(Coordenadas coordenadaFinal) {
	this->coordenadasDestino = coordenadaFinal;
}

void Viaje::agregarEstacionCercanaAInicio(Estacion* estacionCercanaAInicio) {
	this->estacionInicio = estacionCercanaAInicio;
}

void Viaje::agregarEstacionBajadaDeCombinacion(
		Estacion* estacionBajadaDeCombinacion) {
	this->estacionBajadaDeCombinacion = estacionBajadaDeCombinacion;
}

void Viaje::agregarEstacionCercanaADestino(Estacion* estacionCercanaADestino) {
	this->estacionDestino = estacionCercanaADestino;
}
void Viaje::agregarTipoDeViaje(TipoDeViaje tipoDeViaje) {
	this->tipoDeViaje = tipoDeViaje;
}

void Viaje::agregarEstacionSubidaDeCombinacion(
		Estacion* estacionSubidaDeCombinacion) {
	this->estacionSubidaDeCombinacion = estacionSubidaDeCombinacion;
}
double Viaje::calcularDistaciaTotalACaminar() {
	return coordenadasIniciales.calcularDistancia(
			estacionInicio->obtenerCoordenadas())
			+ coordenadasDestino.calcularDistancia(
					estacionDestino->obtenerCoordenadas())
			+ (estacionBajadaDeCombinacion->obtenerCoordenadas()).calcularDistancia(
					(estacionSubidaDeCombinacion->obtenerCoordenadas()));
}

