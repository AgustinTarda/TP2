/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"
using namespace std;

void Interfaz::mostrarMensajeDeBienvenida() {
	cout << "Bienvenidos a AlgoMaps, su buscador de viajes favorito !" << endl
			<< endl;
}

Coordenadas Interfaz::pedirCoordenadasDeInicio() {

	cout << "Ingrese las coordenadas de inicio" << endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasInicio(latitud, longitud);

	return coordenadasInicio;
}

Coordenadas Interfaz::pedirCoordenadasDeDestino() {

	cout << "Ingrese las coordenadas de destino" << endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasDestino(latitud, longitud);

	return coordenadasDestino;
}

double Interfaz::pedirLongitud() {
	double longitud;

	cout << "Ingrese la longitud" << endl;
	cin >> longitud;

	return longitud;
}
double Interfaz::pedirLatitud() {
	double latitud;

	cout << "Ingrese la latitud" << endl;
	cin >> latitud;

	return latitud;
}

void Interfaz::imprimirRecorridos(Lista<Recorrido*> *recorridos) {
	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor()) {
		Recorrido *recorridoAImprimir = recorridos->obtenerCursor();
		cout << "Recorrido: " << recorridoAImprimir->obtenerLinea() << " --- "
				<< recorridoAImprimir->obtenerTipoDeTransporte() << " --- "
				<< recorridoAImprimir->obtenerEstaciones()->contarElementos()
				<< endl;
		imprimirEstaciones(recorridoAImprimir->obtenerEstaciones());

	}
}

void Interfaz::imprimirEstaciones(Lista<Estacion*> *estaciones) {
	estaciones->iniciarCursor();
	while (estaciones->avanzarCursor()) {
		Estacion *estacionAImprimir = estaciones->obtenerCursor();
		cout << "Estacion: ---------------------------- "
				<< estacionAImprimir->obtenerDireccion() << " --- "
				<< estacionAImprimir->obtenerLinea() << " --- "
				<< estacionAImprimir->obtenerTipoDeTransporte() << endl;

	}
}

void Interfaz::imprimirViajes(Coordenadas *coordenadasDeInicio,
		Coordenadas *coordenadasDeDestino,
		AdministradorDeRecorridos *administradorDeRecorridos, Viaje* viaje) {
	DibujadorDeMapa mapa;
	if (viaje->esDirecto()) {
		imprimirViajeDirecto(*viaje);

		// Imprime los viajes, descomentar y usar este cuando se termine de probar todo
		this->imprimirMapaDeViajeDirecto(coordenadasDeInicio,
				coordenadasDeDestino, *viaje, administradorDeRecorridos);

	} else if (viaje->esConCombinacionSimple()) {
		imprimirViajeConCombinacionSimple(*viaje);

		// Imprime los viajes, descomentar y usar este cuando se termine de probar todo
		this->imprimirMapaDeViajeCombinacion(coordenadasDeInicio,
				coordenadasDeDestino, *viaje, administradorDeRecorridos);

	}

	imprimirCostoViaje(calcularPrecio(viaje));

	delete viaje;

}

void Interfaz::imprimirViajes(Lista<Viaje*> *viajes) {
	viajes->iniciarCursor();
	while (viajes->avanzarCursor()) {
		Viaje *viajeAImprimir = viajes->obtenerCursor();
		if (viajeAImprimir->esDirecto()) {
			imprimirViajeDirecto(*viajeAImprimir);

		} else if (viajeAImprimir->esConCombinacionSimple()) {
			imprimirViajeConCombinacionSimple(*viajeAImprimir);

		}

	}
}
void Interfaz::imprimirMapaDeViajeDirecto(Coordenadas *coordenadasInicial,
		Coordenadas *coordenadasFinal, Viaje viaje,
		AdministradorDeRecorridos *administradorDeRecorridos) {
	DibujadorDeMapa mapa;

	Recorrido *recorrido =
			administradorDeRecorridos->obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionInicial());

	Lista<Estacion*> *estaciones = recorrido->obtenerEstaciones();

	estaciones->iniciarCursor();

	while (estaciones->avanzarCursor()) {
		Estacion *estacionLeida = estaciones->obtenerCursor();
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2, 0,
				0, 0);
	}
	Estacion *estacionFinal = viaje.obtenerEstacionDestino();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionFinal->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionFinal->obtenerCoordenadas()), 5, 0, 255, 0);

	Estacion *estacionInicial = viaje.obtenerEstacionInicial();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionInicial->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionInicial->obtenerCoordenadas()), 5, 255, 0, 255);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(*coordenadasInicial),
			mapa.convertidorDeCoordenadasAPixelsLatitud(*coordenadasInicial), 5,
			0, 255, 255);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(*coordenadasFinal),
			mapa.convertidorDeCoordenadasAPixelsLatitud(*coordenadasFinal), 5,
			0, 0, 128);
	BMP *mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeDirecto.bmp");
}

void Interfaz::imprimirMapaDeViajeCombinacion(Coordenadas *coordenadasInicial,
		Coordenadas *coordenadasFinal, Viaje viaje,
		AdministradorDeRecorridos *administradorDeRecorridos) {
	DibujadorDeMapa mapa;

	Recorrido *recorridoPrimeraParte =
			administradorDeRecorridos->obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionInicial());

	Lista<Estacion*> *estacionesPrimerTramo =
			recorridoPrimeraParte->obtenerEstaciones();

	estacionesPrimerTramo->iniciarCursor();
	while (estacionesPrimerTramo->avanzarCursor()) {
		Estacion *estacionLeida = estacionesPrimerTramo->obtenerCursor();
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2, 0,
				0, 0);
	}
	Recorrido *recorridoSegundaParte =
			administradorDeRecorridos->obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionSubidaDeCombinacion());

	Lista<Estacion*> *estacionesSegundoTramo =
			recorridoSegundaParte->obtenerEstaciones();

	estacionesSegundoTramo->iniciarCursor();

	while (estacionesSegundoTramo->avanzarCursor()) {
		Estacion *estacionLeida = estacionesSegundoTramo->obtenerCursor();
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2,
				128, 0, 0);
	}

	Estacion *estacionFinal = viaje.obtenerEstacionDestino();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionFinal->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionFinal->obtenerCoordenadas()), 5, 0, 255, 0);
	Estacion *estacionInicial = viaje.obtenerEstacionInicial();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionInicial->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionInicial->obtenerCoordenadas()), 5, 255, 0, 255);

	Estacion *estacionSubida = viaje.obtenerEstacionSubidaDeCombinacion();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionSubida->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionSubida->obtenerCoordenadas()), 4, 0, 0, 255);
	Estacion *estacionBajada = viaje.obtenerEstacionBajadaDeCombinacion();
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionBajada->obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionBajada->obtenerCoordenadas()), 4, 0, 128, 128);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(*coordenadasInicial),
			mapa.convertidorDeCoordenadasAPixelsLatitud(*coordenadasInicial), 5,
			0, 255, 255);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(*coordenadasFinal),
			mapa.convertidorDeCoordenadasAPixelsLatitud(*coordenadasFinal), 5,
			0, 0, 128);
	BMP *mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeCombinacion.bmp");
}

void Interfaz::imprimirViajeDirecto(Viaje viajeDirecto) {
	Estacion *estacionInicio = viajeDirecto.obtenerEstacionInicial();
	Estacion *estacionDestino = viajeDirecto.obtenerEstacionDestino();

	cout << "Viaje directo: ---------------------------- " << endl
			<< "Camine y subase en la estacion de "
			<< estacionInicio->imprimirTipoDeTransporte() << " linea: "
			<< estacionInicio->obtenerLinea() << " ubicada en: "
			<< estacionInicio->obtenerDireccion()
			<< " luego bajese en la estacion ubicada en "
			<< estacionDestino->obtenerDireccion() << endl;
}
void Interfaz::imprimirViajeConCombinacionSimple(
		Viaje viajeConCombinacionSimple) {

	Estacion *estacionInicio =
			viajeConCombinacionSimple.obtenerEstacionInicial();
	Estacion *estacionSubida =
			viajeConCombinacionSimple.obtenerEstacionSubidaDeCombinacion();
	Estacion *estacionBajada =
			viajeConCombinacionSimple.obtenerEstacionBajadaDeCombinacion();
	Estacion *estacionDestino =
			viajeConCombinacionSimple.obtenerEstacionDestino();

	cout << "Viaje combinado: ---------------------------- " << endl
			<< "Camine y subase en la estacion de "
			<< estacionInicio->imprimirTipoDeTransporte() << " linea: "
			<< estacionInicio->obtenerLinea() << " ubicada en: "
			<< estacionInicio->obtenerDireccion()
			<< " luego bajese en la estacion ubicada en "
			<< estacionBajada->obtenerDireccion()
			<< estacionBajada->obtenerDireccion() <<endl

			<< "Luego camine y subase en la estacion de "
			<< estacionSubida->imprimirTipoDeTransporte() << " linea: "
			<< estacionSubida->obtenerLinea() << " ubicada en: "
			<< estacionSubida->obtenerDireccion()
			<< " y por ultimo bajese en la estacion ubicada en "
			<< estacionDestino->obtenerDireccion()
			<< " y camine hasta su destino" << endl;

}
void Interfaz::noSeEncontroViajesPosibles() {

	cout << "No se encontro ningun viaje. Lo sentimos prube de nuevo" << endl;
}

double Interfaz::calcularPrecio(Viaje* viaje) {
	double costo;
	Estacion* estacionInicial = viaje->obtenerEstacionInicial();

	if (viaje->obtenerTipoDeViaje() == Viaje::DIRECTO) {

		costo = obtenerCostoDelTransporte(
				estacionInicial->obtenerTipoDeTransporte());

	} else if (viaje->obtenerTipoDeViaje() == Viaje::COMBINACION_SIMPLE) {
		Estacion* estacionSubida = viaje->obtenerEstacionSubidaDeCombinacion();

		costo = obtenerCostoDelTransporte(
				estacionInicial->obtenerTipoDeTransporte())
				+ obtenerCostoDelTransporte(
						estacionSubida->obtenerTipoDeTransporte());
	}

	return costo;
}
double Interfaz::obtenerCostoDelTransporte(
		Estacion::TipoDeTransporte tipoDeTransporte) {
	double precio;

	if (tipoDeTransporte == Estacion::COLECTIVO) {
		precio = PRECIO_COLECTIVO;

	} else if (tipoDeTransporte == Estacion::SUBTE) {
		precio = PRECIO_SUBTE;

	} else if (tipoDeTransporte == Estacion::METROBUS) {
		precio = PRECIO_METROBUS;
	} else if (tipoDeTransporte == Estacion::FERROCARRIL) {
		precio = PRECIO_FERROCARRIL;
	}
	return precio;

}

void Interfaz::imprimirCostoViaje(double costo){
	cout<< "El costo del viaje es: " << costo << endl;
}

