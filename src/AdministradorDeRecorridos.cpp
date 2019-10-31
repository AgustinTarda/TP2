#include "AdministradorDeRecorridos.h"

AdministradorDeRecorridos::AdministradorDeRecorridos() {
	this->recorridos = new Lista<Recorrido*>;
}


AdministradorDeRecorridos::AdministradorDeRecorridos(const AdministradorDeRecorridos &otroAdministradorDeRecorridos){
	this->recorridos = otroAdministradorDeRecorridos.recorridos;
}


void AdministradorDeRecorridos::agregarEstacion(Estacion estacion) {
	bool tieneRecorrido = false;

	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor() && !tieneRecorrido) {
		Recorrido *recorridoAnalizado = recorridos->obtenerCursor();
		if (recorridoAnalizado->debeContener(estacion)) {
			recorridoAnalizado->agregarEstacion(estacion);
			tieneRecorrido = true;
		}
	}

	if (!tieneRecorrido) {
		crearRecorridoPara(estacion);
	}

}

Recorrido AdministradorDeRecorridos::obtenerRecorridoAlQuePertenece(
		Estacion estacion) {
	bool seEncontroElRecorrido = false;
	Recorrido *recorridoBuscado;
	this->recorridos->iniciarCursor();
	while (recorridos->avanzarCursor() && !seEncontroElRecorrido) {
		Recorrido *recorridoAnalizado = recorridos->obtenerCursor();
		if (recorridoAnalizado->debeContener(estacion)) {
			recorridoBuscado = recorridoAnalizado;
			seEncontroElRecorrido = true;
		}
	}

	return *recorridoBuscado;
}

Lista<Recorrido*> AdministradorDeRecorridos::obtenerRecorridos() {
	return *(this->recorridos);
}


void AdministradorDeRecorridos::crearRecorridoPara(Estacion estacion) {
	Lista<Estacion> *estacionesDelRecorrido = new Lista<Estacion>;
	estacionesDelRecorrido->agregar(estacion);
	Recorrido *recorridoAAgregar = new Recorrido(estacion.obtenerLinea(),
			estacionesDelRecorrido, estacion.obtenerTipoDeTransporte());
	this->recorridos->agregar(recorridoAAgregar);
}

AdministradorDeRecorridos::~AdministradorDeRecorridos() {
	delete this->recorridos;
}
