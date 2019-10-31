/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"

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
	bool longitudEsValida = false;

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
