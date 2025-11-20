#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#include "PKW.h"
#include "GlobaleZeit.h"
#include "Fahrzeug.h" //für Konstanten



PKW::PKW(std::string fahrzeugName, double maxGeschwindigkeit, double verbrauch, double tankvolumen = 55)
: Fahrzeug(fahrzeugName, maxGeschwindigkeit), p_dVerbrauch(verbrauch), p_dTankvolumen(tankvolumen), p_dTankinhalt(tankvolumen/2) { //p_iID wurde bereits im Fahrzeug Konstruktor festgelegt
	std::cout 	<< "┌ PKW erstellt!" << std::endl
				<< "├ Name: " << p_sName << std::endl
				<< "└ ID: " << p_iID << std::endl;
};

PKW::~PKW() {
	std::cout 	<< "┌ PKW zerstört!" << std::endl
					<< "├ Name: " << p_sName << std::endl
					<< "└ ID: " << p_iID << std::endl;
}

double PKW::dTanken(double dMenge = std::numeric_limits<double>::infinity()) {
	double dGetankteMenge = 0;
	if (p_dTankinhalt + dMenge > p_dTankvolumen) {
		// Nichts angegeben: Volltanken
		dGetankteMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
	} else {
		p_dTankinhalt += dMenge;
		dGetankteMenge = dMenge;
	}
	return dGetankteMenge;
}

void PKW::vSimulieren() {
	if (p_dZeit == dGlobaleZeit) {//Prüfen ob Fahrzeug in diesem Zeitabschnitt schon simuliert wurde
		return;
	}
	Fahrzeug::vSimulieren();
	double dZurueckgelegteStrecke = iTaktRate * p_dMaxGeschwindigkeit;

	if (p_dTankinhalt - (dZurueckgelegteStrecke / 100) * p_dVerbrauch > 0) {
		p_dTankinhalt = (dZurueckgelegteStrecke / 100) * p_dVerbrauch;
	} else { // liegen geblieben
		p_dTankinhalt = 0;
		//ACHTUNG: HIER MUSS NOCH NACHTANKEN FUNKTIONALITÄT
	}
}

void PKW::vAusgeben() const {
	Fahrzeug::vAusgeben();
	std::cout 	<< std::setw(LENGTH_GESAMTVERBRAUCH) << std::right << p_dGesamtStrecke / p_dTankinhalt
				<< std::setw(LENGTH_TANKINHALT) << std::right << p_dTankinhalt;

};





//OVERRIDE FUNKTION NOCH DEFINIEREN
