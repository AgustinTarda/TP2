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

class Interfaz {
private:
public:
	void mostrarMensajeDeBienvenida();
	Coordenadas pedirCoordenadasDeInicio();
	Coordenadas pedirCoordenadasDeDestino();
	double pedirLongitud();
	double pedirLatitud();
	void mostrarParada(Estacion parada);
	void imprimirRecorridos(Lista<Recorrido*> *recorridos);
	void imprimirEstaciones(Lista<Estacion*> *estaciones);
	void imprimirViajes(Coordenadas coordenadasDeInicio,Coordenadas coordenadasDeDestino, AdministradorDeRecorridos administradorDeRecorridos, Lista<Viaje> viajes);
	void imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);
	void imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje, AdministradorDeRecorridos administradorDeRecorridos);

	void imprimirViajeDirecto(Viaje viajeDirecto);
	void imprimirViajeConCombinacionSimple(Viaje viajeConCombinacionSimple);

	void graficarParadasEnMapa(Recorrido recorrido);

};

#endif /* SRC_INTERFAZ_H_ */
