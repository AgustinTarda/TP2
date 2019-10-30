/*
 * lectoraDeArchivos.h
 *
 *  Created on: 17 oct. 2019
 *      Author: agustin
 */

#ifndef LECTORADEARCHIVOS_H_
#define LECTORADEARCHIVOS_H_

#include <string>
#include "Lista.h"
#include "Coordenadas.h"
#include "Estacion.h"

class LectoraDeArchivos {
public:
	void leerEstacionesDeMetrobus(std::string archivosDeEstacionesDeMetrobus,
			Lista<Estacion> &estaciones);

	void leerEstacionesDeFerrocarril(
			std::string archivosDeEstacionesDeFerrocarril,
			Lista<Estacion> &estaciones);

	void leerEstacionesDeColectivo(std::string archivosDeEstacionesDeColectivo,
			Lista<Estacion> &estaciones);

	void leerGarajes(std::string archivosDeGarajes, Lista<Estacion> &paradas);

	void leerEstacionesDeSubte(std::string archivosDeEstacionesDeSubte,
			Lista<Estacion> &estaciones);

private:
	Estacion leerEstacionDeMetrobus(std::ifstream &entrada);
	Estacion leerEstacionDeColectivo(std::ifstream &entrada);
	Estacion leerEstacionDeFerrocarril(std::ifstream &entrada);
	Estacion leerEstacionDeSubte(std::ifstream &entrada);
	Estacion leerGarage(std::ifstream &entrada);
};

#endif /* LECTORADEARCHIVOS_H_ */
