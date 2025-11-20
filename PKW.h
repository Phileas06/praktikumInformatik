#ifndef PKW_H_ //include guard, aufwendiger aber kompatibler als #pragma once
#define PKW_H_

#include <iostream>
#include <string>

#include "Fahrzeug.h"

class PKW : public Fahrzeug {
private:
	double p_dVerbrauch; //in Liter /100km
	double p_dTankvolumen;
	double p_dTankinhalt; //in Liter
public:
	virtual void vAusgeben() const override; //auch hier virtual, auch wenn nicht notwendig (da basisklasse aussreicht)

	virtual void vSimulieren() override;

	PKW(std::string fahrzeugName, double maxGeschwindigkeit, double verbrauch, double tankvolumen); //2 Elemente für die Basisklassenkonstruktor

	~PKW();

	double dTanken(double dMenge) override; //größtmöglicher wert (laut Aufgabe)
};

#endif
