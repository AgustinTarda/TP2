/*
 * Coordenadas.h
 *
 *  Created on: Oct 21, 2019
 *      Author: lucas
 */

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas {

private:

	double latitudSalida;
	double longitudSalida;
	double latitudDestino;
	double longitudDestino;

public:

	Coordenadas(double latitudSalida, double longitudSalida,
				double latitudDestino, double longitudDestino);
	Coordenadas(const Coordenadas &otrasCoordenadas);
	Coordenadas();

	double getLatitudSalida();
	double getLongitudSalida();
	double getLatitudDestino();
	double getLongitudDestino();

};



#endif /* COORDENADAS_H_ */
