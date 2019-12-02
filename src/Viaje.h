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
	Estacion *estacionInicio;
	Estacion *estacionDestino;
	Estacion *estacionBajadaDeCombinacion;
	Estacion *estacionSubidaDeCombinacion;
	TipoDeViaje tipoDeViaje;
	Coordenadas *coordenadasIniciales;
	Coordenadas *coordenadasDestino;

public:

	/*
	 * post: crea una instancia de viaje vacia.
	 */
	Viaje();

	/*
	 * pre: el viaje es directo.
	 * post: crea una instancia de viaje con los datos recibidos.
	 */
	Viaje(unsigned int distanciaTotalACaminar, Estacion *estacionInicio,
			Estacion *EstacionDestino);

	/*
	 * pre: el viaje es con combinacion simple.
	 * post: crea una instancia de viaje con los datos recibidos.
	 */
	Viaje(unsigned int distanciaTotalACaminar, Estacion *estacionInicio,
			Estacion *EstacionDestino, Estacion *estacionBajadaDeCombinacion,
			Estacion *estacionSubidaDeCombinacion);

	/*
	 * pre: recibe una instancia de viaje no vacia.
	 * post: hace una copia del viaje.
	 */
	Viaje(const Viaje &otroViaje);

	/*
	 * post: devuelve la estacion inicial de la instancia.
	 */
	Estacion* obtenerEstacionInicial();

	/*
	 * post: devuelve la estacion de destino de la instancia.
	 */
	Estacion* obtenerEstacionDestino();

	/*
	 * post: devuelve la estacion de bajada de combinacion de la instancia.
	 */
	Estacion* obtenerEstacionBajadaDeCombinacion();

	/*
	 * post: devuelve la estacion de subida de combinacion de la instancia.
	 */
	Estacion* obtenerEstacionSubidaDeCombinacion();

	/*
	 * post: devuelve true si el viaje es directo.
	 */
	bool esDirecto();

	TipoDeViaje obtenerTipoDeViaje();

	/*
	 * post: devuelve true si el viaje es una combinacion simple.
	 */
	bool esConCombinacionSimple();

	/*
	 * post: agrega coordenadas de inicio al viaje
	 */
	void agregarCoordenadasInicio(Coordenadas *coordenadaInicial);

	/*
	 * post: agrega coordenadas de destino al viaje
	 */

	void agregarCoordenadasDestino(Coordenadas *coordenadaFinal);

	/*
	 * post: agrega la primera estacion de subida al viaje
	 */

	void agregarEstacionCercanaAInicio(Estacion *estacionCercanaAInicio);
	/*
	 * post: agrega la  estacion de bajada del primer trayecto al viaje
	 */

	void agregarEstacionBajadaDeCombinacion(
			Estacion *estacionBajadaDeCombinacion);

	/*
	 * post: agrega la  estacion de bajada en destino al viaje
	 */
	void agregarEstacionCercanaADestino(Estacion *estacionCercanaADestino);

	/*
	 * post: le agrega un tipo de viaje(combinado o directo) al viaje
	 */
	void agregarTipoDeViaje(TipoDeViaje tipoDeViaje);

	/*
	 * post: agrega la  estacion de subida del segundo trayecto al viaje
	 */

	void agregarEstacionSubidaDeCombinacion(
			Estacion *estacionSubidaDeCombinacion);

	/*
	 * post: devuelve la distancia total que hay que caminar en el viaje
	 */
	double calcularDistaciaTotalACaminar();

	/*
	 * pre: el viaje debe ser combinado
	 * post: devuelve la distancia total que hay que caminar en el viaje
	 */
	double calcularDistanciaViajeCombinado();

	/*
	 * pre: el viaje debe ser directo
	 * post: devuelve la distancia total que hay que caminar en el viaje
	 */
	double calcularDistanciaViajeDirecto();

	/*
	 * post: elimina el viaje
	 */
	~Viaje();
};

#endif /* SRC_VIAJE_H_ */
