#include "AdministradorDeRecorridos.h"

AdministradorDeRecorridos::AdministradorDeRecorridos() {
	this->recorridos = new Lista<Recorrido*>;
}

AdministradorDeRecorridos::AdministradorDeRecorridos(
		const AdministradorDeRecorridos &otroAdministradorDeRecorridos) {
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

Lista<Recorrido*>* AdministradorDeRecorridos::obtenerRecorridos() {
	return this->recorridos;

}


void AdministradorDeRecorridos::crearRecorridoPara(Estacion estacion) {
	Recorrido *recorridoAAgregar = new Recorrido(estacion.obtenerLinea(),
			estacion.obtenerTipoDeTransporte());
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
