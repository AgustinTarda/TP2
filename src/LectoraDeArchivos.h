#ifndef LECTORADEARCHIVOS_H_
#define LECTORADEARCHIVOS_H_

#include <string>
#include "Lista.h"
#include "Coordenadas.h"
#include "Estacion.h"
#include "AdministradorDeRecorridos.h"

class LectoraDeArchivos {
public:

	/*
	 * post: lee el archivo de estaciones de metrobus y las agrega al administrador de recorridos.
	 */
	void leerEstacionesDeMetrobus(std::string archivosDeEstacionesDeMetrobus,
			AdministradorDeRecorridos* administradorDeRecorridos);

	/*
	 * post: lee el archivo de estaciones de ferrocarril y las agrega al administrador de recorridos.
	 */
	void leerEstacionesDeFerrocarril(
			std::string archivosDeEstacionesDeFerrocarril,
			AdministradorDeRecorridos* administradorDeRecorridos);

	/*
	 * post: lee el archivo de estaciones de colectivo y las agrega al administrador de recorridos.
	 */
	void leerEstacionesDeColectivo(std::string archivosDeEstacionesDeColectivo,
			AdministradorDeRecorridos* administradorDeRecorridos);

	/*
	 * post: lee el archivo de garages y los agrega al administrador de recorridos.
	 */
	void leerGarajes(std::string archivosDeGarajes,
			AdministradorDeRecorridos* administradorDeRecorridos);

	/*
	 * post: lee el archivo de estaciones de subte y las agrega al administrador de recorridos.
	 */

	void leerEstacionesDeSubte(std::string archivosDeEstacionesDeSubte,
			AdministradorDeRecorridos* administradorDeRecorridos);

private:
	/*
	 * post: lee una linea del archivo de estaciones de metrobus.
	 */
	Estacion leerEstacionDeMetrobus(std::ifstream &entrada);

	/*
	 * post: lee una linea del archivo de estaciones de colectivo.
	 */
	Estacion leerEstacionDeColectivo(std::ifstream &entrada);

	/*
	 * post: lee una linea del archivo de estaciones de ferrocarril.
	 */
	Estacion leerEstacionDeFerrocarril(std::ifstream &entrada);

	/*
	 * post: lee una linea del archivo de estaciones de subte.
	 */
	Estacion leerEstacionDeSubte(std::ifstream &entrada);

	/*
	 * post: lee una linea del archivo de garages.
	 */
	Estacion leerGarage(std::ifstream &entrada);
};

#endif /* LECTORADEARCHIVOS_H_ */
