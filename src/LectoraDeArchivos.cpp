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

Lista<EstacionFerrocarril> LectoraDeArchivos::leerEstacionesDeFerrocarril(
		std::string archivosDeEstacionesDeFerrocarril,
		Lista<EstacionFerrocarril> listaDeEstacionesDeFerrocarril) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeFerrocarril.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		listaDeEstacionesDeFerrocarril.agregar(leerEstacionDeFerrocarril(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

	return listaDeEstacionesDeFerrocarril;

}

EstacionFerrocarril LectoraDeArchivos::leerEstacionDeFerrocarril(
		std::ifstream &entrada) {

	std::string longitud;
	std::string latitud;
	std::string id;
	std::string nombre;
	std::string linea;
	std::string linea2;
	std::string ramal;
	std::string barrio;
	std::string comuna;
	std::string localidad;
	std::string partido;

	std::getline(entrada, longitud, ',');
	std::getline(entrada, latitud, ',');
	std::getline(entrada, id, ',');
	std::getline(entrada, nombre, ',');
	std::getline(entrada, linea, ',');
	std::getline(entrada, linea2, ',');
	std::getline(entrada, ramal, ',');
	std::getline(entrada, barrio, ',');
	std::getline(entrada, comuna, ',');
	std::getline(entrada, localidad, ',');
	std::getline(entrada, partido, ',');

	EstacionFerrocarril estacionFerrocarril(stod(longitud), stod(latitud), stoul(id),
			nombre, linea, linea2, ramal, barrio, comuna, localidad, partido);
	return estacionFerrocarril;

}

Lista<EstacionColectivo> LectoraDeArchivos::leerEstacionesDeColectivo(
		std::string archivosDeEstacionesDeColectivo,
		Lista<EstacionColectivo> listaDeEstacionesDeColectivo) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeColectivo.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		listaDeEstacionesDeColectivo.agregar(leerEstacionDeColectivo(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

	return listaDeEstacionesDeColectivo;

}

EstacionColectivo LectoraDeArchivos::leerEstacionDeColectivo(
		std::ifstream &entrada) {

	std::string id;
	std::string codigo;
	std::string nombre;
	std::string latitud;
	std::string longitud;
	std::string idDireccion;
	std::string idRuta;
	std::string idAgencia;
	std::string rutaNombreCorto;
	std::string rutaNombreLargo;
	std::string rutaDesc;
	std::string tipoRuta;

	std::getline(entrada, id, ',');
	std::getline(entrada, codigo, ',');
	std::getline(entrada, nombre, ',');
	std::getline(entrada, latitud, ',');
	std::getline(entrada, longitud, ',');
	std::getline(entrada, idDireccion, ',');
	std::getline(entrada, idRuta, ',');
	std::getline(entrada, idAgencia, ',');
	std::getline(entrada, rutaNombreCorto, ',');
	std::getline(entrada, rutaNombreLargo, ',');
	std::getline(entrada, rutaDesc, ',');
	std::getline(entrada, tipoRuta, ',');

	EstacionColectivo estacionColectivo( stoul(id), stoul(codigo), nombre,
			stod(latitud), stod(longitud), stoul(idDireccion), stoul(idRuta), stoul(idAgencia),
					rutaNombreCorto, rutaNombreLargo, rutaDesc, stoul(tipoRuta) );
	return estacionColectivo;

}

