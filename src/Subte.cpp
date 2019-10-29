/*
 * Subte.cpp
 *
 *  Created on: 21 oct. 2019
 *      Author: rochi
 */

#include "subte.h"

EstacionSubte::EstacionSubte(unsigned int longitud, unsigned int latitud,
		unsigned int id, std::string linea, std::string estacion,
		std::string numeroDeEstacion, std::string destinoDeBocacalle, std::string lineasDeCombinacion,
		bool cierraFin, bool escaleraNoMecanica, bool escaleraMecanica,
		bool ascensor, bool rampa, bool salvaescaleras, std::string calle,
		unsigned int altura, std::string calle2, std::string barrio,
		std::string comuna, std::string observacion, std::string objeto,
		std::string dominioSalida, std::string dominioOrigen) {

	this->longitud = longitud;
	this->latitud = latitud;
	this->id = id;
	this->linea = linea;
	this->estacion = estacion;
	this->numeroDeEstacion = numeroDeEstacion;
	this->destinoDeBocacalle = destinoDeBocacalle;
	this->lineasDeCombinacion = lineasDeCombinacion;
	this->cierraFin = cierraFin;
	this->escaleraNoMecanica = escaleraNoMecanica;
	this->escaleraMecanica = escaleraMecanica;
	this->ascensor = ascensor;
	this->rampa = rampa;
	this->salvaescaleras = salvaescaleras;
	this->calle = calle;
	this->altura = altura;
	this->calle2 = calle2;
	this->barrio = barrio;
	this->comuna = comuna;
	this->observacion = observacion;
	this->objeto = objeto;
	this->dominioSalida = dominioSalida;
	this->dominioOrigen = dominioOrigen;

}
EstacionSubte::EstacionSubte(const EstacionSubte &otraEstacion) {
	this->longitud = otraEstacion.longitud;
	this->latitud = otraEstacion.latitud;
	this->id = otraEstacion.id;
	this->linea = otraEstacion.linea;
	this->estacion = otraEstacion.estacion;
	this->numeroDeEstacion = otraEstacion.numeroDeEstacion;
	this->destinoDeBocacalle = otraEstacion.destinoDeBocacalle;
	this->lineasDeCombinacion = otraEstacion.lineasDeCombinacion;
	this->cierraFin = otraEstacion.cierraFin;
	this->escaleraNoMecanica = otraEstacion.escaleraNoMecanica;
	this->escaleraMecanica = otraEstacion.escaleraMecanica;
	this->ascensor = otraEstacion.ascensor;
	this->rampa = otraEstacion.rampa;
	this->salvaescaleras = otraEstacion.salvaescaleras;
	this->calle = otraEstacion.calle;
	this->altura = otraEstacion.altura;
	this->calle2 = otraEstacion.calle2;
	this->barrio = otraEstacion.barrio;
	this->comuna = otraEstacion.comuna;
	this->observacion = otraEstacion.observacion;
	this->objeto = otraEstacion.objeto;
	this->dominioSalida = otraEstacion.dominioSalida;
	this->dominioOrigen = otraEstacion.dominioOrigen;

}
EstacionSubte::EstacionSubte() {

}

