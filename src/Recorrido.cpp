#include "Recorrido.h"

Recorrido::Recorrido() {
	this->estaciones = new Lista<Estacion>;
}

Recorrido::Recorrido(const Recorrido &otroRecorrido) {
	this->linea = otroRecorrido.linea;
	this-> estaciones = otroRecorrido.estaciones;
	this->tipoDeTransporte = otroRecorrido.tipoDeTransporte;
}

Recorrido::Recorrido(std::string linea, Lista<Estacion> *estaciones,
		Estacion::TipoDeTransporte tipoDeTransporte) {
	this->linea = linea;
	this->estaciones = estaciones;
	this->tipoDeTransporte = tipoDeTransporte;
}

Lista<Estacion> Recorrido::obtenerEstaciones() {
	return *this->estaciones;
}

bool Recorrido::debeContener(Estacion estacion) {
	return (this->linea == estacion.obtenerLinea())
			&& (this->tipoDeTransporte == estacion.obtenerTipoDeTransporte());
}

void Recorrido::agregarEstacion(Estacion estacion) {
	this->estaciones->agregar(estacion);
}
Recorrido::~Recorrido() {
	delete this->estaciones;
}
