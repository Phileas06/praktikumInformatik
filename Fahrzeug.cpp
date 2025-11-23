#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

#include "Fahrzeug.h"
#include "Layoutkonstanten.h"
#include "Zeit.h"
#include "Ausgabeverwaltung.h"

using namespace std;



//Konstruktoren und Destruktoren:
Fahrzeug::Fahrzeug() : p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++) {
	cout 	<< "Fahrzeug erstellt! | "
			<<"Name: " << "Nicht vergeben | "
			<< "ID: " << p_iID << endl;
}

Fahrzeug::Fahrzeug(std::string sFahrzeugName) : p_sName(sFahrzeugName), p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++) {
	cout 	<< "Fahrzeug erstellt! | "
			<< "Name: " << p_sName << " | "
			<< "ID: " << p_iID << endl;
}

Fahrzeug::Fahrzeug(string sFahrzeugName, double dMaxGeschwindigkeit)
: p_sName(sFahrzeugName), p_dMaxGeschwindigkeit(dMaxGeschwindigkeit > 0 ? dMaxGeschwindigkeit : 0), p_dAktuelleGeschwindigkeit(p_dMaxGeschwindigkeit), p_dStartZeitpunkt(dGlobaleZeit), p_iID(p_iMaxID++) { //Prüfen von Geschwindigkeit mit ternary überflüssig, da Eingabeverwaltung schon prüft
	cout 	<< "Fahrzeug erstellt! | "
			<< "Name: " << p_sName << " | "
			<< "ID: " << p_iID << endl;
};

Fahrzeug::~Fahrzeug() {
	cout 	<< "Fahrzeug zerstört! | "
			<< "Name: " << p_sName << " | "
			<< "ID: " << p_iID << endl;
};

//Funktionen:

void Fahrzeug::operator=(const Fahrzeug& ObjektMitStammdaten) {
	this->p_dMaxGeschwindigkeit = ObjektMitStammdaten.p_dMaxGeschwindigkeit;
	this->p_sName = ObjektMitStammdaten.p_sName;
	//Startzeitpunkt oder ID dürfen nicht kopiert werden
}

bool Fahrzeug::operator<(const Fahrzeug& vergleichsFahrzeug) {
	return this->p_dGesamtStrecke < vergleichsFahrzeug.p_dGesamtStrecke;
}

double Fahrzeug::dTanken(double dMenge) { // dMenge optional, siehe deklaration in header file
	return 0;
};

double Fahrzeug::dGeschwindigkeit() {
	return p_dMaxGeschwindigkeit;
};

int Fahrzeug::getMaxID() {
	return Fahrzeug::p_iMaxID;
}

void Fahrzeug::vKopf() {
	cout 	<< setw(LÄNGE_ID) << resetiosflags(ios::left) << setiosflags(ios::right) << "ID  " //puffer
			<< setw(LÄNGE_NAME) << resetiosflags(ios::right) << setiosflags(ios::left) << "Name"
			<< setw(LÄNGE_MAX_GESCHWINDIGKEIT) << resetiosflags(ios::left) << setiosflags(ios::right) << "MaxGeschwindigkeit"
			<< setw(LÄNGE_AKTUELLE_GESCHWINDIGKEIT) << "Aktuelle Geschwindigkeit"
			<< setw(LÄNGE_GESAMT_STRECKE) << "Gesamtstrecke"
			<< setw(LÄNGE_GESAMT_VERBRAUCH) << "Gesamtverbrauch"
			<< setw(LÄNGE_TANKINHALT) <<"Tankinhalt";

	//Gestrichelte Linie erstellen
	cout << endl << setw(LÄNGE_ID + LÄNGE_NAME + LÄNGE_MAX_GESCHWINDIGKEIT + LÄNGE_GESAMT_STRECKE + LÄNGE_GESAMT_VERBRAUCH + LÄNGE_TANKINHALT + LÄNGE_AKTUELLE_GESCHWINDIGKEIT);
	cout << setfill('-');
	cout << "-" << endl;
	cout << setfill(' ');
};

void Fahrzeug::vAusgeben(std::ostream& ostream) const {

	ostream		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(LÄNGE_ID - 2) << this->p_iID << "  " // - 2 wegen puffer
				<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(LÄNGE_NAME) << this->p_sName
				<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(LÄNGE_MAX_GESCHWINDIGKEIT - 4) << this->p_dMaxGeschwindigkeit << "km/h"
				<< setw(LÄNGE_AKTUELLE_GESCHWINDIGKEIT - 4) << this->p_dAktuelleGeschwindigkeit << "km/h"
				<< setw(LÄNGE_GESAMT_STRECKE - 2) << this->p_dGesamtStrecke << "km";

	//Andere Werte werden in den Subklassen ausgegeben
};

void Fahrzeug::vSimulieren() {
	if (p_dZeit == dGlobaleZeit) return; //Prüfen ob Fahrzeug in diesem Zeitabschnitt schon simuliert wurde


	this->p_dGesamtStrecke += (dGlobaleZeit - p_dZeit) * p_dAktuelleGeschwindigkeit; //Zeitdifferenz * aktuelle geschwindigkeit (Aktuelle Geschwindigkeit 0, wenn Tank leer)
	dGeschwindigkeit(); //Neuberechnung der Geschwindigkeit der Fahrräder (erst nachdem Gesamtstrecke gesetzt wurde)
	this->p_dGesamtZeit = dGlobaleZeit - this->p_dStartZeitpunkt;
	this->p_dZeit = dGlobaleZeit;
}










