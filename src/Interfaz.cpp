/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"

void Interfaz::mostrarMensajeDeBienvenida() {
	std::cout << "Bienvenidos a AlgoMaps, su buscador de viajes favorito !"
			<< std::endl << std::endl;
}

Coordenadas Interfaz::pedirCoordenadasDeInicio() {

	std::cout << "Ingrese las coordenadas de inicio" << std::endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasInicio(latitud, longitud);

	return coordenadasInicio;
}

Coordenadas Interfaz::pedirCoordenadasDeDestino() {

	std::cout << "Ingrese las coordenadas de destino" << std::endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasDestino(latitud, longitud);

	return coordenadasDestino;
}

double Interfaz::pedirLongitud() {
	double longitud;

	std::cout << "Ingrese la longitud" << std::endl;
	std::cin >> longitud;

	return longitud;
}
double Interfaz::pedirLatitud() {
	double latitud;

	std::cout << "Ingrese la latitud" << std::endl;
	std::cin >> latitud;

	return latitud;
}

void Interfaz::mostrarParada(Estacion parada) {

	std::cout << "MetroBus: " << parada.obtenerLinea() << std::endl;

}


void Interfaz::imprimirRecorridos(Lista<Recorrido*> *recorridos) {
	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor()) {
		Recorrido *recorridoAImprimir = recorridos->obtenerCursor();
		std::cout << "Recorrido: " << recorridoAImprimir->obtenerLinea()
				<< " --- " << recorridoAImprimir->obtenerTipoDeTransporte()
				<< " --- "
				<< recorridoAImprimir->obtenerEstaciones()->contarElementos()
				<< std::endl;
		//imprimirEstaciones(recorridoAImprimir->obtenerEstaciones());

	}
}

void Interfaz::imprimirEstaciones(Lista<Estacion*> *estaciones) {
	estaciones->iniciarCursor();
	while (estaciones->avanzarCursor()) {
		Estacion *estacionAImprimir = estaciones->obtenerCursor();
		std::cout << "Estacion: ---------------------------- "
				<< estacionAImprimir->obtenerDireccion() << " --- "
				<< estacionAImprimir->obtenerLinea() << " --- "
				<< estacionAImprimir->obtenerTipoDeTransporte() << std::endl;

	}
}

void Interfaz::imprimirViajes(Lista<Viaje> viajes) {
	viajes.iniciarCursor();
	while (viajes.avanzarCursor()) {
		Viaje viajeAImprimir = viajes.obtenerCursor();
		if (viajeAImprimir.esDirecto()) {
			imprimirViajeDirecto(viajeAImprimir);
		} else if (viajeAImprimir.esConCombinacionSimple()) {
			imprimirViajeConCombinacionSimple(viajeAImprimir);
		}

	}
}

void Interfaz::imprimirViajeDirecto(Viaje viajeDirecto) {
}
void Interfaz::imprimirViajeConCombinacionSimple(
		Viaje viajeConCombinacionSimple) {
}


