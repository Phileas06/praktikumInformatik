#include <cmath>
#include <string>
#include <iostream>

#include "Fahrrad.h"
#include "Fahrzeug.h"

Fahrrad::Fahrrad(std::string sFahrzeugName, double dMaxGeschwindigkeit) : Fahrzeug(sFahrzeugName, dMaxGeschwindigkeit) {};

Fahrrad::~Fahrrad() {};

double Fahrrad::dGeschwindigkeit()  { //const
	double dNeueGeschwindigkeit = (p_dMaxGeschwindigkeit * std::pow(0.90, (int) p_dGesamtStrecke / 20)); //int cast sorgt für int division => abrunden

	if (dNeueGeschwindigkeit > 12) {
			p_dAktuelleGeschwindigkeit = dNeueGeschwindigkeit;
		} else {
			p_dAktuelleGeschwindigkeit = 12;
	}

	return p_dAktuelleGeschwindigkeit;
}

void Fahrrad::vAusgeben(std::ostream& o) const {
	Fahrzeug::vAusgeben(o);
};
