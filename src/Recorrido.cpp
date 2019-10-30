#include "Recorrido.h"

Recorrido::Recorrido() {

}

Recorrido::Recorrido(const Recorrido &otroRecorrido) {
	this->linea = otroRecorrido.linea;
	this->estaciones = otroRecorrido.estaciones;
	this->tipoDeTransporte = otroRecorrido.tipoDeTransporte;
}
