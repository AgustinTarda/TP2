/*
 * DibujadorDeMapa.h
 *
 *  Created on: 31 oct. 2019
 *      Author: melanie
 */

#ifndef DIBUJADORDEMAPA_H_
#define DIBUJADORDEMAPA_H_

#include "EasyBMP.h"
#include <stdlib.h>
#include <iostream>
#include "Viaje.h"

const double COORDENADA_X0 = -58.558610;
const double COORDENADA_Y0 = -34.538653;
const double DISTANCIA_PIXEL_X = 182;
const double DISTANCIA_PIXEL_Y = 380;
const double DISTANCIA_COORDENADAS_X = 0.040847;
const double DISTANCIA_COORDENADAS_Y = -0.073172;

class DibujadorDeMapa {
private:

	BMP* mapa;
	void dibujarPuntoIterativo(unsigned int xCentro, unsigned int yCentro,
			unsigned int radio, RGBApixel color);
	void dibujarLineaIterativo(unsigned int xInicial, unsigned int yInicial,
			unsigned int xFinal, unsigned int yFinal, RGBApixel color);
public:
	/* post: crea un dibujador de mapa con un mapa en blanco de "X_POR_DEFECTO" x "Y_POR_DEFECTO" pixeles */
	DibujadorDeMapa();

	/* post: crea un dibujador de mapa con una copia del mapa pasado por parametro */
	DibujadorDeMapa(BMP& mapa);

	/* post: devuelve la altura en pixeles del mapa sobre el que se esta dibujando */
	unsigned int obtenerAltura();

	/* post: devuelve el ancho en pixeles del mapa sobre el que se esta dibujando */
	unsigned int obtenerAncho();

	/* pre : "xInicial" y "xFinal" deben pertenecer al intervalo (1..dibujadorDeMapa->obtenerAncho())
	 * 		 "yInicial" y "yFinal" deben pertenecer al intervalo (1..dibujadorDeMapa->obtenerAltura())
	 *		 "rojo", "verde" y "azul deben pertenecer al intervalo (0..255)
	 * post: dibuja una linea de 1 pixel de ancho desde las coordenadas (xInicial, yInicial) hasta (xFinal, yFinal)
	 * 		 y de color (rojo, verde, azul) segun el codigo RGB de colores */

	void dibujarLinea(unsigned int xInicial, unsigned int yInicial,
			unsigned int xFinal, unsigned int yFinal, short int rojo,
			short int verde, short int azul);

	/* pre : "xCentro" debe pertenecer al intervalo (1..dibujadorDeMapa->obtenerAncho())
	 * 		 "yCentro" debe pertenecer al intervalo (1..dibujadorDeMapa->obtenerAltura())
	 * post: dibuja un punto de radio igual a "radio+1" con centro en (xCentro, yCentro)
	 * 		 y de color (rojo, verde, azul) segun el codigo RGB de colores */

	void dibujarPunto(unsigned int xCentro, unsigned int yCentro,
			unsigned int radio, short int rojo, short int verde,
			short int azul);

	/*pre: recibe una coordenada geografica.
	 *
	 * post: devuelve una coordenada un punto del bitmap para graficarlo.
	 */

	unsigned int convertidorDeCoordenadasAPixelsLongitud(Coordenadas coordenadas);

	unsigned int convertidorDeCoordenadasAPixelsLatitud(Coordenadas coordenadas);

	BMP* obtenerMapa();

	/* post: destruye el Dibujador, guardando el mapa en un archivo BMP y liberando los recursos */
	~DibujadorDeMapa();
};

#endif /* DIBUJADORDEMAPA_H_ */
