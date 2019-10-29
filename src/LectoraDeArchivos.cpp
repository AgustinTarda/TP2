/*
 * lectoraDeArchivos.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: agustin
 */

#include "LectoraDeArchivos.h"
#include <fstream>

void LectoraDeArchivos::leerEstacionesDeMetrobus(
		std::string archivosDeEstacionesDeMetrobus,
		Lista<EstacionMetrobus> &listaDeEstacionesDeMetrobus) {

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
		Lista<EstacionFerrocarril> &listaDeEstacionesDeFerrocarril) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeFerrocarril.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		listaDeEstacionesDeFerrocarril.agregar(
				leerEstacionDeFerrocarril(entrada));
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

	EstacionFerrocarril estacionFerrocarril(stod(longitud), stod(latitud),
			stoul(id), nombre, linea, linea2, ramal, barrio, comuna, localidad,
			partido);
	return estacionFerrocarril;

}

void LectoraDeArchivos::leerEstacionesDeColectivo(
		std::string archivosDeEstacionesDeColectivo,
		Lista<EstacionColectivo> &listaDeEstacionesDeColectivo) {

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

}

EstacionColectivo LectoraDeArchivos::leerEstacionDeColectivo(
		std::ifstream &entrada) {

	std::string id;
	std::string codigo;
	std::string nombre;
	std::string latitud;
	std::string longitud;
	std::string idDireccion;
	std::string numeroLinea;
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
	std::getline(entrada, numeroLinea, ',');
	std::getline(entrada, idAgencia, ',');
	std::getline(entrada, rutaNombreCorto, ',');
	std::getline(entrada, rutaNombreLargo, ',');
	std::getline(entrada, rutaDesc, ',');
	std::getline(entrada, tipoRuta, ',');

	EstacionColectivo estacionColectivo( stoul(id), stoul(codigo), nombre,
			stod(latitud), stod(longitud), stoul(idDireccion), stoul(numeroLinea), stoul(idAgencia),
					rutaNombreCorto, rutaNombreLargo, rutaDesc, stoul(tipoRuta) );

	return estacionColectivo;

}

Lista<Garage> LectoraDeArchivos::leerGarages(
		std::string archivosDeEstacionesDeSubte,
		Lista<Garage> &listaDeGarages) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeSubte.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		listaDeGarages.agregar(leerGarage(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

	return listaDeGarages;

}

Garage LectoraDeArchivos::leerGarage(std::ifstream &entrada) {

	std::string longitud;
	std::string latitud;
	std::string smp;
	std::string nombreDeLaCalle;
	std::string alturaDeLaCalle;
	std::string tipo1;
	std::string tipo2;
	std::string pisos;
	std::string nombre;
	std::string barrio;
	std::string comuna;
	std::string codigoPostal;
	std::string codigoPostalArgentino;

	std::getline(entrada, longitud, ',');
	std::getline(entrada, latitud, ',');
	std::getline(entrada, smp, ',');
	std::getline(entrada, nombreDeLaCalle, ',');
	std::getline(entrada, alturaDeLaCalle, ',');
	std::getline(entrada, tipo1, ',');
	std::getline(entrada, tipo2, ',');
	std::getline(entrada, pisos, ',');
	std::getline(entrada, nombre, ',');
	std::getline(entrada, barrio, ',');
	std::getline(entrada, comuna, ',');
	std::getline(entrada, codigoPostal, ',');
	std::getline(entrada, observacion, ',');
	std::getline(entrada, objeto, ',');
	std::getline(entrada, dominioSalida, ',');
	std::getline(entrada, codigoPostalArgentino, ',');

	Garage garage(stod(longitud), stod(latitud), smp, nombreDeLaCalle,
			stoul(alturaDeLaCalle), tipo1, tipo2, stoul(pisos), nombre, barrio,
			stof(comuna), stoul(codigoPostal), codigoPostalArgentino);

	return garage;

}

/*
 Lista<EstacionSubte> LectoraDeArchivos::leerEstacionesDeSubte(
 std::string archivosDeEstacionesDeSubte,
 Lista<EstacionSubte> listaDeEstacionesDeSubte){


 /* crea el archivo y abre la ruta especificada */
/*	std::ifstream entrada;
 entrada.open(archivosDeEstacionesDeSubte.c_str());

 /* lee la primera línea completa porque esta el formato de los campos */
/*	std::string titulo;
 std::getline(entrada, titulo);

 /* lee el resto del archivo */
/*	while (entrada.peek() != EOF) {
 listaDeEstacionesDeSubte.agregar(leerEstacionDeSubte(entrada));
 }

 /* cierra el archivo, liberando el recurso */
/*	entrada.close();

 return listaDeEstacionesDeSubte;

 }


 faltan castear los atributos bool del subte

 EstacionSubte leerEstacionDeSubte(std::ifstream &entrada){

 std::string longitud;
 std::string latitud;
 std::string id;
 std::string linea;
 std::string estacion;
 std::string numeroDeEstacion;
 std::string destino;
 std::string lineasDe;
 std::string cierraFin;
 std::string escaleraMecanica;
 std::string escaleraNoMecanica;
 std::string ascensor;
 std::string rampa;
 std::string salvaEscaleras;
 std::string calle;
 std::string altura;
 std::string calle2;
 std::string barrio;
 std::string comuna;
 std::string observacion;
 std::string objeto;
 std::string dominioSalida;
 std::string dominioOrigen;

 std::getline(entrada, longitud, ',');
 std::getline(entrada, latitud, ',');
 std::getline(entrada, id, ',');
 std::getline(entrada, linea, ',');
 std::getline(entrada, estacion, ',');
 std::getline(entrada, numeroDeEstacion, ',');
 std::getline(entrada, destino, ',');
 std::getline(entrada, lineasDe, ',');
 std::getline(entrada, cierraFin, ',');
 std::getline(entrada, escaleraMecanica, ',');
 std::getline(entrada, escaleraNoMecanica, ',');
 std::getline(entrada, ascensor, ',');
 std::getline(entrada, rampa, ',');
 std::getline(entrada, salvaEscaleras, ',');
 std::getline(entrada, calle, ',');
 std::getline(entrada, altura, ',');
 std::getline(entrada, calle2, ',');
 std::getline(entrada, barrio, ',');
 std::getline(entrada, comuna, ',');
 std::getline(entrada, observacion, ',');
 std::getline(entrada, objeto, ',');
 std::getline(entrada, dominioSalida, ',');
 std::getline(entrada, dominioOrigen, ',');

 EstacionSubte estacionDeSubte(stoul(longitud), stoul(latitud), stoul(id), linea, estacion,
 numeroDeEstacion, destino, lineasDe, cierraFin, escaleraNoMecanica, ascensor,
 rampa, salvaEscaleras, calle, stoul(altura), calle2, barrio, comuna, observacion,
 objeto, dominioSalida, dominioOrigen);

 return estacionDeSubte;
 }


EstacionSubte leerEstacionDeSubte(std::ifstream &entrada){

	std::string longitud;
	std::string latitud;
	std::string id;
	std::string numeroLinea;
	std::string estacion;
	std::string numeroDeEstacion;
	std::string destinoDeBocacalle;
	std::string lineasDe;
	std::string cierraFin;
	std::string escaleraMecanica;
	std::string escaleraNoMecanica;
	std::string ascensor;
	std::string rampa;
	std::string salvaEscaleras;
	std::string calle;
	std::string altura;
	std::string calle2;
	std::string barrio;2 conflicts ￼ Prev  ￼ Next 

	std::string comuna;
	std::string observacion;
	std::string objeto;
	std::string dominioSalida;
	std::string dominioOrigen;

	std::getline(entrada, longitud, ',');
	std::getline(entrada, latitud, ',');
	std::getline(entrada, id, ',');
	std::getline(entrada, numeroLinea, ',');
	std::getline(entrada, estacion, ',');
	std::getline(entrada, numeroDeEstacion, ',');
	std::getline(entrada, destinoDeBocacalle, ',');
	std::getline(entrada, lineasDe, ',');
329
 std::getline(entrada, observacion, ',');
330
 std::getline(entrada, objeto, ',');
331
 std::getline(entrada, dominioSalida, ',');
	std::getline(entrada, cierraFin, ',');
	std::getline(entrada, escaleraMecanica, ',');
	std::getline(entrada, escaleraNoMecanica, ',');
	std::getline(entrada, ascensor, ',');
	std::getline(entrada, rampa, ',');
	std::getline(entrada, salvaEscaleras, ',');
	std::getline(entrada, calle, ',');
	std::getline(entrada, altura, ',');
	std::getline(entrada, calle2, ',');
	std::getline(entrada, barrio, ',');
	std::getline(entrada, comuna, ',');
	std::getline(entrada, observacion, ',');
	std::getline(entrada, objeto, ',');
	std::getline(entrada, dominioSalida, ',');
	std::getline(entrada, dominioOrigen, ',');

	EstacionSubte estacionDeSubte(stoul(longitud), stoul(latitud), stoul(id), numeroLinea, estacion,
				  numeroDeEstacion, destinoDeBocacalle, lineasDe, cierraFin, escaleraNoMecanica, ascensor,
				  rampa, salvaEscaleras, calle, stoul(altura), calle2, barrio, comuna, observacion,
				  objeto, dominioSalida, dominioOrigen);

	return estacionDeSubte;
}

*/

