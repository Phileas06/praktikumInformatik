#include <string>
#include <iostream>
#include <limits>
#include <iomanip>



#include "Zeit.h"
#include "PKW.h"
#include "Fahrzeug.h"


//Konstruktoren und Destruktoren
PKW::PKW(std::string sFahrzeugName, double dMaxGeschwindigkeit, double dVerbrauch)
: Fahrzeug(sFahrzeugName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(55/2) {};

PKW::PKW(std::string sFahrzeugName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) //Tankvolumen wird immer mitgegeben
: Fahrzeug(sFahrzeugName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen > 0 ? dTankvolumen : 55), p_dTankinhalt(dTankvolumen/2) {};

PKW::~PKW() {};

void PKW::vAusgeben(std::ostream& ostream) const {
	Fahrzeug::vAusgeben(ostream);
	ostream 		<< std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setw(LÄNGE_GESAMT_VERBRAUCH - 1)
					<< p_dGesamtStrecke * p_dVerbrauch/100 << "l" // - n in setw() um Größe der Einheit zu berücksichtigen
					<< std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right)
					<< std::setw(LÄNGE_TANKINHALT - 1) << p_dTankinhalt << "l";
};

void PKW::vSimulieren() {
	if (p_dZeit == dGlobaleZeit) return; //Prüfen ob Fahrzeug in diesem Zeitabschnitt schon simuliert wurde



	//Tankinhalt wird simuliert
	double dZurueckgelegteStrecke = (dGlobaleZeit - p_dZeit) * p_dMaxGeschwindigkeit; //Berechnung durch Zeitdifferenz
	if (p_dTankinhalt > 0) {
		Fahrzeug::vSimulieren(); //Aufruf bereits hier notwendig, da sonst aktuelle geschwindigkeit evtl. auf 0 gesetzt wurde

		if (p_dTankinhalt - dZurueckgelegteStrecke * (p_dVerbrauch / 100) > 0) { //überprüfen, ob tank nach berechnetem Verbrauch leer ist
			p_dTankinhalt -= dZurueckgelegteStrecke * (p_dVerbrauch / 100);
			p_dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit;
			return; //sonst 2facher aufruf
		} else {
			p_dTankinhalt = 0; //
			p_dAktuelleGeschwindigkeit = 0;
		}
		//Fährt durch Reserve weiter, auch wenn Tankinhalt nicht ausreichen würde
	}
	Fahrzeug::vSimulieren(); //Aufruf hier notwendig, da sonst p_dZeit nicht gesetzt wird => gesamteStrecke wird nach Auftanken gefahren (PKW hat nie gehalten)
							//Zeitvergleich in vSimulieren regelt eventuellen doppelten Aufruf
}


double PKW::dTanken(double dMenge = std::numeric_limits<double>::infinity()) { //dMenge = 0, oder nicht angeben => volltanken
	if (dMenge == 0) dMenge = std::numeric_limits<double>::infinity();

	double dGetankteMenge = 0;
	if (p_dTankinhalt + dMenge > p_dTankvolumen) { //Volltanken
		dGetankteMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
	} else {
		p_dTankinhalt += dMenge;
		dGetankteMenge = dMenge;
	}
	return dGetankteMenge;
}
