/*
 * Coordenadas.h
 *
 *  Created on: Oct 21, 2019
 *      Author: lucas
 */

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

class Coordenadas {

private:

	double latitud;
	double longitud;

public:
	/*
	 * PRE: recibe dos coordenadas geograficas
	 * POST: crea una instancia de coordenadas asignandoles los parametros recibidos a sus respectivos atributos
	 */
	Coordenadas(double latitud, double longitud);
	/*
	 * PRE: recibe una instancia de Coordenadas no vacia
	 * POST: hace una copia de la Coordenada
	 */
	Coordenadas(const Coordenadas &otrasCoordenadas);
	/*
	 * POST: crea una instancia Coordenadas con sus atributos en cero
	 */
	Coordenadas();
	/*
	 * PRE: Coordenas tiene que ser una instancia ya creada
	 * POST: devuelve la latitud de la Coordenada
	 */
	double getLatitud();
	/*
	 * PRE: Coordenas tiene que ser una instancia ya creada
	 * POST: devuelve la longitud de la Coordenada
	 */
	double getLongitud();
	/*
	 * PRE: debe existir una estacion con sus coordenadas y recibe unas coordenadas finales existentes
	 * POST: devuelve la distancia entre ambas coordenadas
	 */
	double calcularDistancia(const Coordenadas coordenadasFinal);
	/*
	 * PRE: las coordenadas deben estan en grados
	 * POST: devuelve las coordenadas en radianes
	 */
	double toRad(double degree);

};

#endif /* COORDENADAS_H_ */
