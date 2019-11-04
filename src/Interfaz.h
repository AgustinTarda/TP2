/*
 * Interfaz.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include <iostream>

#include "Estacion.h"
#include "Recorrido.h"
#include "Viaje.h"
#include "DibujadorDeMapa.h"
#include "AdministradorDeRecorridos.h"

class Interfaz {
private:
public:

	Interfaz();
	/*
	 * post: muestra el mensaje de bienvenida.
	 */
	void mostrarMensajeDeBienvenida();

	/*
	 * post: pide las coordenadas de inicio y las guarda en una instancia de coordenadas.
	 */
	Coordenadas pedirCoordenadasDeInicio();

	/*
	 * post: pide las coordenadas de destino y las guarda en una instancia de coordenadas.
	 */
	Coordenadas pedirCoordenadasDeDestino();

	/*
	 * post: pide una longitud y la devuelve.
	 */
	double pedirLongitud();

	/*
	 * post: pide una latitud y la devuelve.
	 */
	double pedirLatitud();

	/*
	 * pre: recibe una parada como parametro.
	 * post: muesta la parada recibida.
	 */
	void mostrarParada(Estacion parada);

	/*
	 * pre: recibe una lista de recorridos.
	 * post: imprime los datos de los recorridos por pantalla.
	 */
	void imprimirRecorridos(Lista<Recorrido*> *recorridos);

	/*
	 * pre: recibe una lista de estaciones.
	 * post: imprime los datos de las estaciones por pantalla.
	 */
	void imprimirEstaciones(Lista<Estacion*> *estaciones);

	/*
	 * pre: recibe una lista de viajes.
	 * post: imprime los datos de los viajes por pantalla.
	 */
	void imprimirViajes(Coordenadas coordenadasDeInicio,Coordenadas coordenadasDeDestino, AdministradorDeRecorridos administradorDeRecorridos, Lista<Viaje> viajes);


	void imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);


	void imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);
	/*
	 * pre: recibe un viaje directo.
	 * post: imprime los datos del viaje directo por pantalla.
	 */
	void imprimirViajeDirecto(Viaje viajeDirecto);

	/*
	 * pre: recibe un viaje con combinacion simple
	 * post: imprime los datos del viaje con combinacion simple por pantalla.
	 */
	void imprimirViajeConCombinacionSimple(Viaje viajeConCombinacionSimple);

	void imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);

	void imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);
	/*
	 * pre: recibe un recorrido.
	 * post: grafica el recorrido en el mapa.
	 */
	void graficarParadasEnMapa(Recorrido recorrido);

	void imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial,
			Coordenadas coordenadasFinal, Viaje viaje,
			AdministradorDeRecorridos administradorDeRecorridos);

	void imprimirViajes(Coordenadas coordenadasDeInicio,
			Coordenadas coordenadasDeDestino,
			AdministradorDeRecorridos administradorDeRecorridos,
			Lista<Viaje> viajes);

	void imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial,
			Coordenadas coordenadasFinal, Viaje viaje,
			AdministradorDeRecorridos administradorDeRecorridos);
};

#endif /* SRC_INTERFAZ_H_ */
