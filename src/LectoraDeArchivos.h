#ifndef LECTORADEARCHIVOS_H_
#define LECTORADEARCHIVOS_H_

#include <string>
#include "Lista.h"
#include "Coordenadas.h"
#include "Estacion.h"
#include "AdministradorDeRecorridos.h"

class LectoraDeArchivos {
public:
	void leerEstacionesDeMetrobus(std::string archivosDeEstacionesDeMetrobus,
			AdministradorDeRecorridos administradorDeRecorridos);

	void leerEstacionesDeFerrocarril(
			std::string archivosDeEstacionesDeFerrocarril,
			AdministradorDeRecorridos administradorDeRecorridos);

	void leerEstacionesDeColectivo(std::string archivosDeEstacionesDeColectivo,
			AdministradorDeRecorridos administradorDeRecorridos);

	void leerGarajes(std::string archivosDeGarajes,
			AdministradorDeRecorridos administradorDeRecorridos);

	void leerEstacionesDeSubte(std::string archivosDeEstacionesDeSubte,
			AdministradorDeRecorridos administradorDeRecorridos);

private:
	Estacion leerEstacionDeMetrobus(std::ifstream &entrada);
	Estacion leerEstacionDeColectivo(std::ifstream &entrada);
	Estacion leerEstacionDeFerrocarril(std::ifstream &entrada);
	Estacion leerEstacionDeSubte(std::ifstream &entrada);
	Estacion leerGarage(std::ifstream &entrada);
};

#endif /* LECTORADEARCHIVOS_H_ */
