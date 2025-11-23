#include "Ausgabeverwaltung.h"
#include "Fahrzeug.h"

#include <iostream>


std::ostream& operator<<(std::ostream& ostream, const Fahrzeug& fahrzeug) {
	fahrzeug.vAusgeben(ostream); //ruft fahrzeug.vAusgeben auf und übergibt referenz von ostream => Polymorphie sorgt für Aufruft von PKW/Fahrrad.vAusgeben()

	return ostream;
}

