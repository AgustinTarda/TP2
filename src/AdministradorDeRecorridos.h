#ifndef SRC_ADMINISTRADORDERECORRIDOS_H_
#define SRC_ADMINISTRADORDERECORRIDOS_H_

#include "Recorrido.h"

class AdministradorDeRecorridos {

private:

	Lista<Recorrido> recorridos;

public:
	Recorrido obtenerRecorridoAlQuePertenece(Parada parada);
	void agregarEstacion(Estacion estacion);

};

#endif /* SRC_ADMINISTRADORDERECORRIDOS_H_ */
