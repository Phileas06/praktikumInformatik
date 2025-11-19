#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <iostream>

//niemals namespace in header dateien

enum class Velocity {
	toMeterPerSecond,
	toKilometerPerHour
};

class Fahrzeug {
private:
	std::string p_sName = {}; //initialisiere als leeren string
	double p_dGesamtStrecke = 0;
	double p_dGesamtZeit = 0; //gesamte Fahrzeit
	double p_dZeit = 0; //Zeit zu der das Fahrzeug zuletzt simuliert wurde :: muss eventuell auf globale Zeit gesetzt werden
	double p_dMaxGeschwindigkeit = 0; //im km/h

	//Eigene
	double p_dStartZeitpunkt; // wird in konstruktoren initialisiert

	const int p_iID; //nicht mit 0 vorbesetzen da const. Muss spätestens im Konstruktor definiert werden

	static inline int p_iMaxID = 0;


	int iCalcIDLen(int iID); //const?
	double dConvertVelocity(double dvelocity, Velocity iconversionInstruction);
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

	double getMaxVelocity() const;

	static void vKopf();

	void vAusgeben() const;

	void vSimulieren(); //hier nicht const, da es werte ändert
};

#endif
