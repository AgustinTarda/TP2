/*
 * ParadasCercanas.h
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */
//
#ifndef SRC_ESTACION_H_
#define SRC_ESTACION_H_

#include "Coordenadas.h"
#include <string>

class Estacion {
public:
	enum TipoDeTransporte {
		SUBTE, COLECTIVO, METROBUS, FERROCARRIL, GARAGE, ORIGEN, DESTINO
	};

private:
	Coordenadas coordenadas;
	std::string linea;
	TipoDeTransporte tipoDeTransporte;
	std::string direccion;

public:
	/*
	 * pre: recibe las coordenadas, la estacion, el tipo de transporte y la direccion.
	 * post: crea una instancia de estacion con los datos recibidos.
	 */
	Estacion(Coordenadas coordenadas,
			TipoDeTransporte tipoDeTransporte,std::string linea, std::string direccion);

	/*
	 * pre: recibe las coordenadas y el tipo de transporte
	 * post: crea una instancia de estacion con los datos recibidos.
	 */
	Estacion(Coordenadas* coordenadas,
			TipoDeTransporte tipoDeTransporte);

	/*
	 * pre: recibe una instancia de estacion no vacia.
	 * post: hace una copia de la estacion.
	 */
	Estacion(const Estacion &otraParada);

	/*
	 * post: devuelve las coordenadas de la instancia.
	 */
	Coordenadas obtenerCoordenadas();

	/*
	 * post: devuelve la linea de la instancia.
	 */
	std::string obtenerLinea();

	/*
	 * post: devuelve el tipo de transporte de la instancia.
	 */
	TipoDeTransporte obtenerTipoDeTransporte();

	/*
	 * post: devuelve la direccion de la instancia.
	 */
	std::string obtenerDireccion();

	/*
	 * post: imprime por pantalla el tipo de transporte de la instancia.
	 */
	std::string imprimirTipoDeTransporte();

	/*
	 * post: Se elimina la estacion.
	 */
	~Estacion();
};

#endif /* SRC_ESTACION_H_ */
