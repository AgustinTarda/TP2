/*
 * AlgoMaps.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_ALGOMAPS_H_
#define SRC_ALGOMAPS_H_

#include <string>

#include "AdministradorDeRecorridos.h"
#include "Interfaz.h"
#include "Estacion.h"
#include "Lista.h"
#include "LectoraDeArchivos.h"
#include "BuscadorDeViaje.h"
#include "DibujadorDeMapa.h"




class AlgoMaps {
private:
	Interfaz interfazDeUsuario;
	AdministradorDeRecorridos administradorDeRecorridos;
	BuscadorDeViaje buscadorDeViajes;

public:
	/*
	 * POST: devuelve una instancia de algo maps
	 */
	AlgoMaps();
	/*
	 * POST: crea y llena una lista de viaje
	 */
	void iniciarViaje();
	void imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje);
	void imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje);
};

#endif /* SRC_ALGOMAPS_H_ */
