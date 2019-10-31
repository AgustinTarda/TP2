#include "Recorrido.h"

Recorrido::Recorrido() {
	this->estaciones = new Lista<Estacion*>;
}

Recorrido::Recorrido(std::string linea,
		Estacion::TipoDeTransporte tipoDeTransporte) {
	this->linea = linea;
	this->estaciones = new Lista<Estacion*>;
	this->tipoDeTransporte = tipoDeTransporte;
}
Recorrido::Recorrido(const Recorrido &otroRecorrido) {
	this->linea = otroRecorrido.linea;
	this->estaciones = otroRecorrido.estaciones;
	this->tipoDeTransporte = otroRecorrido.tipoDeTransporte;
}

Lista<Estacion*>* Recorrido::obtenerEstaciones() {
	return this->estaciones;
}

std::string Recorrido::obtenerLinea() {
	return this->linea;
}

Estacion::TipoDeTransporte Recorrido::obtenerTipoDeTransporte() {
	return this->tipoDeTransporte;
}

bool Recorrido::debeContener(Estacion estacion) {
	return (this->linea == estacion.obtenerLinea())
			&& (this->tipoDeTransporte == estacion.obtenerTipoDeTransporte());
}

void Recorrido::agregarEstacion(Estacion estacion) {
	Estacion *nuevaEstacion = new Estacion(estacion.obtenerCoordenadas(),
			estacion.obtenerLinea(), estacion.obtenerTipoDeTransporte(),
			estacion.obtenerDireccion());
	this->estaciones->agregar(nuevaEstacion);
}
Recorrido::~Recorrido() {

	while (!estaciones->estaVacia()) {
		Estacion *estacionAEliminar = estaciones->obtener(1);
		delete estacionAEliminar;
		estaciones->remover(1);
	}
	delete this->estaciones;
}
