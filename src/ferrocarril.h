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
	double int longitud;
	double int latitud;
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
	EstacionFerrocarril(unsigned int longitud, unsigned int latitud, unsigned int id, std::string nombre, std::string linea,
			std::string linea2, std::string ramal, std::string barrio, std::string comuna, std::string localidad,
			std::string nombreSentido, std::string partido);


};

#endif /* FERROCARRIL_H_ */
