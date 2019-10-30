#ifndef SRC_ADMINISTRADORDERECORRIDOS_H_
#define SRC_ADMINISTRADORDERECORRIDOS_H_

#include "Recorrido.h"

class AdministradorDeRecorridos {

private:

	Lista<Recorrido> recorridos;

public:
	void agregarEstacion(Estacion estacion);
	Recorrido obtenerRecorridoAlQuePertenece(Estacion estacion);
	void crearRecorridoPara(Estacion estacion);

};

#endif /* SRC_ADMINISTRADORDERECORRIDOS_H_ */
