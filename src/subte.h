/*
 * subte.h
 *
 *  Created on: 15 oct. 2019
 *      Author: rochi
 */

#ifndef SUBTE_H_
#define SUBTE_H_

#include <string>

class EstacionSubte{

private:
	unsigned int longitud;
	unsigned int latitud;
	unsigned int id;
	std:: string linea;
	std:: string estacion;
	std:: string numeroDeEstacion;
	std:: string destino;
	std:: string lineasDe;
	bool cierraFin;
	bool escaleraNoMecanica;
	bool escaleraMecanica;
	bool ascensor;
	bool rampa;
	bool salvaescaleras;
	std:: string calle;
	unsigned int altura;
	std:: string calle2;
	std:: string barrio;
	std:: string comuna;
	std:: string observacion;
	std:: string objeto;
	std:: string dominioSalida;
	std:: string dominioOrigen;

};



#endif /* SUBTE_H_ */
