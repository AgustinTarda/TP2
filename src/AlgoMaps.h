/*
 * AlgoMaps.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_ALGOMAPS_H_
#define SRC_ALGOMAPS_H_

#include "AdministradorDeRecorridos.h"
#include "Interfaz.h"
#include <string>
#include "Estacion.h"
#include "Lista.h"
#include "LectoraDeArchivos.h"
#include "BuscadorDeViaje.h"

class AlgoMaps {
private:

	AdministradorDeRecorridos *administradorDeRecorridos;
	BuscadorDeViaje* buscadorDeViajes;
	Interfaz* interfazDeUsuario;

public:
	/*
	 * pos: devuelve una instancia de algo maps
	 */
	AlgoMaps();
	/*
	 * pos: crea y llena una lista de viaje
	 */
	void iniciarViaje();

	/*
	 * pos: filtra el viaje directo y el viaje combinado que tengan menor distancia a pie
	 */
	void filtrarMejoresViajes(Lista<Viaje*> *viajesARevisar,
			Lista<Viaje*> *mejoresViajes);

	/*
	 * pos: devuelve el viaje que pertenezca a viajes y sea de tipo de viaje tipoDeViaje que
	 * tenga menor distancia a pie
	 */
	Viaje* calcularMejorViajeDe(Viaje::TipoDeViaje tipoDeViaje,
			Lista<Viaje*> *viajes);

	/*
	 * pos: elimina la instancia de algo maps
	 */
	~AlgoMaps();

};

#endif /* SRC_ALGOMAPS_H_ */
