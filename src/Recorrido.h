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

	/*
	 * pre: recibe una instancia de recorrido no vacia.
	 * post: hace una copia del recorrido.
	 */
	Recorrido(const Recorrido &otroRecorrido);

	/*
	 * pre: recibe la linea y el tipo de transporte del recorrido.
	 * post: crea una instancia con los datos recibidos.
	 */
	Recorrido(std::string linea, Estacion::TipoDeTransporte tipoDeTransporte);

	/*
	 * pre: recibe una lista de estaciones no vacia, la linea y el tipo de transporte del recorrido.
	 * post: crea una instancia de recorrido con los datos recibidos.
	 */
	Recorrido(std::string linea, Lista<Estacion*> *estaciones,
			Estacion::TipoDeTransporte tipoDeTransporte);

	/*
	 * post: devuelve la lista de estaciones de la instancia.
	 */
	Lista<Estacion*>* obtenerEstaciones();

	/*
	 * post: devuelve la linea de la instancia.
	 */
	std::string obtenerLinea();

	/*
	 * post: devuelve el tipo de transporte de la instancia.
	 */
	Estacion::TipoDeTransporte obtenerTipoDeTransporte();

	/*
	 * post: devuelve true si la estacion recibida está en la lista de estaciones.
	 */
	bool debeContener(Estacion *estacion);

	/*
	 * pre: recibe una estacion.
	 * post: se agrega la estacion recibida a la lista de estaciones.
	 */
	void agregarEstacion(Estacion *estacion);

	/*
	 * post: destruye la instancia de recorrido.
	 */
	~Recorrido();
};

#endif /* SRC_RECORRIDO_H_ */
