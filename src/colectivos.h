/*
 * colectivos.h
 *
 *  Created on: 17 oct. 2019
 *      Author: melanie
 */


#ifndef SRC_COLECTIVOS_H_
#define SRC_COLECTIVOS_H_

#include <string>

class EstacionColectivo{
	private:
		unsigned int id;
		unsigned int codigo;
		std:: string nombre;
		int latitud;
		int longitud;
		unsigned int idDireccion;
		unsigned int idRuta;
		unsigned int idAgencia;
		std:: string rutaNombreCorto;
		std:: string rutaNombreLargo;
		std:: string rutaDesc;
		unsigned int tipoRuta;
};



#endif /* SRC_COLECTIVOS_H_ */
