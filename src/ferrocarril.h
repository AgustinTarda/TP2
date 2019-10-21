/*
 * ferrocarril.h
 *
 *  Created on: 17 oct. 2019
 *      Author: rochi
 */

#ifndef FERROCARRIL_H_
#define FERROCARRIL_H_

#include <string>

class EstacionFerrocarril {

private:
	double longitud;
	double latitud;
	unsigned int id;
	std::string nombre;
	std::string linea;
	std::string linea2;
	std::string ramal;
	std::string barrio;
	std::string comuna;
	std::string localidad;
	std::string partido;

public:
	EstacionFerrocarril(double longitud, double latitud, unsigned int id,
			std::string nombre, std::string linea, std::string linea2,
			std::string ramal, std::string barrio, std::string comuna,
			std::string localidad, std::string partido);

	EstacionFerrocarril(const EstacionFerrocarril &otraEstacion);
	EstacionFerrocarril();

};

#endif /* FERROCARRIL_H_ */
