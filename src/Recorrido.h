#ifndef SRC_RECORRIDO_H_
#define SRC_RECORRIDO_H_

#include <string>
#include "Lista.h"
#include "Estacion.h"

class Recorrido {

public:
	enum TipoDeTransporte {
			SUBTE, COLECTIVO, METROBUS, FERROCARRIL, GARAGE
		};
private:

	std::string linea;
	Lista<Estacion> estaciones;
	TipoDeTransporte tipoDeTransporte;


public:

	Recorrido();
	Recorrido(const Recorrido& otroRecorrido);


};

#endif /* SRC_RECORRIDO_H_ */
