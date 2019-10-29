/*
 * Interfaz.h
 *
 *  Created on: 29 oct. 2019
 *      Author: agustin
 */

#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include<iostream>
#include"Metrobus.h"
#include"colectivos.h"


class Interfaz {
private:
public:
	void mostrarEstacionDeMetrobus(EstacionMetrobus estacionDeMetrobus);
	void mostrarEstacionDeColectivo(EstacionColectivo estacionDeColectivo);
};

#endif /* SRC_INTERFAZ_H_ */
