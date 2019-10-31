#ifndef SRC_ADMINISTRADORDERECORRIDOS_H_
#define SRC_ADMINISTRADORDERECORRIDOS_H_

#include "Recorrido.h"

class AdministradorDeRecorridos {

private:

	Lista<Recorrido> recorridos;

public:
	AdministradorDeRecorridos();
	AdministradorDeRecorridos(
			const AdministradorDeRecorridos &otroAdministradorDeRecorridos);
	void agregarEstacion(Estacion estacion);
	Recorrido obtenerRecorridoAlQuePertenece(Estacion estacion);
	void crearRecorridoPara(Estacion estacion);
	Lista<Recorrido> obtenerRecorridos();

};

#endif /* SRC_ADMINISTRADORDERECORRIDOS_H_ */
