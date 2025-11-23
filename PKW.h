//Include Guard
#ifndef PKW_H_
#define PKW_H_

#include <iostream>

#include "Fahrzeug.h"

class PKW : public Fahrzeug {
private:
	double p_dVerbrauch; //in Liter /100km
	double p_dTankvolumen;
	double p_dTankinhalt; //Standard 50% Tankvolumen

public:
	//Konstruktoren und Destruktoren
	PKW(std::string sFahrzeugName, double dMaxGeschwindigkeit, double dVerbrauch);

	PKW(std::string sFahrzeugName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen); //2 Elemente für Basisklassenkonstruktor

	virtual ~PKW();

	//Funktionen
	double dTanken(double dMenge) override;

	//Simulation und Ausgeben

	virtual void vAusgeben(std::ostream& o) const override;

	virtual void vSimulieren() override;



};

#endif
