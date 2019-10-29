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
	void leerEstacionesDeMetrobus(std::string archivosDeEstacionesDeMetrobus,
			Lista<EstacionMetrobus> &listaDeEstacionesDeMetrobus);

	Lista<EstacionFerrocarril> leerEstacionesDeFerrocarril(
			std::string archivosDeEstacionesDeFerrocarril,
			Lista<EstacionFerrocarril> &listaDeEstacionesDeFerrocarril);

	void leerEstacionesDeColectivo(std::string archivosDeEstacionesDeColectivo,
			Lista<EstacionColectivo> &listaDeEstacionesDeColectivo);

	Lista<Garage> leerGarages(std::string archivosDeGarage,
			Lista<Garage> &listaDeGarages);

	Lista<EstacionSubte> leerEstacionesDeSubte(
			std::string archivosDeEstacionesDeSubte,
			Lista<EstacionSubte> &listaDeEstacionesSubte);

private:
	EstacionMetrobus leerEstacionDeMetrobus(std::ifstream &entrada);
	EstacionColectivo leerEstacionDeColectivo(std::ifstream &entrada);
	EstacionFerrocarril leerEstacionDeFerrocarril(std::ifstream &entrada);
	EstacionSubte leerEstacionDeSubte(std::ifstream &entrada);
	Garage leerGarage(std::ifstream &entrada);
};

#endif /* LECTORADEARCHIVOS_H_ */
