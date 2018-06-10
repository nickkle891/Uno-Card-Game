/*#pragma once
#include <vector>
#include "CCarta.h"
#include <string>

using namespace std;
using namespace System;
using namespace System::Drawing;

class CJugador {
private:
	int puntos;
	int turno;
	string nombre;
	vector<CCarta^> cartas;
public:
	CJugador(int puntos, int turno, string nombre, vector<CCarta^> cartas) {
		this->puntos = puntos;
		this->turno = turno;
		this->nombre = nombre;
		this->cartas = cartas;
	};
	~CJugador() {
		this->puntos = 0;
		this->turno = 0;
		this->nombre = "";
	}
	void setPuntos(int puntos) { this->puntos = puntos; }
	int getPuntos() { return this->puntos; }
	void setTurno(int turno) { this->turno = turno; }
	int getTurno() { return this->turno; }
	void setNombre(string nombre) { this->nombre = nombre; }
	string getNombre() { return this->nombre; }
	void setcartas(vector<CCarta^>cartas) { this->cartas = cartas; }
	vector<CCarta^>getcartas() { return this->cartas; }
	void cogerCarta() {};
	void colocarCarta() {};

};
*/