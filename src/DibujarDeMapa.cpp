/*
 * DibujarDeMapa.cpp
 *
 *  Created on: 31 oct. 2019
 *      Author: melanie
 */

#include "DibujadorDeMapa.h"

DibujadorDeMapa::DibujadorDeMapa(){
	this->mapa = new BMP();
	this->mapa->SetBitDepth(1);
	//this->mapa->SetSize(X_POR_DEFECTO, Y_POR_DEFECTO);
	this->mapa->ReadFromFile("ciudadDigital.bmp");

}

DibujadorDeMapa::DibujadorDeMapa(BMP & mapaBase){
	this->mapa = new BMP();
	this->mapa->SetSize(mapaBase.TellWidth(), mapaBase.TellHeight());
	RangedPixelToPixelCopy(mapaBase, 0, mapaBase.TellWidth(), 0, mapaBase.TellHeight(), *this->mapa, 0, 0);
}

unsigned int DibujadorDeMapa::obtenerAltura(){
	return this->mapa->TellHeight();
}

unsigned int DibujadorDeMapa::obtenerAncho(){
	return this->mapa->TellWidth();
}

void DibujadorDeMapa::dibujarPunto(unsigned int xCentro, unsigned int yCentro, unsigned int radio, short int rojo, short int verde, short int azul){
	RGBApixel color;
	color.Red = rojo;
	color.Green = verde;
	color.Blue = azul;
	this->dibujarPuntoIterativo(xCentro, yCentro, radio, color);
}

void DibujadorDeMapa::dibujarPuntoIterativo(unsigned int xCentro, unsigned int yCentro, unsigned int radio, RGBApixel color){
	if (radio == 0){
		this->mapa->SetPixel(xCentro, yCentro, color);
	}else{
		unsigned int x, y;
		y = yCentro;
		x = xCentro-radio;
		while(x <= xCentro){
			this->mapa->SetPixel(x, y, color);
			x++;
			y--;
		}
		while(x <= xCentro+radio){
			this->mapa->SetPixel(x, y, color);
			x++;
			y++;
		}
		while(x >= xCentro){
			this->mapa->SetPixel(x, y, color);
			x--;
			y++;
		}
		while(x >= xCentro-radio){
			this->mapa->SetPixel(x, y, color);
			x--;
			y--;
		}
		this->dibujarPuntoIterativo(xCentro, yCentro, radio-1, color);
	}
}

void DibujadorDeMapa::dibujarLinea(unsigned int xInicial, unsigned int yInicial, unsigned int xFinal, unsigned int yFinal, short int rojo, short int verde, short int azul){
	RGBApixel color;
	color.Red = rojo;
	color.Green = verde;
	color.Blue = azul;
	this->dibujarLineaIterativo(xInicial, yInicial, xFinal, yFinal, color);
}

void DibujadorDeMapa::dibujarLineaIterativo(unsigned int xInicial,  unsigned int yInicial, unsigned int xFinal, unsigned int yFinal, RGBApixel color){
	if ((xInicial - xFinal) != 0 || (yInicial - yFinal) != 0){
		int desplazamientoX, desplazamientoY;
		desplazamientoX = xFinal-xInicial;
		desplazamientoY = yFinal-yInicial;
		if (abs(desplazamientoX) <= abs(desplazamientoY)){
			if (desplazamientoY >= 0){
				this->dibujarLineaIterativo(xInicial, yInicial+1, xFinal, yFinal, color);
			}else{
				this->dibujarLineaIterativo(xInicial, yInicial-1, xFinal, yFinal, color);
			}
		}else{
			if (desplazamientoX >= 0){
				this->dibujarLineaIterativo(xInicial+1, yInicial, xFinal, yFinal, color);
			}else{
				this->dibujarLineaIterativo(xInicial-1, yInicial, xFinal, yFinal, color);
			}
		}
	}
	this->mapa->SetPixel(xInicial, yInicial, color);
}
/*
unsigned int DibujadorDeMapa::convertidorDeCoordenadasAPixels(Coordenadas coordenada){

	unsigned int pixelX, pixelY;

	pixelX = (unsigned int)(coordenada.obtenerLongitud() - COORDENADA_X0)*DISTANCIA_PIXEL_X/ DISTANCIA_COORDENADAS_X;
	pixelY = (unsigned int)(coordenada.obtenerLatitud() - COORDENADA_Y0)*DISTANCIA_PIXEL_Y/ DISTANCIA_COORDENADAS_Y;

	return pixelX, pixelY;

}
*/

DibujadorDeMapa::~DibujadorDeMapa(){
	this->mapa->WriteToFile("mapa.bmp");
	delete this->mapa;
}



