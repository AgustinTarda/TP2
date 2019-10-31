#ifndef SRC_ADMINISTRADORDERECORRIDOS_H_
#define SRC_ADMINISTRADORDERECORRIDOS_H_

#include "Recorrido.h"

class AdministradorDeRecorridos {

private:

	Lista<Recorrido*> *recorridos;

public:
	AdministradorDeRecorridos();
	void agregarEstacion(Estacion estacion);
	Recorrido obtenerRecorridoAlQuePertenece(Estacion estacion);
	Lista<Recorrido*> obtenerRecorridos();
	void crearRecorridoPara(Estacion estacion);
	~AdministradorDeRecorridos();

};

#endif /* SRC_ADMINISTRADORDERECORRIDOS_H_ */
