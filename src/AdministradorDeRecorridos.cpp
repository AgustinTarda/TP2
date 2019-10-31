#include "AdministradorDeRecorridos.h"


AdministradorDeRecorridos::AdministradorDeRecorridos(){

}

AdministradorDeRecorridos::AdministradorDeRecorridos(const AdministradorDeRecorridos &otroAdministradorDeRecorridos){
	this->recorridos = otroAdministradorDeRecorridos.recorridos;

}

void AdministradorDeRecorridos::agregarEstacion(Estacion estacion) {
	bool tieneRecorrido = false;

	recorridos.iniciarCursor();
	while (recorridos.avanzarCursor() && !tieneRecorrido) {
		Recorrido recorridoAnalizado = recorridos.obtenerCursor();
		if (recorridoAnalizado.debeContener(estacion)) {
			recorridoAnalizado.agregarEstacion(estacion);
			tieneRecorrido = true;
		}
	}

	if (!tieneRecorrido) {
		crearRecorridoPara(estacion);
	}

}

Recorrido AdministradorDeRecorridos::obtenerRecorridoAlQuePertenece(
		Estacion estacion) {


}
Lista<Recorrido> AdministradorDeRecorridos:: obtenerRecorridos(){
	return this-> recorridos;
}

void AdministradorDeRecorridos::crearRecorridoPara(Estacion estacion) {
	Lista<Estacion> estacionesDelRecorrido;
	estacionesDelRecorrido.agregar(estacion);
	Recorrido recorridoAAgregar(estacion.obtenerLinea(), estacionesDelRecorrido,
			estacion.obtenerTipoDeTransporte());
	this->recorridos.agregar(recorridoAAgregar);
}
