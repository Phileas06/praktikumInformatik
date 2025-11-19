#include "Fahrzeug.h"
#include "GlobaleZeit.h"

#include <string> //best practice aber nicht notwendig, include guards regelt
#include <iostream>
#include <iomanip>

using namespace std;

#define LENGHT_NAME 20
#define LENGHT_MAXGESCHWINDIGKEIT 50
#define LENGHT_GESAMTSTRECKE 15 //13 länge des wortes + 2 puffer



//Default-Konstruktor
Fahrzeug::Fahrzeug() : p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++)  {
	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name noch nicht zugewiesen" << endl
			<< "└ ID: " << p_iID << endl;
}

//Benutzerdefinierter Konstruktor
Fahrzeug::Fahrzeug(std::string fahrzeugName) : p_sName(fahrzeugName), p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++) {


	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name: " << p_sName << endl
			<< "└ ID: " << p_iID << endl;
}

//Konstruktor fahrzeugName + MaxGeschwindigkeit
Fahrzeug::Fahrzeug(std::string fahrzeugName, double maxGeschwindigkeit) : p_sName(fahrzeugName), p_dMaxGeschwindigkeit(maxGeschwindigkeit > 0 ? maxGeschwindigkeit : 0), p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++) {
	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name: " << p_sName << endl
			<< "├ Maximale Geschwindigkeit: " << p_dMaxGeschwindigkeit << endl
			<< "└ ID: " << p_iID << endl;
}

Fahrzeug::~Fahrzeug() {
	cout 	<< "┌ Fahrzeug zerstört!" << endl
			<< "├ " << ((p_sName == "") ? "Name nicht vergeben" : p_sName) << endl //hier klammern da cout niedrigere prio hat
			<< "└ ID: " << p_iID << endl;
}

//Bestimmt die Länge meiner ID, um dynamisch meine Tabelle anzupassen: mind. 5
int iIDCalcLen(int iID) {
	int ilen = 0;
	while(iID > 0) {
		iID /= 10;
		ilen++;
	};
	return (ilen < 5) ? 5 : ilen;
}
/*
double Fahrzeug::dConvertVelocity(double dVelocity, Velocity iConversionInstruction) {
	switch(iConversionInstruction) {
	case Velocity::toMeterPerSecond:
		return dVelocity / 3.6;
		break;
	case Velocity::toKilometerPerHour:
		return dVelocity * 3.6;
	break;
	default:
		return 0;
	}
}
*/
std::string Fahrzeug::getName() const {
	return this->p_sName;
}

double Fahrzeug::getMaxVelocity() const {
	return this->p_dMaxGeschwindigkeit;
}

void Fahrzeug::vKopf() { //hier kein type qualifier, wie const
	std::cout 	<< std::setw(iIDCalcLen(p_iMaxID)) << std::left << "ID"
				<< std::setw(LENGHT_NAME) << "Name"
				<< std::setw(LENGHT_MAXGESCHWINDIGKEIT) << "MaxGeschwindigkeit"
				<< std::setw(LENGHT_GESAMTSTRECKE) << "Gesamtstrecke" << endl;

	std::cout	<< std::setw(iIDCalcLen(p_iMaxID) + LENGHT_NAME + LENGHT_MAXGESCHWINDIGKEIT + LENGHT_GESAMTSTRECKE)
				<< std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void Fahrzeug::vAusgeben() const {
	std::cout	<< std::setw(iIDCalcLen(p_iMaxID) - 2) << std::right << this->p_iID << "  " //puffer zur optischen trennung von name und zahl
				<< std::setw(LENGHT_NAME) << std::left << this->p_sName
				<< std::setw(LENGHT_MAXGESCHWINDIGKEIT) << std::right << this->p_dMaxGeschwindigkeit
				<< std::setw(LENGHT_GESAMTSTRECKE) << std::right << this->p_dGesamtStrecke;
}


void Fahrzeug::vSimulieren() {
	if (p_dZeit == dGlobaleZeit) {//Prüfen ob Fahrzeug in diesem Zeitabschnitt schon simuliert wurde
		return;
	}
	this->p_dGesamtStrecke += iTaktRate * this->p_dMaxGeschwindigkeit;//geschwindigkeit wird erhöht
	this->p_dGesamtZeit = dGlobaleZeit - this->p_dStartZeitpunkt;
	this->p_dZeit = dGlobaleZeit;
}
