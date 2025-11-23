//Include Guard
#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include <string>
#include <iostream>

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
	Fahrrad(std::string sFahrzeugName, double dMaxGeschwindigkeit);

	virtual ~Fahrrad();

	double dGeschwindigkeit() override;

	virtual void vAusgeben(std::ostream&) const override;

};

#endif
