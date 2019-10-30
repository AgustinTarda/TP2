#include "Recorrido.h"

Recorrido::Recorrido() {

}

Recorrido::Recorrido(const Recorrido &otroRecorrido) {
	this->linea = otroRecorrido.linea;
	this->estaciones = otroRecorrido.estaciones;
	this->tipoDeTransporte = otroRecorrido.tipoDeTransporte;
}

Recorrido::Recorrido(std::string linea, Lista<Estacion> estaciones,
		Estacion::TipoDeTransporte tipoDeTransporte) {
	this->linea = linea;
	this->estaciones = estaciones;
	this->tipoDeTransporte = tipoDeTransporte;
}

Lista<Estacion> Recorrido::obtenerEstaciones() {

}

bool Recorrido::debeContener(Estacion estacion) {
	return (this->linea == estacion.obtenerLinea())
			&& (this->tipoDeTransporte == estacion.obtenerTipoDeTransporte());
}

void Recorrido::agregarEstacion(Estacion estacion) {
	this->estaciones.agregar(estacion);
}

