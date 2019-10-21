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

class LectoraDeArchivos {
public:
	Lista<EstacionMetrobus> leerEstacionesDeMetrobus(
			std::string archivosDeEstacionesDeMetrobus,
			Lista<EstacionMetrobus> listaDeEstacionesDeMetrobus);

	EstacionMetrobus leerEstacionDeMetrobus(std::ifstream &entrada);

	Lista<EstacionFerrocarril> leerEstacionesDeFerrocarril(
				std::string archivosDeEstacionesDeFerrocarril,
				Lista<EstacionFerrocarril> listaDeEstacionesDeFerrocarril);

	EstacionFerrocarril leerEstacionDeFerrocarril(std::ifstream &entrada);


	Lista<EstacionColectivo> leerEstacionesDeColectivo(
					std::string archivosDeEstacionesDeColectivo,
					Lista<EstacionColectivo> listaDeEstacionesDeColectivo);

	EstacionColectivo leerEstacionDeColectivo(std::ifstream &entrada);

	Lista<Garage> leerGarages(
			std::string archivosDeGarage,
			Lista<Garage> listaDeGarages);

	Garage leerGarage(std::ifstream &entrada);

	Lista<EstacionSubte> leerEstacionesDeSubte(
			std::string archivosDeEstacionesDeSubte,
			Lista<EstacionSubte> listaDeEstacionesSubte);

	EstacionSubte leerEstacionDeSubte(std::ifstream &entrada);

};

#endif /* LECTORADEARCHIVOS_H_ */
