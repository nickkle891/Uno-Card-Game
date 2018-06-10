#pragma once
using namespace std;
using namespace System;
using namespace System::Drawing;

class CEscenario {
private:
	int X;
	int Y;
public:
	CEscenario(int X, int Y) {
		this->X = X;
		this->Y = Y;
	};
	void validar() {};
};