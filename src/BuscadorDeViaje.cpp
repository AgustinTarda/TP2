/*
 * BuscadorDeViaje.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: rochi
 */

#include "BuscadorDeViaje.h"
BuscadorDeViaje::BuscadorDeViaje() {

}

void BuscadorDeViaje::buscarViaje(Coordenadas *coordenadaInicial,
		Coordenadas *coordenadaFinal,
		AdministradorDeRecorridos *administradorDeRecorridos,
		Lista<Viaje*> *viajes) {

	Lista<Estacion*> *estacionesCercanasInicio = new Lista<Estacion*>;
	Lista<Estacion*> *estacionesCercanasDestino = new Lista<Estacion*>;

	buscarEstacionesCercanas(estacionesCercanasInicio,
			estacionesCercanasDestino, coordenadaInicial, coordenadaFinal,
			administradorDeRecorridos);

	if ((!estacionesCercanasInicio->estaVacia())
			&& (!estacionesCercanasDestino->estaVacia())) {

		buscarViajesDirectosPosibles(coordenadaInicial, coordenadaFinal,
				estacionesCercanasInicio, estacionesCercanasDestino, viajes);

		buscarCombinacionesPosibles(coordenadaInicial, coordenadaFinal,
				estacionesCercanasInicio, estacionesCercanasDestino,
				administradorDeRecorridos, viajes);

	}
	delete estacionesCercanasDestino;
	delete estacionesCercanasInicio;
}

void BuscadorDeViaje::buscarEstacionesCercanas(
		Lista<Estacion*> *estacionesCercanasInicio,
		Lista<Estacion*> *estacionesCercanasDestino,
		Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	Lista<Recorrido*> *recorridos;
	recorridos = administradorDeRecorridos->obtenerRecorridos();

	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor()) {
		Recorrido *recorridoActual = recorridos->obtenerCursor();

		Lista<Estacion*> *estacionesDelRecorrido;
		estacionesDelRecorrido = recorridoActual->obtenerEstaciones();
		buscarEstacionesCercanas(estacionesCercanasInicio,
				estacionesCercanasDestino, coordenadaInicial, coordenadaFinal,
				estacionesDelRecorrido);

	}
}

void BuscadorDeViaje::buscarEstacionesCercanas(
		Lista<Estacion*> *estacionesCercanasInicio,
		Lista<Estacion*> *estacionesCercanasDestino,
		Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
		Lista<Estacion*> *estacionesDelRecorrido) {
	while (estacionesDelRecorrido->avanzarCursor()) {
		Estacion *estacionActual = estacionesDelRecorrido->obtenerCursor();

		if (coordenadaInicial->calcularDistancia(
				estacionActual->obtenerCoordenadas())
				< DISTANCIA_MAXIMA_A_CAMINAR) {
			estacionesCercanasInicio->agregar(estacionActual);

		}
		if (coordenadaFinal->calcularDistancia(
				estacionActual->obtenerCoordenadas())
				< DISTANCIA_MAXIMA_A_CAMINAR) {

			estacionesCercanasDestino->agregar(estacionActual);

		}
	}

}

void BuscadorDeViaje::buscarCombinacionesPosibles(
		Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
		Lista<Estacion*> *estacionesCercanasInicio,
		Lista<Estacion*> *estacionesCercanasDestino,
		AdministradorDeRecorridos *administradorDeRecorridos,
		Lista<Viaje*> *viajesPosibles) {

	Viaje posibleViajeConCombinacion;
	posibleViajeConCombinacion.agregarCoordenadasInicio(coordenadaInicial);
	posibleViajeConCombinacion.agregarCoordenadasDestino(coordenadaFinal);
	posibleViajeConCombinacion.agregarTipoDeViaje(Viaje::COMBINACION_SIMPLE);

	estacionesCercanasInicio->iniciarCursor();
	while (estacionesCercanasInicio->avanzarCursor()) {

		Estacion *estacionCercanaAInicio =
				estacionesCercanasInicio->obtenerCursor();

		posibleViajeConCombinacion.agregarEstacionCercanaAInicio(
				estacionCercanaAInicio);

		Recorrido *recorridoDeEstacionInicial =
				administradorDeRecorridos->obtenerRecorridoAlQuePertenece(
						estacionCercanaAInicio);

		Lista<Estacion*> *estacionesDelRecorridoInicial;
		estacionesDelRecorridoInicial =
				recorridoDeEstacionInicial->obtenerEstaciones();

		estacionesDelRecorridoInicial->iniciarCursor();
		while (estacionesDelRecorridoInicial->avanzarCursor()) {
			Estacion *estacionActualDeRecorridoInicial;
			estacionActualDeRecorridoInicial =
					estacionesDelRecorridoInicial->obtenerCursor();

			posibleViajeConCombinacion.agregarEstacionBajadaDeCombinacion(
					estacionActualDeRecorridoInicial);

			analizarSiTieneCombinacionConDestino(administradorDeRecorridos,
					estacionesCercanasDestino, posibleViajeConCombinacion,
					viajesPosibles);
		}

	}
}

void BuscadorDeViaje::analizarSiTieneCombinacionConDestino(
		AdministradorDeRecorridos *administradorDeRecorridos,
		Lista<Estacion*> *estacionesCercanasDestino,
		Viaje &posibleViajeConCombinacion, Lista<Viaje*> *viajesPosibles) {

	Recorrido *recorridoDeEstacionFinal;
	bool combinacionEncontrada = false;

	estacionesCercanasDestino->iniciarCursor();
	while (estacionesCercanasDestino->avanzarCursor() && !combinacionEncontrada) {

		Estacion *estacionCercanaADestino =
				estacionesCercanasDestino->obtenerCursor();

		posibleViajeConCombinacion.agregarEstacionCercanaADestino(
				estacionCercanaADestino);

		if ((posibleViajeConCombinacion.obtenerEstacionBajadaDeCombinacion())->obtenerLinea()
				!= estacionCercanaADestino->obtenerLinea()) {
			recorridoDeEstacionFinal =
					administradorDeRecorridos->obtenerRecorridoAlQuePertenece(
							estacionCercanaADestino);
			Lista<Estacion*> *estacionesDelRecorridoFinal;
			estacionesDelRecorridoFinal =
					recorridoDeEstacionFinal->obtenerEstaciones();

			analizarCombinacionEntreEstaciones(posibleViajeConCombinacion,
					estacionesDelRecorridoFinal, viajesPosibles,
					&combinacionEncontrada);
		}

	}
}
void BuscadorDeViaje::analizarCombinacionEntreEstaciones(
		Viaje &posibleViajeConCombinacion,
		Lista<Estacion*> *estacionesDelRecorridoFinal,
		Lista<Viaje*> *viajesPosibles, bool *combinacionEncontrada) {

	estacionesDelRecorridoFinal->iniciarCursor();

	while (estacionesDelRecorridoFinal->avanzarCursor()) {

		Estacion *estacionActualDeRecorridoFinal =
				estacionesDelRecorridoFinal->obtenerCursor();

		posibleViajeConCombinacion.agregarEstacionSubidaDeCombinacion(
				estacionActualDeRecorridoFinal);

		Coordenadas coordenadasEstacionActualInicial =
				(posibleViajeConCombinacion.obtenerEstacionBajadaDeCombinacion())->obtenerCoordenadas();
		double distanciaEntreCombinacion =
				coordenadasEstacionActualInicial.calcularDistancia(
						(posibleViajeConCombinacion.obtenerEstacionSubidaDeCombinacion())->obtenerCoordenadas());

		if (distanciaEntreCombinacion < DISTANCIA_MAXIMA_A_CAMINAR) {

			Viaje *viajeConCombinacion = new Viaje(posibleViajeConCombinacion);
			*combinacionEncontrada = true;

			viajesPosibles->agregar(viajeConCombinacion);
		}
	}
}

void BuscadorDeViaje::buscarViajesDirectosPosibles(
		Coordenadas *coordenadaInicial, Coordenadas *coordenadaFinal,
		Lista<Estacion*> *estacionesCercanasInicio,
		Lista<Estacion*> *estacionesCercanasDestino,
		Lista<Viaje*> *viajesPosibles) {

	bool encontroViajeDirecto = false;
	estacionesCercanasInicio->iniciarCursor();
	estacionesCercanasDestino->iniciarCursor();

	while (estacionesCercanasInicio->avanzarCursor()) {
		Estacion *estacionCercanaAInicio =
				estacionesCercanasInicio->obtenerCursor();

		while (estacionesCercanasDestino->avanzarCursor()
				&& (!encontroViajeDirecto)) {

			Estacion *estacionCercanaADestino =
					estacionesCercanasDestino->obtenerCursor();

			if (estacionCercanaAInicio->obtenerLinea()
					== estacionCercanaADestino->obtenerLinea()) {

				unsigned int distanciaACaminar =
						coordenadaInicial->calcularDistancia(
								estacionCercanaAInicio->obtenerCoordenadas())
								+ coordenadaFinal->calcularDistancia(
										estacionCercanaADestino->obtenerCoordenadas());

				Viaje *viajeActual = new Viaje(distanciaACaminar,
						estacionCercanaAInicio, estacionCercanaADestino);
				viajeActual->agregarCoordenadasInicio(coordenadaInicial);
				viajeActual->agregarCoordenadasDestino(coordenadaFinal);
				viajesPosibles->agregar(viajeActual);

				encontroViajeDirecto = true;
			}
		}
	}
}
void BuscadorDeViaje::mejorViajeConGrafo(Lista<Viaje*>* viajes) {

	Grafo* grafo = new Grafo;
	Viaje* viaje = viajes->obtener(1);

	Estacion* origen = new Estacion(viaje->obtenerCoordenadaInicial(),
			Estacion::ORIGEN);
	Estacion* destino = new Estacion(viaje->obtenerCoordenadaDestino(),
			Estacion::DESTINO);
	Coordenadas* coordenadasOrigen = viaje->obtenerCoordenadaInicial();

	grafo->insertarVertice(origen);

	viajes->iniciarCursor();
	while (viajes->avanzarCursor()) {
		Viaje* viajeActual = viajes->obtenerCursor();

		Estacion* estacionInicial = viajeActual->obtenerEstacionInicial();
		Estacion* estacionFinal = viajeActual->obtenerEstacionDestino();

		grafo->insertarVertice(estacionInicial,
				grafo->obtenerVerticeQueContiene(origen),
				coordenadasOrigen->calcularDistancia(
						estacionInicial->obtenerCoordenadas()));

		if (viaje->obtenerTipoDeViaje() == Viaje::DIRECTO) {
			agregarViajeDirectoAGrafo(grafo, estacionFinal, estacionInicial,
					origen, destino);

		} else {
			agregarViajeCombinadoAGrafo(viajeActual, grafo, estacionFinal,
					estacionInicial, origen, destino);
		}
	}
}

void BuscadorDeViaje::agregarViajeDirectoAGrafo(Grafo* grafo,
		Estacion* estacionFinal, Estacion* estacionInicial, Estacion* origen,
		Estacion* destino) {
	Coordenadas coordenadasEstacionInicial =
			estacionInicial->obtenerCoordenadas();
	Coordenadas coordenadasEstacionFinal = estacionFinal->obtenerCoordenadas();

	grafo->insertarVertice(estacionFinal,
			grafo->obtenerVerticeQueContiene(estacionInicial),
			coordenadasEstacionInicial.calcularDistancia(
					coordenadasEstacionFinal));
	grafo->insertarVertice(destino,
			grafo->obtenerVerticeQueContiene(estacionFinal),
			coordenadasEstacionFinal.calcularDistancia(
					destino->obtenerCoordenadas()));

}

void BuscadorDeViaje::agregarViajeCombinadoAGrafo(Viaje* viajeActual,
		Grafo* grafo, Estacion* estacionFinal, Estacion* estacionInicial,
		Estacion* origen, Estacion* destino) {

	Estacion* CombinacionBajada =
			viajeActual->obtenerEstacionBajadaDeCombinacion();
	Estacion* CombinacionSubida =
			viajeActual->obtenerEstacionSubidaDeCombinacion();
	Coordenadas coordenadasCombinacionBajada =
			CombinacionBajada->obtenerCoordenadas();
	Coordenadas coordenadasCombinacionSubida =
			CombinacionSubida->obtenerCoordenadas();
	Coordenadas coordenadasEstacionInicial =
			estacionInicial->obtenerCoordenadas();
	Coordenadas coordenadasEstacionFinal = estacionFinal->obtenerCoordenadas();

	grafo->insertarVertice(CombinacionBajada,
			grafo->obtenerVerticeQueContiene(estacionInicial),
			coordenadasEstacionInicial.calcularDistancia(
					coordenadasCombinacionBajada));

	grafo->insertarVertice(CombinacionSubida,
			grafo->obtenerVerticeQueContiene(CombinacionBajada),
			coordenadasCombinacionBajada.calcularDistancia(
					coordenadasCombinacionSubida));

	grafo->insertarVertice(estacionFinal,
			grafo->obtenerVerticeQueContiene(CombinacionSubida),
			coordenadasCombinacionSubida.calcularDistancia(
					coordenadasEstacionFinal));

	grafo->insertarVertice(destino,
			grafo->obtenerVerticeQueContiene(estacionFinal),
			coordenadasEstacionFinal.calcularDistancia(
					destino->obtenerCoordenadas()));
}

