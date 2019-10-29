/*
 * colectivos.h
 *
 *  Created on: 17 oct. 2019
 *      Author: melanie
 */

#ifndef SRC_COLECTIVOS_H_
#define SRC_COLECTIVOS_H_

#include <string>

class EstacionColectivo {
private:
	unsigned int id;
	unsigned int codigo;
	std::string nombre;
	double latitud;
	double longitud;
	unsigned int idDireccion;
	unsigned int numeroLinea;
	unsigned int idAgencia;
	std::string rutaNombreCorto;
	std::string rutaNombreLargo;
	std::string rutaDesc;
	unsigned int tipoRuta;

public:
	EstacionColectivo(unsigned int id, unsigned int codigo, std::string nombre,
			double latitud, double longitud, unsigned int idDireccion,
			unsigned int numeroLinea, unsigned int idAgencia,
			std::string rutaNombreCorto, std::string rutaNombreLargo,
			std::string rutaDesc, unsigned int tipoRuta);
	EstacionColectivo(const EstacionColectivo &otraEstacion);
	EstacionColectivo();
	std::string obtenerNombre();

};

#endif /* SRC_COLECTIVOS_H_ */
