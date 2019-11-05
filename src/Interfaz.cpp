/*
 * Interfaz.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#include"Interfaz.h"

void Interfaz::mostrarMensajeDeBienvenida() {
	std::cout << "Bienvenidos a AlgoMaps, su buscador de viajes favorito !"
			<< std::endl << std::endl;
}

Coordenadas Interfaz::pedirCoordenadasDeInicio() {

	std::cout << "Ingrese las coordenadas de inicio" << std::endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasInicio(latitud, longitud);

	return coordenadasInicio;
}

Coordenadas Interfaz::pedirCoordenadasDeDestino() {

	std::cout << "Ingrese las coordenadas de destino" << std::endl;
	double longitud = pedirLongitud();
	double latitud = pedirLatitud();
	Coordenadas coordenadasDestino(latitud, longitud);

	return coordenadasDestino;
}

double Interfaz::pedirLongitud() {
	double longitud;

	std::cout << "Ingrese la longitud" << std::endl;
	std::cin >> longitud;

	return longitud;
}
double Interfaz::pedirLatitud() {
	double latitud;

	std::cout << "Ingrese la latitud" << std::endl;
	std::cin >> latitud;

	return latitud;
}

void Interfaz::mostrarParada(Estacion parada) {

	std::cout << "MetroBus: " << parada.obtenerLinea() << std::endl;

}

void Interfaz::imprimirRecorridos(Lista<Recorrido*> *recorridos) {
	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor()) {
		Recorrido *recorridoAImprimir = recorridos->obtenerCursor();
		std::cout << "Recorrido: " << recorridoAImprimir->obtenerLinea()
				<< " --- " << recorridoAImprimir->obtenerTipoDeTransporte()
				<< " --- "
				<< recorridoAImprimir->obtenerEstaciones()->contarElementos()
				<< std::endl;
		imprimirEstaciones(recorridoAImprimir->obtenerEstaciones());

	}
}

void Interfaz::imprimirEstaciones(Lista<Estacion*> *estaciones) {
	estaciones->iniciarCursor();
	while (estaciones->avanzarCursor()) {
		Estacion *estacionAImprimir = estaciones->obtenerCursor();
		std::cout << "Estacion: ---------------------------- "
				<< estacionAImprimir->obtenerDireccion() << " --- "
				<< estacionAImprimir->obtenerLinea() << " --- "
				<< estacionAImprimir->obtenerTipoDeTransporte() << std::endl;

	}
}

void Interfaz::imprimirViajes(Coordenadas coordenadasDeInicio,
		Coordenadas coordenadasDeDestino,
		AdministradorDeRecorridos administradorDeRecorridos,
		Lista<Viaje> viajes) {
	DibujadorDeMapa mapa;
	viajes.iniciarCursor();
	while (viajes.avanzarCursor()) {
		Viaje viajeAImprimir = viajes.obtenerCursor();
		if (viajeAImprimir.esDirecto()) {
			imprimirViajeDirecto(viajeAImprimir);

			// Imprime los viajes, descomentar y usar este cuando se termine de probar todo
			this->imprimirMapaDeViajeDirecto(coordenadasDeInicio,
					coordenadasDeDestino, viajeAImprimir,
					administradorDeRecorridos);

		} else if (viajeAImprimir.esConCombinacionSimple()) {
			imprimirViajeConCombinacionSimple(viajeAImprimir);

			// Imprime los viajes, descomentar y usar este cuando se termine de probar todo
			this->imprimirMapaDeViajeCombinacion(coordenadasDeInicio,
					coordenadasDeDestino, viajeAImprimir,
					administradorDeRecorridos);

		}

	}
}

void Interfaz::imprimirViajes(Lista<Viaje> viajes) {
	viajes.iniciarCursor();
	while (viajes.avanzarCursor()) {
		Viaje viajeAImprimir = viajes.obtenerCursor();
		if (viajeAImprimir.esDirecto()) {
			imprimirViajeDirecto(viajeAImprimir);

		} else if (viajeAImprimir.esConCombinacionSimple()) {
			imprimirViajeConCombinacionSimple(viajeAImprimir);

		}

	}
}
void Interfaz::imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial,
		Coordenadas coordenadasFinal, Viaje viaje,
		AdministradorDeRecorridos administradorDeRecorridos) {
	DibujadorDeMapa mapa;

	Recorrido *recorrido =
			administradorDeRecorridos.obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionInicial());

	Lista<Estacion*> *estaciones = recorrido->obtenerEstaciones();

	estaciones->iniciarCursor();

	while (estaciones->avanzarCursor()) {
		Estacion *estacionLeida(estaciones->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2,
				0, 0, 0);
	}
	Estacion estacionInicial(viaje.obtenerEstacionInicial());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionInicial.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionInicial.obtenerCoordenadas()), 5, 255, 0, 255);
	Estacion estacionFinal(viaje.obtenerEstacionDestino());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionFinal.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionFinal.obtenerCoordenadas()), 5, 255, 0, 0);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasInicial),
			mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasInicial), 5,
			0, 255, 255);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasFinal),
			mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasFinal), 5, 0,
			0, 128);
	BMP *mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeDirecto.bmp");
}

void Interfaz::imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial,
		Coordenadas coordenadasFinal, Viaje viaje,
		AdministradorDeRecorridos administradorDeRecorridos) {
	DibujadorDeMapa mapa;

	Recorrido *recorridoPrimeraParte =
			administradorDeRecorridos.obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionInicial());

	Lista<Estacion*> *estacionesPrimeraParte =
			recorridoPrimeraParte->obtenerEstaciones();

	estacionesPrimeraParte->iniciarCursor();

	while (estacionesPrimeraParte->avanzarCursor()) {
		Estacion *estacionLeida(estacionesPrimeraParte->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2,
				128, 0, 0);
	}
	Recorrido *recorridoSegundaParte =
			administradorDeRecorridos.obtenerRecorridoAlQuePertenece(
					viaje.obtenerEstacionSubidaDeCombinacion());

	Lista<Estacion*> *estacionesSegundaParte =
			recorridoSegundaParte->obtenerEstaciones();

	estacionesSegundaParte->iniciarCursor();

	while (estacionesSegundaParte->avanzarCursor()) {
		Estacion *estacionLeida(estacionesSegundaParte->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(
				mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 2,
				0, 0, 0);
	}
	Estacion estacionInicial(viaje.obtenerEstacionInicial());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionInicial.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionInicial.obtenerCoordenadas()), 5, 255, 0, 255);
	Estacion estacionFinal(viaje.obtenerEstacionDestino());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionFinal.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionFinal.obtenerCoordenadas()),  5, 255, 0, 0);

	Estacion estacionSubida(viaje.obtenerEstacionSubidaDeCombinacion());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionSubida.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionSubida.obtenerCoordenadas()), 4, 128, 0, 128);
	Estacion estacionBajada(viaje.obtenerEstacionBajadaDeCombinacion());
	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(
					estacionBajada.obtenerCoordenadas()),
			mapa.convertidorDeCoordenadasAPixelsLatitud(
					estacionBajada.obtenerCoordenadas()), 4, 0, 128, 128);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasInicial),
			mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasInicial), 5,
			0, 255, 255);

	mapa.dibujarPunto(
			mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasFinal),
			mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasFinal), 5, 0,
			0, 128);
	BMP *mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeCombinacion.bmp");
}

void Interfaz::graficarParadasEnMapa(Recorrido recorrido) {

}
void Interfaz::imprimirViajeDirecto(Viaje viajeDirecto) {
	Estacion estacionInicio = viajeDirecto.obtenerEstacionInicial();
	Estacion estacionDestino = viajeDirecto.obtenerEstacionDestino();

	std::cout << "Viaje directo: ---------------------------- " << std::endl
			<< "Camine y subase en la estacion de "
			<< estacionInicio.imprimirTipoDeTransporte() << " linea: "
			<< estacionInicio.obtenerLinea() << " ubicada en: "
			<< estacionInicio.obtenerDireccion()
			<< " luego bajese en la estacion ubicada en "
			<< estacionDestino.obtenerDireccion() << std::endl;
}
void Interfaz::imprimirViajeConCombinacionSimple(
		Viaje viajeConCombinacionSimple) {

}

