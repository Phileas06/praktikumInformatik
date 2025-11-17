#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <iostream>
using namespace std;

class Fahrzeug {
private:
	std::string p_sName = {};
	double p_dGesamtStrecke;
	double p_dGesamtZeit; //gesamte Fahrzeit
	double p_dZeit; //Zeit zu der das Fahrzeug zuletzt simuliert wurde
	double p_dMaxGeschwindigkeit = 0;

	const int p_iID; //nicht mit 0 vorbesetzen da const. Muss spätestens im Konstruktor definiert werden

	static inline int p_iMaxID = 0;
public:

	//Default-Konstruktor
	Fahrzeug();

	//Konstruktor FahrzeugName
	Fahrzeug(std::string fahrzeugName);

	//Konstruktor FahrzeugName & MaxGeschwindigkeit
	Fahrzeug(std::string fahrzeugName, double gesamtStrecke);

	//Default-Destruktor
	~Fahrzeug();

	std::string getName() const;
};

#endif
