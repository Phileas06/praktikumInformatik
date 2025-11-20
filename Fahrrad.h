#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include <iostream>

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
private:

	//private hier
public:
	Fahrrad();

	static void vKopf();

	virtual void vAusgeben() const override; //auch hier virtual

	double dTanken(double dMenge) override;

};


#endif
