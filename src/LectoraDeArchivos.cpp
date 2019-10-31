#include "LectoraDeArchivos.h"
#include <fstream>

void LectoraDeArchivos::leerEstacionesDeMetrobus(
		std::string archivosDeEstacionesDeMetrobus,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeMetrobus.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos.agregarEstacion(
				leerEstacionDeMetrobus(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion LectoraDeArchivos::leerEstacionDeMetrobus(std::ifstream &entrada) {

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

	Coordenadas coordenadasDeLaParada(stod(latitud), stod(longitud));
	Estacion paradaDeMetrobus(coordenadasDeLaParada, metrobus,
			Estacion::METROBUS, calle1);

	return paradaDeMetrobus;

}

void LectoraDeArchivos::leerEstacionesDeFerrocarril(
		std::string archivosDeEstacionesDeFerrocarril,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeFerrocarril.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos.agregarEstacion(
				leerEstacionDeFerrocarril(entrada));

	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion LectoraDeArchivos::leerEstacionDeFerrocarril(std::ifstream &entrada) {

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
	std::getline(entrada, partido);
	Coordenadas coordenadasDeLaParada(stod(latitud), stod(longitud));
	Estacion estacionFerrocarril(coordenadasDeLaParada, linea,
			Estacion::FERROCARRIL, nombre);
	return estacionFerrocarril;

}

void LectoraDeArchivos::leerEstacionesDeColectivo(
		std::string archivosDeEstacionesDeColectivo,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeColectivo.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos.agregarEstacion(
				leerEstacionDeColectivo(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion LectoraDeArchivos::leerEstacionDeColectivo(std::ifstream &entrada) {

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
	std::getline(entrada, tipoRuta);
	Coordenadas coordenadasDeLaParada(stod(latitud), stod(longitud));
	Estacion estacionColectivo(coordenadasDeLaParada, numeroLinea,
			Estacion::COLECTIVO, nombre);

	return estacionColectivo;

}

void LectoraDeArchivos::leerGarajes(std::string archivosDeGarajes,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeGarajes.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
		administradorDeRecorridos.agregarEstacion(leerGarage(entrada));
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

Estacion LectoraDeArchivos::leerGarage(std::ifstream &entrada) {

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
	std::string observacion;
	std::string objeto;
	std::string dominioSalida;
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

	std::getline(entrada, codigoPostalArgentino);
	Coordenadas coordenadasDeLaParada(stod(latitud), stod(longitud));
	Estacion garage(coordenadasDeLaParada, "Estacionamiento", Estacion::GARAGE,
			nombreDeLaCalle);

	return garage;

}

<<<<<<< HEAD

Lista<EstacionSubte> LectoraDeArchivos::leerEstacionesDeSubte(
=======
void LectoraDeArchivos::leerEstacionesDeSubte(
>>>>>>> refs/remotes/origin/master
		std::string archivosDeEstacionesDeSubte,
		AdministradorDeRecorridos &administradorDeRecorridos) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(archivosDeEstacionesDeSubte.c_str());

	/* lee la primera línea completa porque esta el formato de los campos */
	std::string titulo;
	std::getline(entrada, titulo);

	/* lee el resto del archivo */
	while (entrada.peek() != EOF) {
<<<<<<< HEAD
		listaDeEstacionesDeSubte.agregar(leerEstacionDeSubte(entrada));
=======
		administradorDeRecorridos.agregarEstacion(leerEstacionDeSubte(entrada));
>>>>>>> refs/remotes/origin/master
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
<<<<<<< HEAD

	return listaDeEstacionesDeSubte;
=======
>>>>>>> refs/remotes/origin/master

}

<<<<<<< HEAD
EstacionSubte leerEstacionDeSubte(std::ifstream &entrada){
=======
Estacion LectoraDeArchivos::leerEstacionDeSubte(std::ifstream &entrada) {
>>>>>>> refs/remotes/origin/master

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
	std::getline(entrada, dominioOrigen);

<<<<<<< HEAD
	EstacionSubte estacionDeSubte(stoul(longitud), stoul(latitud), stoul(id), linea, estacion,
				  numeroDeEstacion, destino, lineasDe, cierraFin == "True", escaleraNoMecanica == "True", escaleraMecanica == "True", ascensor == "True",
				  rampa == "True", salvaEscaleras == "True", calle, stoul(altura), calle2, barrio, comuna, observacion,
				  objeto, dominioSalida, dominioOrigen);
=======
	Coordenadas coordenadasDeLaParada(stod(latitud), stod(longitud));
	Estacion estacionDeSubte(coordenadasDeLaParada, linea, Estacion::SUBTE,
			calle);
>>>>>>> refs/remotes/origin/master

	return estacionDeSubte;
}

<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/master
