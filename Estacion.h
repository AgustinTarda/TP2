#ifndef ESTACION_H_
#define ESTACION_H_

#include <string>

struct Estacion {
	double longitud;
	double latitud;
	int id;
	std::string nombre;
	std::string calle1;
	std::string calle2;
	std::string interseccion;
	std::string lineasSentidoNorte;
	std::string lineasSentidoSur;
	std::string metrobus;
	std::string nombreSentidoId;
	std::string observacion;
};

struct Intervalo {
	double maximo;
	double minimo;
};

#endif /* ESTACION_H_ */
