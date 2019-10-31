/*
 * Coordenadas.h
 *
 *  Created on: Oct 21, 2019
 *      Author: lucas
 */

#ifndef COORDENADAS_H_
#define COORDENADAS_H_


#include <math.h>
#define PI 3.14159265358979323846

class Coordenadas {

private:

	double latitud;
	double longitud;

public:

	Coordenadas(double latitud, double longitud);
	Coordenadas(const Coordenadas &otrasCoordenadas);
	Coordenadas();

	double getLatitud();
	double getLongitud();
	unsigned int calcularDistancia(const Coordenadas coordenadasFinal);

};



#endif /* COORDENADAS_H_ */
