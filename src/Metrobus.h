/*
 * metrobus.h
 *
 *  Created on: 11 oct. 2019
 *      Author: rochi
 */

#ifndef SRC_METROBUS_H_
#define SRC_METROBUS_H_

#include <string>

class EstacionMetrobus {

private:
	double longitud;
	double latitud;
	unsigned int id;
	std::string nombre;
	std::string calle1;
	std::string calle2;
	std::string interseccion;
	std::string lineaSentidoNorte;
	std::string lineaSentidoSur;
	std::string metrobus;
	std::string nombreSentido;
	std::string observacion;

public:
	EstacionMetrobus(double longitud, double latitud, unsigned int id,
			std::string nombre, std::string calle1, std::string calle2,
			std::string interseccion, std::string lineaSentidoNorte,
			std::string lineaSentidoSur, std::string metrobus,
			std::string nombreSentido, std::string observacion);
	EstacionMetrobus(const EstacionMetrobus &otraEstacion);
	EstacionMetrobus();
	std::string obtenerNombre();
};

#endif /* SRC_METROBUS_H_ */
