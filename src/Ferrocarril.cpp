/*
 * Ferrocarril.cpp
 *
 *  Created on: 19 oct. 2019
 *      Author: rochi
 */

#include "ferrocarril.h"
#include <string>

EstacionFerrocarril::EstacionFerrocarril(double longitud, double latitud,
		unsigned int id, std::string nombre, std::string linea,
		std::string linea2, std::string ramal,
		std::string barrio, std::string comuna,
		std::string localidad, std::string partido) {

	this->longitud = longitud;
	this->latitud = latitud;
	this->id = id;
	this->nombre = nombre;
	this->linea = linea;
	this->linea2 = linea2;
	this->ramal = ramal;
	this->barrio = barrio;
	this->comuna = comuna;
	this->localidad = localidad;
	this->partido = partido;
}

EstacionFerrocarril::EstacionFerrocarril(const EstacionFerrocarril &otraEstacion) {

	this->longitud = otraEstacion.longitud;
	this->latitud = otraEstacion.latitud;
	this->id = otraEstacion.id;
	this->nombre = otraEstacion.nombre;
	this->linea = otraEstacion.linea;
	this->linea2 = otraEstacion.linea2;
	this->ramal = otraEstacion.ramal;
	this->barrio = otraEstacion.barrio;
	this->comuna = otraEstacion.comuna;
	this->localidad = otraEstacion.localidad;
	this->partido = otraEstacion.partido;

}

EstacionFerrocarril::EstacionFerrocarril() {

}
