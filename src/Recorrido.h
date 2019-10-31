#ifndef SRC_RECORRIDO_H_
#define SRC_RECORRIDO_H_

#include <string>
#include "Lista.h"
#include "Estacion.h"

class Recorrido {

private:

	std::string linea;
	Lista<Estacion*> *estaciones;
	Estacion::TipoDeTransporte tipoDeTransporte;

public:

	Recorrido();
	Recorrido(const Recorrido &otroRecorrido);
	Recorrido(std::string linea, Estacion::TipoDeTransporte tipoDeTransporte);
	Recorrido(std::string linea, Lista<Estacion*> *estaciones,
			Estacion::TipoDeTransporte tipoDeTransporte);
	Lista<Estacion*>* obtenerEstaciones();
	std::string obtenerLinea();
	Estacion::TipoDeTransporte obtenerTipoDeTransporte();
	bool debeContener(Estacion estacion);
	void agregarEstacion(Estacion estacion);
	~Recorrido();
};

#endif /* SRC_RECORRIDO_H_ */
