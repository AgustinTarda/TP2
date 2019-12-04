#include "LectoraDeArchivos.h"
#include <fstream>
using namespace std;

void LectoraDeArchivos::leerEstacionesDeMetrobus(
		string archivosDeEstacionesDeMetrobus,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;
	entrada.open(archivosDeEstacionesDeMetrobus.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	string titulo;
	getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos->agregarEstacion(
				leerEstacionDeMetrobus(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion* LectoraDeArchivos::leerEstacionDeMetrobus(ifstream &entrada) {

	string longitud;
	string latitud;
	string id;
	string nombre;
	string calle1;
	string calle2;
	string interseccion;
	string lineaSentidoNorte;
	string lineaSentidoSur;
	string metrobus;
	string nombreSentido;
	string observacion;

	getline(entrada, longitud, ',');
	getline(entrada, latitud, ',');
	getline(entrada, id, ',');
	getline(entrada, nombre, ',');
	getline(entrada, calle1, ',');
	getline(entrada, calle2, ',');
	getline(entrada, interseccion, ',');
	getline(entrada, lineaSentidoNorte, ',');
	getline(entrada, lineaSentidoSur, ',');
	getline(entrada, metrobus, ',');
	getline(entrada, nombreSentido, ',');
	getline(entrada, observacion);

	Coordenadas coordenadasDeLaParada(atof(latitud.c_str()),
			atof(longitud.c_str()));
	Estacion *paradaDeMetrobus = new Estacion(coordenadasDeLaParada,
			Estacion::METROBUS, metrobus, calle1);

	return paradaDeMetrobus;

}

void LectoraDeArchivos::leerEstacionesDeFerrocarril(
		string archivosDeEstacionesDeFerrocarril,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;
	entrada.open(archivosDeEstacionesDeFerrocarril.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	string titulo;
	getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos->agregarEstacion(
				leerEstacionDeFerrocarril(entrada));

	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion* LectoraDeArchivos::leerEstacionDeFerrocarril(ifstream &entrada) {

	string longitud;
	string latitud;
	string id;
	string nombre;
	string linea;
	string linea2;
	string ramal;
	string barrio;
	string comuna;
	string localidad;
	string partido;

	getline(entrada, longitud, ',');
	getline(entrada, latitud, ',');
	getline(entrada, id, ',');
	getline(entrada, nombre, ',');
	getline(entrada, linea, ',');
	getline(entrada, linea2, ',');
	getline(entrada, ramal, ',');
	getline(entrada, barrio, ',');
	getline(entrada, comuna, ',');
	getline(entrada, localidad, ',');
	getline(entrada, partido);

	Coordenadas coordenadasDeLaParada(atof(latitud.c_str()),
			atof(longitud.c_str()));
	Estacion *estacionFerrocarril = new Estacion(coordenadasDeLaParada,
			Estacion::FERROCARRIL, linea, nombre);

	return estacionFerrocarril;

}

void LectoraDeArchivos::leerEstacionesDeColectivo(
		string archivosDeEstacionesDeColectivo,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;
	entrada.open(archivosDeEstacionesDeColectivo.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	string titulo;
	getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos->agregarEstacion(
				leerEstacionDeColectivo(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion* LectoraDeArchivos::leerEstacionDeColectivo(ifstream &entrada) {

	string id;
	string codigo;
	string nombre;
	string latitud;
	string longitud;
	string idDireccion;
	string numeroLinea;
	string idAgencia;
	string rutaNombreCorto;
	string rutaNombreLargo;
	string rutaDesc;
	string tipoRuta;

	getline(entrada, id, ',');
	getline(entrada, codigo, ',');
	getline(entrada, nombre, ',');
	getline(entrada, latitud, ',');
	getline(entrada, longitud, ',');
	getline(entrada, idDireccion, ',');
	getline(entrada, numeroLinea, ',');
	getline(entrada, idAgencia, ',');
	getline(entrada, rutaNombreCorto, ',');
	getline(entrada, rutaNombreLargo, ',');
	getline(entrada, rutaDesc, ',');
	getline(entrada, tipoRuta);

	Coordenadas coordenadasDeLaParada(atof(latitud.c_str()),
			atof(longitud.c_str()));
	Estacion *estacionColectivo = new Estacion(coordenadasDeLaParada,
			 Estacion::COLECTIVO,rutaNombreCorto, nombre);

	return estacionColectivo;

}

void LectoraDeArchivos::leerGarajes(string archivosDeGarajes,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;
	entrada.open(archivosDeGarajes.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	string titulo;
	getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos->agregarEstacion(leerGarage(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion* LectoraDeArchivos::leerGarage(ifstream &entrada) {

	string longitud;
	string latitud;
	string smp;
	string nombreDeLaCalle;
	string alturaDeLaCalle;
	string tipo1;
	string tipo2;
	string pisos;
	string nombre;
	string barrio;
	string comuna;
	string observacion;
	string objeto;
	string dominioSalida;
	string codigoPostal;
	string codigoPostalArgentino;

	getline(entrada, longitud, ',');
	getline(entrada, latitud, ',');
	getline(entrada, smp, ',');
	getline(entrada, nombreDeLaCalle, ',');
	getline(entrada, alturaDeLaCalle, ',');
	getline(entrada, tipo1, ',');
	getline(entrada, tipo2, ',');
	getline(entrada, pisos, ',');
	getline(entrada, nombre, ',');
	getline(entrada, barrio, ',');
	getline(entrada, comuna, ',');
	getline(entrada, codigoPostal, ',');
	getline(entrada, observacion, ',');
	getline(entrada, objeto, ',');
	getline(entrada, dominioSalida, ',');
	getline(entrada, codigoPostalArgentino);

	Coordenadas coordenadasDeLaParada(atof(latitud.c_str()),
			atof(longitud.c_str()));
	Estacion *garage = new Estacion(coordenadasDeLaParada,
			Estacion::GARAGE,"Estacionamiento", nombreDeLaCalle);

	return garage;

}

void LectoraDeArchivos::leerEstacionesDeSubte(
		string archivosDeEstacionesDeSubte,
		AdministradorDeRecorridos *administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	ifstream entrada;
	entrada.open(archivosDeEstacionesDeSubte.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	string titulo;
	getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos->agregarEstacion(
				leerEstacionDeSubte(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion* LectoraDeArchivos::leerEstacionDeSubte(ifstream &entrada) {

	string longitud;
	string latitud;
	string id;
	string linea;
	string estacion;
	string numeroDeEstacion;
	string destino;
	string lineasDe;
	string cierraFin;
	string escaleraMecanica;
	string escaleraNoMecanica;
	string ascensor;
	string rampa;
	string salvaEscaleras;
	string calle;
	string altura;
	string calle2;
	string barrio;
	string comuna;
	string observacion;
	string objeto;
	string dominioSalida;
	string dominioOrigen;

	getline(entrada, longitud, ',');
	getline(entrada, latitud, ',');
	getline(entrada, id, ',');
	getline(entrada, linea, ',');
	getline(entrada, estacion, ',');
	getline(entrada, numeroDeEstacion, ',');
	getline(entrada, destino, ',');
	getline(entrada, lineasDe, ',');
	getline(entrada, cierraFin, ',');
	getline(entrada, escaleraMecanica, ',');
	getline(entrada, escaleraNoMecanica, ',');
	getline(entrada, ascensor, ',');
	getline(entrada, rampa, ',');
	getline(entrada, salvaEscaleras, ',');
	getline(entrada, calle, ',');
	getline(entrada, altura, ',');
	getline(entrada, calle2, ',');
	getline(entrada, barrio, ',');
	getline(entrada, comuna, ',');
	getline(entrada, observacion, ',');
	getline(entrada, objeto, ',');
	getline(entrada, dominioSalida, ',');
	getline(entrada, dominioOrigen);

	Coordenadas coordenadasDeLaParada(atof(latitud.c_str()),
			atof(longitud.c_str()));
	Estacion *estacionDeSubte = new Estacion(coordenadasDeLaParada,
			Estacion::SUBTE,linea, calle);

	return estacionDeSubte;
}

