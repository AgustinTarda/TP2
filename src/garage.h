/*
 * garage.h
 *
 *  Created on: 17 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_
#include <string>

class Garage {
private:
	double longitud;
	double latitud;
	std::string smp;
	std::string nombreDeLaCalle;
	unsigned int alturaDeLaCalle;
	std::string tipo1;
	std::string tipo2;
	unsigned int pisos;
	std::string nombre;
	std::string barrio;
	float comuna;
	unsigned int codigoPostal;
	std::string codigoPostalArgentino;
};

#endif /* SRC_GARAGE_H_ */
