/*
 * Viaje.h
 *
 *  Created on: 30 oct. 2019
 *      Author: rochi
 */
#ifndef SRC_VIAJE_H_
#define SRC_VIAJE_H_

#include "Estacion.h"
//
class Viaje {
public:
	enum TipoDeViaje {
		DIRECTO, COMBINACION_SIMPLE
	};
private:

	unsigned int distanciaTotalACaminar;
	Estacion estacionInicio;
	Estacion estacionDestino;
	Estacion estacionBajadaDeCombinacion;
	Estacion estacionSubidaDeCombinacion;
	TipoDeViaje tipoDeViaje;
	Coordenadas coordenadasIniciales;
	Coordenadas coordenadasDestino;

public:

	/*
	 * post: crea una instancia de viaje vacia.
	 */
	Viaje();

	/*
	 * pre: el viaje es directo.
	 * post: crea una instancia de viaje con los datos recibidos.
	 */
	Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio,
			Estacion EstacionDestino);

	/*
	 * pre: el viaje es con combinacion simple.
	 * post: crea una instancia de viaje con los datos recibidos.
	 */
	Viaje(unsigned int distanciaTotalACaminar, Estacion estacionInicio,
			Estacion EstacionDestino, Estacion estacionBajadaDeCombinacion,
			Estacion estacionSubidaDeCombinacion);

	/*
	 * pre: recibe una instancia de viaje no vacia.
	 * post: hace una copia del viaje.
	 */
	Viaje(const Viaje &otroViaje);

	/*
	 * post: devuelve la estacion inicial de la instancia.
	 */
	Estacion obtenerEstacionInicial();

	/*
	 * post: devuelve la estacion de destino de la instancia.
	 */
	Estacion obtenerEstacionDestino();

	/*
	 * post: devuelve la estacion de bajada de combinacion de la instancia.
	 */
	Estacion obtenerEstacionBajadaDeCombinacion();

	/*
	 * post: devuelve la estacion de subida de combinacion de la instancia.
	 */
	Estacion obtenerEstacionSubidaDeCombinacion();

	/*
	 * post: devuelve true si el viaje es directo.
	 */
	bool esDirecto();

	/*
	 * post: devuelve true si el viaje es una combinacion simple.
	 */
	bool esConCombinacionSimple();

	void agregarCoordenadasInicio(Coordenadas coordenadaInicial);

	void agregarCoordenadasDestino(Coordenadas coordenadaFinal);

	void agregarEstacionCercanaAInicio(Estacion estacionCercanaAInicio);

	void agregarEstacionBajadaDeCombinacion(Estacion estacionBajadaDeCombinacion);

	void agregarEstacionCercanaADestino(Estacion estacionCercanaADestino);

	void agregarTipoDeViaje(TipoDeViaje tipoDeViaje);

	void agregarEstacionSubidaDeCombinacion(Estacion estacionSubidaDeCombinacion);

	double calcualrDistaciaTotalACaminar();
};

#endif /* SRC_VIAJE_H_ */
