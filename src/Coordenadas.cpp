#include "Coordenadas.h"
using namespace std;

Coordenadas::Coordenadas(double latitud, double longitud) {

	this->latitud = latitud;
	this->longitud = longitud;
}

Coordenadas::Coordenadas(const Coordenadas &otrasCoordenadas) {

	this->latitud = otrasCoordenadas.latitud;
	this->longitud = otrasCoordenadas.longitud;
}

Coordenadas::Coordenadas() {

	this->latitud = 0;
	this->longitud = 0;
}

double Coordenadas::getLatitud() {
	return this->latitud;
}

double Coordenadas::getLongitud() {
	return this->longitud;
}

double Coordenadas::calcularDistancia(const Coordenadas coordenadasFinal) {

	double distanciaA, distanciaC, distanciTotal;

	double diferencialLatitud = toRad(coordenadasFinal.latitud - this->latitud);
	double diferencialLongitud = toRad(
			coordenadasFinal.longitud - this->longitud);

	distanciaA = sin(diferencialLatitud / 2) * sin(diferencialLatitud / 2)
			+ cos(toRad(this->latitud)) * cos(toRad(coordenadasFinal.latitud))
					* sin(diferencialLongitud / 2)
					* sin(diferencialLongitud / 2);
	distanciaC = 2 * (atan2(sqrt(distanciaA), sqrt(1 - distanciaA)));

	distanciTotal = 6371000 * distanciaC;
	return distanciTotal;

}

double Coordenadas::toRad(double degree) {
	return degree / 180 * pi;
}
