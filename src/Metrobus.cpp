/*
 * mestrobus.cpp
 *
 *  Created on: 11 oct. 2019
 *      Author: agustin
 */

#include <string>
#include "Metrobus.h"

EstacionMetrobus::EstacionMetrobus(double longitud, double latitud,
		unsigned int id, std::string nombre, std::string calle1,
		std::string calle2, std::string interseccion,
		std::string lineaSentidoNorte, std::string lineaSentidoSur,
		std::string metrobus, std::string nombreSentido,
		std::string observacion) {

	this->longitud = longitud;
	this->latitud = latitud;
	this->id = id;
	this->nombre = nombre;
	this->calle1 = calle1;
	this->calle2 = calle2;
	this->interseccion = interseccion;
	this->lineaSentidoNorte = lineaSentidoNorte;
	this->lineaSentidoSur = lineaSentidoSur;
	this->metrobus = metrobus;
	this->nombreSentido = nombreSentido;
	this->observacion = observacion;
}

EstacionMetrobus::EstacionMetrobus(const EstacionMetrobus &otraEstacion) {

	this->longitud = otraEstacion.longitud;
	this->latitud = otraEstacion.latitud;
	this->id = otraEstacion.id;
	this->nombre = otraEstacion.nombre;
	this->calle1 = otraEstacion.calle1;
	this->calle2 = otraEstacion.calle2;
	this->interseccion = otraEstacion.interseccion;
	this->lineaSentidoNorte = otraEstacion.lineaSentidoNorte;
	this->lineaSentidoSur = otraEstacion.lineaSentidoSur;
	this->metrobus = otraEstacion.metrobus;
	this->nombreSentido = otraEstacion.nombreSentido;
	this->observacion = otraEstacion.observacion;

}

EstacionMetrobus::EstacionMetrobus() {

}

