#ifndef SRC_ADMINISTRADORDERECORRIDOS_H_
#define SRC_ADMINISTRADORDERECORRIDOS_H_

#include "Recorrido.h"

class AdministradorDeRecorridos {

private:

	Lista<Recorrido*> *recorridos;

public:
	/*
	 * POST: crea la una lista vacia de recorridos
	 */
	AdministradorDeRecorridos();
	/*
	 * PRE: La instancia recibida debe ser un AdministradorDeRecorridos no vacia
	 * POST: crea una copia del administrador de recorridos recibido
	 */
	AdministradorDeRecorridos(
			const AdministradorDeRecorridos &otroAdministradorDeRecorridos);
	/*
	* PRE: La instancia recibida debe ser una Estacion no vacia
	* POST: agrega la estacion a su recorrido
	*/
	void agregarEstacion(Estacion* estacion);

	/*
	 * PRE: recibe una Estacion que tiene una lista una linea asociada
	 * POST: devuelve una lista de las estaciones de esa linea o recorrido
	 */
	Recorrido* obtenerRecorridoAlQuePertenece(Estacion* estacion);

	/*
	 * POST: devuelve una lista de todos los recorridos de las lineas
	 */
	Lista<Recorrido*>* obtenerRecorridos();

	/*
	 * PRE: recibe una estacion con una linea asociado
	 * POST: crea una instancia de recorrido de la linea asociada a la estacion
	 */
	void crearRecorridoPara(Estacion* estacion);

	/*
	 * POST: destruye el administrador de recorridos
	 */
	~AdministradorDeRecorridos();

};

#endif /* SRC_ADMINISTRADORDERECORRIDOS_H_ */
