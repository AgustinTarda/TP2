/*
 * garage.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: agustin
 */
#include "garage.h"

Garage::Garage(double longitud, double latitud, std::string smp, std::string nombreDeLaCalle,
		unsigned int alturaDeLaCalle, std::string tipo1, std::string tipo2, unsigned int pisos,
		std::string nombre, std::string barrio, float comuna, unsigned int codigoPostal,
		std::string codigoPostalArgentino){

	this->longitud = longitud;
	this->latitud = latitud;
	this->smp = smp;
	this->nombreDeLaCalle = nombreDeLaCalle;
	this->alturaDeLaCalle = alturaDeLaCalle;
	this->tipo1 = tipo1;
	this->tipo2 = tipo2;
	this->pisos = pisos;
	this->nombre = nombre;
	this->barrio = barrio;
	this->comuna = comuna;
	this->codigoPostal = codigoPostal;
	this->codigoPostalArgentino = codigoPostalArgentino;

}

Garage::Garage(const Garage &otroGarage){

	this->longitud = otroGarage.longitud;
	this->latitud = otroGarage.latitud;
	this->smp = otroGarage.smp;
	this->nombreDeLaCalle = otroGarage.nombreDeLaCalle;
	this->alturaDeLaCalle = otroGarage.alturaDeLaCalle;
	this->tipo1 = otroGarage.tipo1;
	this->tipo2 = otroGarage.tipo2;
	this->pisos = otroGarage.pisos;
	this->nombre = otroGarage.nombre;
	this->barrio = otroGarage.barrio;
	this->comuna = otroGarage.comuna;
	this->codigoPostal = otroGarage.codigoPostal;
	this->codigoPostalArgentino = otroGarage.codigoPostalArgentino;

}

Garage::Garage(){

}

