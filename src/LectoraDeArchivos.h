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
#include "Metrobus.h"
#include "ferrocarril.h"
#include "colectivos.h"
#include "subte.h"
#include "garage.h"
#include "Parada.h"
#include "Coordenadas.h"

class LectoraDeArchivos {
public:
	void leerEstacionesDeMetrobus(std::string archivosDeEstacionesDeMetrobus,
			Lista<Parada> &paradas);

	void leerEstacionesDeFerrocarril(
			std::string archivosDeEstacionesDeFerrocarril,
			Lista<Parada> &paradas);

	void leerEstacionesDeColectivo(std::string archivosDeEstacionesDeColectivo,
			Lista<Parada> &paradas);

	void leerGarajes(std::string archivosDeGarajes, Lista<Parada> &paradas);

	void leerEstacionesDeSubte(std::string archivosDeEstacionesDeSubte,
			Lista<Parada> &paradas);

private:
	Parada leerEstacionDeMetrobus(std::ifstream &entrada);
	Parada leerEstacionDeColectivo(std::ifstream &entrada);
	Parada leerEstacionDeFerrocarril(std::ifstream &entrada);
	Parada leerEstacionDeSubte(std::ifstream &entrada);
	Parada leerGarage(std::ifstream &entrada);
};

#endif /* LECTORADEARCHIVOS_H_ */
