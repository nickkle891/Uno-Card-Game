/*#pragma once
#include "CMazo.h"
#include "CJugador.h"
#include "CEscenario.h"
#include <vector>

using namespace std;
using namespace System;
using namespace System::Drawing;

class CJuego {
private:
	vector<CJugador*> jugadores;
	CEscenario* esc;
	CMazo* mazo;
public:
	CJuego(vector<CJugador*> jugadores, CEscenario* esc, CMazo* mazo) {
		this->jugadores = jugadores;
		this->esc = esc;
		this->mazo = mazo;
	}
	~CJuego() {
		for (int i = 0; i < jugadores.size(); i++) {
			delete jugadores.at(i);
		}
		delete esc;
		delete mazo;


	}
	void penalizar() {};
};*/