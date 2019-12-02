#include "AdministradorDeRecorridos.h"

AdministradorDeRecorridos::AdministradorDeRecorridos() {
	this->recorridos = new Lista<Recorrido*>;
}

AdministradorDeRecorridos::AdministradorDeRecorridos(
		const AdministradorDeRecorridos &otroAdministradorDeRecorridos) {
	this->recorridos = otroAdministradorDeRecorridos.recorridos;
}

void AdministradorDeRecorridos::agregarEstacion(Estacion *estacionAAgregar) {
	bool tieneRecorrido = false;

	recorridos->iniciarCursor();
	while (recorridos->avanzarCursor() && !tieneRecorrido) {
		Recorrido *recorridoAnalizado = recorridos->obtenerCursor();
		if (recorridoAnalizado->debeContener(estacionAAgregar)) {
			recorridoAnalizado->agregarEstacion(estacionAAgregar);
			tieneRecorrido = true;
		}
	}

	if (!tieneRecorrido) {
		crearRecorridoPara(estacionAAgregar);
	}

}

Recorrido* AdministradorDeRecorridos::obtenerRecorridoAlQuePertenece(
		Estacion *estacion) {
	bool seEncontroElRecorrido = false;

	Recorrido *recorridoBuscado = NULL;
	this->recorridos->iniciarCursor();
	while (recorridos->avanzarCursor() && !seEncontroElRecorrido) {
		Recorrido *recorridoAnalizado = recorridos->obtenerCursor();
		if (recorridoAnalizado->debeContener(estacion)) {
			recorridoBuscado = recorridoAnalizado;
			seEncontroElRecorrido = true;
		}
	}
	return recorridoBuscado;
}

Lista<Recorrido*>* AdministradorDeRecorridos::obtenerRecorridos() {
	return this->recorridos;

}

void AdministradorDeRecorridos::crearRecorridoPara(Estacion *estacion) {
	Recorrido *recorridoAAgregar = new Recorrido(estacion->obtenerLinea(),
			estacion->obtenerTipoDeTransporte());
	recorridoAAgregar->agregarEstacion(estacion);
	this->recorridos->agregar(recorridoAAgregar);
}

AdministradorDeRecorridos::~AdministradorDeRecorridos() {
	while (!recorridos->estaVacia()) {
		Recorrido *recorridoAEliminar = recorridos->obtener(1);
		delete recorridoAEliminar;
		recorridos->remover(1);
	}
	delete this->recorridos;
}
