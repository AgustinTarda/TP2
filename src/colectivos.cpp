/*
 * colectivos.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: melanie
 */

#include "colectivos.h"

EstacionColectivo::EstacionColectivo(unsigned int id, unsigned int codigo,
		std::string nombre, double latitud, double longitud,
		unsigned int idDireccion, unsigned int idRuta, unsigned int idAgencia,
		std::string rutaNombreCorto, std::string rutaNombreLargo,
		std::string rutaDesc, unsigned int tipoRuta) {

	this->id = id;
	this->codigo = codigo;
	this->nombre = nombre;
	this->latitud = latitud;
	this->longitud = longitud;
	this->idRuta = idRuta;
	this->idAgencia = idAgencia;
	this->idDireccion = idDireccion;
	this->rutaNombreCorto = rutaNombreCorto;
	this->rutaNombreLargo = rutaNombreLargo;
	this->rutaDesc = rutaDesc;
	this->tipoRuta = tipoRuta;
}

EstacionColectivo::EstacionColectivo(const EstacionColectivo &otraEstacion) {

	this->id = otraEstacion.id;
	this->codigo = otraEstacion.codigo;
	this->nombre = otraEstacion.nombre;
	this->latitud = otraEstacion.latitud;
	this->longitud = otraEstacion.longitud;
	this->idRuta = otraEstacion.idRuta;
	this->idAgencia = otraEstacion.idAgencia;
	this->idDireccion = otraEstacion.idDireccion;
	this->rutaNombreCorto = otraEstacion.rutaNombreCorto;
	this->rutaNombreLargo = otraEstacion.rutaNombreLargo;
	this->rutaDesc = otraEstacion.rutaDesc;
	this->tipoRuta = otraEstacion.tipoRuta;

}

EstacionColectivo::EstacionColectivo() {

}

