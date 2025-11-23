#include "Zeit.h"
#include "Programm.h"

#include <iostream>

double dGlobaleZeit = 0.0;
double dTaktRate = 0.0; // wird durch Anwender spezifiziert

double iTimePoint = 0;

void vErhöheGlobalTakt() {
	dGlobaleZeit += dTaktRate;


	//Für Aufgabe 2: Nach 3 Stunden nachtanken

	if (iTimePoint && dGlobaleZeit >= iTimePoint) {
		dGlobaleZeit = iTimePoint;
		std::cout << iTimePoint << " Stunden vergangen: Auftanken!" << std::endl;
		iTimePoint = 0;
		Programm::Tanken();
	}
}

void vSetTimePoint(double iPoint) {
	iTimePoint = iPoint;
}
