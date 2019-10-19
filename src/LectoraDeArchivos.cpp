/*
 * lectoraDeArchivos.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: agustin
 */

#include "LectoraDeArchivos.h"
#include <fstream>

Lista<EstacionMetrobus> LectoraDeArchivos::leerEstacionesDeMetrobus(
		std::string archivosDeEstacionesDeMetrobus,
		Lista<EstacionMetrobus> listaDeEstacionesDeMetrobus) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeMetrobus.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		listaDeEstacionesDeMetrobus.agregar(leerEstacionDeMetrobus(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

	return listaDeEstacionesDeMetrobus;

}

EstacionMetrobus LectoraDeArchivos::leerEstacionDeMetrobus(
		std::ifstream &entrada) {

	std::string longitud;
	std::string latitud;
	std::string id;
	std::string nombre;
	std::string calle1;
	std::string calle2;
	std::string interseccion;
	std::string lineaSentidoNorte;
	std::string lineaSentidoSur;
	std::string metrobus;
	std::string nombreSentido;
	std::string observacion;

	std::getline(entrada, longitud, ',');
	std::getline(entrada, latitud, ',');
	std::getline(entrada, id, ',');
	std::getline(entrada, nombre, ',');
	std::getline(entrada, calle1, ',');
	std::getline(entrada, calle2, ',');
	std::getline(entrada, interseccion, ',');
	std::getline(entrada, lineaSentidoNorte, ',');
	std::getline(entrada, lineaSentidoSur, ',');
	std::getline(entrada, metrobus, ',');
	std::getline(entrada, nombreSentido, ',');
	std::getline(entrada, observacion);

	EstacionMetrobus estacionMetrobus(stod(longitud), stod(latitud), stoul(id),
			nombre, calle1, calle2, interseccion, lineaSentidoNorte,
			lineaSentidoSur, metrobus, nombreSentido, observacion);
	return estacionMetrobus;

}

