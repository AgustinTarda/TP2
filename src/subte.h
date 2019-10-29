/*
 * subte.h
 *
 *  Created on: 15 oct. 2019
 *      Author: rochi
 */

#ifndef SUBTE_H_
#define SUBTE_H_

#include <string>

class EstacionSubte {

private:
	unsigned int longitud;
	unsigned int latitud;
	unsigned int id;
	std::string linea;
	std::string estacion;
	std::string numeroDeEstacion;
	std::string destinoDeBocacalle;
	std::string lineasDeCombinacion;
	bool cierraFin;
	bool escaleraNoMecanica;
	bool escaleraMecanica;
	bool ascensor;
	bool rampa;
	bool salvaescaleras;
	std::string calle;
	unsigned int altura;
	std::string calle2;
	std::string barrio;
	std::string comuna;
	std::string observacion;
	std::string objeto;
	std::string dominioSalida;
	std::string dominioOrigen;

public:
	EstacionSubte(unsigned int longitud, unsigned int latitud, unsigned int id,
			std::string linea, std::string estacion,
			std::string numeroDeEstacion, std::string destinoDeBocacalle,
			std::string lineasDeCombinacion, bool cierraFin, bool escaleraNoMecanica,
			bool escaleraMecanica, bool ascensor, bool rampa,
			bool salvaescaleras, std::string calle, unsigned int altura,
			std::string calle2, std::string barrio, std::string comuna,
			std::string observacion, std::string objeto,
			std::string dominioSalida, std::string dominioOrigen);
	EstacionSubte(const EstacionSubte &otraEstacion);
	EstacionSubte();

};

#endif /* SUBTE_H_ */
