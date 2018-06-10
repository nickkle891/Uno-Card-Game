#pragma once
using namespace System;
using namespace System::Drawing;

public ref class CCarta {
protected:
	int color;
	int valor;
	int posY;
	int posX;
	
	System::String^ ruta;
public:
	CCarta(int color, int valor, System::String^ ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = 0;
		this->posX = 0;
		
		this->ruta = ruta;
	};
	~CCarta() {
		this->color = 0;
		this->valor = 0;
		this->posY = 0;
		this->posX = 0;
		
	}
	void setColor(int color) { this->color = color; }
	int getColor() { return this->color; }
	void setValor(int valor) { this->valor = valor; }
	int getValor() { return this->valor; }
	void setPosX(int posX) { this->posX = posX; }
	int getPosX() { return this->posX; }
	void setPosY(int posY) { this->posY = posY; }
	int getPosY() { return this->posY; }
	
	void dibujar(BufferedGraphics ^buffer) {

		
		Bitmap^ bm = gcnew Bitmap(ruta);
		//bm->MakeTransparent(bm->GetPixel(1, 1));
		int anchoImagen = bm->Width;
		int altoImagen = bm->Height;
		//canvas->Clear(Color::Red);
		// Declaramos un rectangulo con las dimensiones del pedazo del sprite a utilizar  
		Rectangle porcionAUsar = Rectangle(0, 0, anchoImagen, altoImagen);
		// Dibujamos la imagen en la posicion 50, 50
		buffer->Graphics->DrawImage(bm, posX, posY, porcionAUsar, GraphicsUnit::Pixel);
	}


};
/*
class CRobados : public ref CCarta {
public:
	CRobados() :CCarta(color, valor, posY, posX, indice,ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = posY;
		this->posX = posX;
		this->indice = indice;
	}
	void robarCarta() {};
	void perderTurno() {};
};
 class CCambiasentido : public CCarta {
public:
	CCambiasentido() :CCarta(color, valor, posY, posX, indice,ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = posY;
		this->posX = posX;
		this->indice = indice;
	}
	void cambiarSentido() {};
};
 class CPierdeturno : public CCarta {
public:
	CPierdeturno() :CCarta(color, valor, posY, posX, indice,ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = posY;
		this->posX = posX;
		this->indice = indice;
	}
	void perderTurno() {};
};
 class CComodin : public CCarta {
public:
	CComodin() :CCarta(color, valor, posY, posX, indice,ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = posY;
		this->posX = posX;
		this->indice = indice;
	}
	void cambiaCarta() {};
};
 class CComodinroba4 : public  CCarta {
public:
	CComodinroba4() :CCarta(color, valor, posY, posX, indice,ruta) {
		this->color = color;
		this->valor = valor;
		this->posY = posY;
		this->posX = posX;
		this->indice = indice;
	}
	void robarCarta() {};
	void perderTurno() {};
	void cambiaColor() {};
	
};*/