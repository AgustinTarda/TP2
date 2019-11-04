/*
 * AlgoMaps.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */
//
#include "AlgoMaps.h"

AlgoMaps::AlgoMaps() {

	LectoraDeArchivos lectora;

	std::string archivoDeMetrobus = "datos/estaciones-de-metrobus.csv";
	lectora.leerEstacionesDeMetrobus(archivoDeMetrobus,
			this->administradorDeRecorridos);

	std::string archivoDeFerrocarril = "datos/estaciones-de-ferrocarril.csv";
	lectora.leerEstacionesDeFerrocarril(archivoDeFerrocarril,
			this->administradorDeRecorridos);

	std::string archivoColectivos = "datos/paradas-de-colectivo.csv";
	lectora.leerEstacionesDeColectivo(archivoColectivos,
			this->administradorDeRecorridos);

	std::string archivoSubte = "datos/bocas-de"
			"-subte.csv";
	lectora.leerEstacionesDeSubte(archivoSubte,
			this->administradorDeRecorridos);

	//std::string archivoGarajes = "datos/garajes-comerciales.csv";
	//lectora.leerGarajes(archivoGarajes, this->administradorDeRecorridos);

	//interfazDeUsuario.imprimirRecorridos(
		//administradorDeRecorridos.obtenerRecorridos());
}

void AlgoMaps::iniciarViaje() {
	interfazDeUsuario.mostrarMensajeDeBienvenida();

	/*Coordenadas coordenadasDeInicio =
	 interfazDeUsuario.pedirCoordenadasDeInicio();
	 Coordenadas coordenadasDeDestino =
	 interfazDeUsuario.pedirCoord`enadasDeDestino();*/

	Coordenadas coordenadasDeInicio(-34.6021056176248, -58.3840678491549);
	Coordenadas coordenadasDeDestino(-34.5952234173066, -58.4028219030811);

	std::cout << coordenadasDeInicio.calcularDistancia(coordenadasDeDestino)
			<< std::endl;

	Lista<Viaje> viajes;
	buscadorDeViajes.buscarViaje(coordenadasDeInicio, coordenadasDeDestino,
			this->administradorDeRecorridos, viajes);

	interfazDeUsuario.imprimirViajes(viajes);


}

void AlgoMaps::imprimirMapaDeViajeDirecto(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje){
	DibujadorDeMapa mapa;

	Recorrido recorrido = administradorDeRecorridos.obtenerRecorridoAlQuePertenece(viaje.obtenerEstacionInicial());

	Lista<Estacion*> * estaciones = recorrido.obtenerEstaciones();

	estaciones->iniciarCursor();

	while(estaciones->avanzarCursor()){
		Estacion* estacionLeida(estaciones->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
							mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 3, 128, 0, 0);
	}
	Estacion estacionInicial(viaje.obtenerEstacionInicial());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionInicial.obtenerCoordenadas()),
					mapa.convertidorDeCoordenadasAPixelsLatitud(estacionInicial.obtenerCoordenadas()), 3, 0, 0, 0);
	Estacion estacionFinal(viaje.obtenerEstacionDestino());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionFinal.obtenerCoordenadas()),
					mapa.convertidorDeCoordenadasAPixelsLatitud(estacionFinal.obtenerCoordenadas()), 3, 255, 0, 0);

	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasInicial),
				mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasInicial), 3, 128, 0, 128);

	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasFinal),
					mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasFinal), 3, 0, 0, 128);
	BMP* mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeDirecto.bmp");
}

void AlgoMaps::imprimirMapaDeViajeCombinacion(Coordenadas coordenadasInicial, Coordenadas coordenadasFinal, Viaje viaje){
	DibujadorDeMapa mapa;

	Recorrido recorridoPrimeraParte = administradorDeRecorridos.obtenerRecorridoAlQuePertenece(viaje.obtenerEstacionInicial());

	Lista<Estacion*> * estacionesPrimeraParte = recorridoPrimeraParte.obtenerEstaciones();

	estacionesPrimeraParte->iniciarCursor();

	while(estacionesPrimeraParte->avanzarCursor()){
		Estacion* estacionLeida(estacionesPrimeraParte->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
							mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 3, 128, 0, 0);
	}
	Recorrido recorridoSegundaParte = administradorDeRecorridos.obtenerRecorridoAlQuePertenece(viaje.obtenerEstacionSubidaDeCombinacion());

	Lista<Estacion*> * estacionesSegundaParte = recorridoSegundaParte.obtenerEstaciones();

	estacionesSegundaParte->iniciarCursor();

	while(estacionesSegundaParte->avanzarCursor()){
		Estacion* estacionLeida(estacionesSegundaParte->obtenerCursor());
		Coordenadas coordenadas(estacionLeida->obtenerCoordenadas());
		mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadas),
						  mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadas), 3, 255, 255, 0);
	}
	Estacion estacionInicial(viaje.obtenerEstacionInicial());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionInicial.obtenerCoordenadas()),
					mapa.convertidorDeCoordenadasAPixelsLatitud(estacionInicial.obtenerCoordenadas()), 3, 0, 0, 0);
	Estacion estacionFinal(viaje.obtenerEstacionDestino());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionFinal.obtenerCoordenadas()),
					mapa.convertidorDeCoordenadasAPixelsLatitud(estacionFinal.obtenerCoordenadas()), 3, 255, 0, 0);

	Estacion estacionSubida(viaje.obtenerEstacionSubidaDeCombinacion());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionSubida.obtenerCoordenadas()),
						mapa.convertidorDeCoordenadasAPixelsLatitud(estacionSubida.obtenerCoordenadas()), 3, 0, 128, 0);
	Estacion estacionBajada(viaje.obtenerEstacionBajadaDeCombinacion());
	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(estacionBajada.obtenerCoordenadas()),
							mapa.convertidorDeCoordenadasAPixelsLatitud(estacionBajada.obtenerCoordenadas()), 3, 255, 0, 255);

	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasInicial),
						mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasInicial), 3, 128, 0, 128);

	mapa.dibujarPunto(mapa.convertidorDeCoordenadasAPixelsLongitud(coordenadasFinal),
							mapa.convertidorDeCoordenadasAPixelsLatitud(coordenadasFinal), 3, 0, 0, 128);
	BMP* mapaActual = mapa.obtenerMapa();
	mapaActual->WriteToFile("viajeCombinacion.bmp");
}
