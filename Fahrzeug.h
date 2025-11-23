//Include Guards
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include <string>
#include <iostream>

#include "Layoutkonstanten.h"

class Fahrzeug {
private:
	static inline int p_iMaxID = 0;

protected:
	std::string p_sName = {};
	double p_dGesamtStrecke = 0; //in km
	double p_dGesamtZeit = 0; //gesamte Fahrzeit
	double p_dZeit = 0; //Zeit zu der das Objekt zuletzt simuliert wurde
	double p_dMaxGeschwindigkeit = 0; //in km/h,
	double p_dAktuelleGeschwindigkeit; //in km/h,

	const double p_dStartZeitpunkt; //MUSS in Konstruktor definiert werden
	const int p_iID;



public:

	//Konstruktoren und Destruktoren:
	Fahrzeug();

	Fahrzeug(std::string sFahrzeugName);

	Fahrzeug(std::string sFahrzeugName, double dGesamtStrecke);

	Fahrzeug(Fahrzeug&) = delete; //Copy-Konstruktor wird verboten

	virtual ~Fahrzeug();

	//Funktionen:

	void operator=(const Fahrzeug& ObjektMitStammdaten);

	bool operator<(const Fahrzeug& vergleichsFahrzeug);

	virtual double dTanken(double dMenge = 55);


	virtual double dGeschwindigkeit();

	static int getMaxID();

	//Simulation und Ausgeben:

	static void vKopf();

	virtual void vAusgeben(std::ostream& o) const;

	virtual void vSimulieren();

};

#endif
