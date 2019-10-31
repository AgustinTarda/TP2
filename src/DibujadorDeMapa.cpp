/*
 * DibojadorDeMapa.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: miguel
 */

#include "DibujadorDeMapa.h"

DibujadorDeMapa::DibujadorDeMapa(){
	this->mapa = new BMP();
	this->mapa->SetSize(X_POR_DEFECTO, Y_POR_DEFECTO);
}

DibujadorDeMapa::DibujadorDeMapa(BMP* mapaBase){
	this->mapa = new BMP();
	this->mapa->SetSize(mapaBase->TellWidth(), mapaBase->TellHeight());
	RangedPixelToPixelCopy(*mapaBase, 0, mapaBase->TellWidth(), 0, mapaBase->TellHeight(), *this->mapa, 0, 0);
}

unsigned int DibujadorDeMapa::obtenerAltura(){
	return this->mapa->TellHeight();
}

unsigned int DibujadorDeMapa::obtenerAncho(){
	return this->mapa->TellWidth();
}

void DibujadorDeMapa::dibujarPunto(double longitudCentro, double latitudCentro, unsigned int radio, short int rojo, short int verde, short int azul){
	RGBApixel color;
	color.Red = rojo;
	color.Green = verde;
	color.Blue = azul;
	unsigned int xCentro, yCentro;
	xCentro = (longitudCentro - int(longitudCentro))*-500;
	yCentro = (latitudCentro - int(latitudCentro))*-500;
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

void DibujadorDeMapa::dibujarLinea(double longitudInicial, double latitudInicial, double longitudFinal, double latitudFinal, short int rojo, short int verde, short int azul){
	RGBApixel color;
	color.Red = rojo;
	color.Green = verde;
	color.Blue = azul;
	unsigned int xInicial, yInicial, xFinal, yFinal;
	xInicial = (longitudInicial - int(longitudInicial))*-500;
	yInicial = (latitudInicial - int (latitudInicial))*-500;
	xFinal = (longitudFinal - int(longitudFinal))*-500;
	yFinal = (latitudFinal - int (latitudFinal))*-500;

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

DibujadorDeMapa::~DibujadorDeMapa(){
	this->mapa->WriteToFile("mapa.bmp");
	delete this->mapa;
}
