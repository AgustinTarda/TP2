/*
 * Interfaz.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include<iostream>

#include "Estacion.h"
#include "Recorrido.h"
#include "Viaje.h"
#include "DibujadorDeMapa.h"
#include "AdministradorDeRecorridos.h"

static const double PRECIO_SUBTE = 25;
static const double PRECIO_COLECTIVO = 20;
static const double PRECIO_METROBUS = 22;
static const double PRECIO_FERROCARRIL = 15;

class Interfaz {
private:

public:
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
	void imprimirViajes(Lista<Viaje*> *viajes);

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

	/*
	 * pre: las coordenadas del punto inicial, el viaje a imprimir y los recorridos de las lineas
	 * post: grafica las paradas del recorrido, la parada de subida, la de bajada y los puntos de origen y destino del usuario
	 */
	void imprimirMapaDeViajeDirecto(Coordenadas *coordenadasInicial,
			Coordenadas *coordenadasFinal, Viaje viaje,
			AdministradorDeRecorridos *administradorDeRecorridos);

	/*
	 * pre: recibe la lista de viajes posibles no vacia
	 * post: llama a la funcion de imprimir dependiendo si es un viaje directo o es combinacion
	 */
	void imprimirViajes(Coordenadas *coordenadasDeInicio,
			Coordenadas *coordenadasDeDestino,
			AdministradorDeRecorridos *administradorDeRecorridos, Viaje*viaje);

	/*
	 * pre: las coordenadas del punto inicial, el viaje a imprimir y los recorridos de las lineas
	 * post: grafica las paradas del recorrido, la parada de subida, la de bajada, las paradas de combinacion y los puntos de origes y destino del usuario
	 */
	void imprimirMapaDeViajeCombinacion(Coordenadas *coordenadasInicial,
			Coordenadas *coordenadasFinal, Viaje viaje,
			AdministradorDeRecorridos *administradorDeRecorridos);
	/*
	 * post: imprime un mensaje indicando que no hat viajes posibles
	 */
	void noSeEncontroViajesPosibles();

	/*
	 * pre: recibe una instancia de viaje
	 * post: calcula el costo del viaje
	 */
	double calcularPrecio(Viaje* viaje);

	/*
	 * pre: recibe un tipo de transporte
	 * post: devuelve el precio de ese transporte
	 *
	 */
	double obtenerCostoDelTransporte(
			Estacion::TipoDeTransporte tipoDeTransporte);

	/*
	 * pre: recibe el costo de un viaje
	 * post: imprime el costo
	 *
	 */
	void imprimirCostoViaje(double costo);

};

#endif /* SRC_INTERFAZ_H_ */
