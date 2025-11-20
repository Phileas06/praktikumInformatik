#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <iostream>

#define LENGHT_NAME 20
#define LENGHT_MAXGESCHWINDIGKEIT 20
#define LENGHT_GESAMTSTRECKE 15 //13 länge des wortes + 2 puffer
#define LENGTH_UNTERKLASSE 20
#define LENGTH_GESAMTVERBRAUCH 20
#define LENGTH_TANKINHALT 20

//niemals namespace in header dateien

enum class Velocity { //enum class statt nur enum, damit ich Velocity::tometerPerSecond schreiben muss (namenskollisionen vermeiden)
	toMeterPerSecond,
	toKilometerPerHour
};

class Fahrzeug {
protected:
	std::string p_sName = {}; //initialisiere als leeren string
	double p_dGesamtStrecke = 0;
	double p_dGesamtZeit = 0; //gesamte Fahrzeit
	double p_dZeit = 0; //Zeit zu der das Fahrzeug zuletzt simuliert wurde :: muss eventuell auf globale Zeit gesetzt werden
	double p_dMaxGeschwindigkeit = 0; //im km/h

	//Eigene
	double p_dStartZeitpunkt; // wird in konstruktoren initialisiert

	const int p_iID; //nicht mit 0 vorbesetzen da const. Muss spätestens im Konstruktor definiert werden

	static inline int p_iMaxID = 0;


	static int iCalcIDLen(int iID); //const?
	double dConvertVelocity(double dvelocity, Velocity iconversionInstruction);
public:
	virtual double dTanken(double dMenge);

	//Default-Konstruktor
	Fahrzeug();

	//Konstruktor FahrzeugName
	Fahrzeug(std::string fahrzeugName);

	//Konstruktor FahrzeugName & MaxGeschwindigkeit
	Fahrzeug(std::string fahrzeugName, double gesamtStrecke);

	//Default-Destruktor
	virtual ~Fahrzeug(); // Destruktor immer als virtual

	std::string getName() const;

	double getMaxVelocity() const;

	static void vKopf();

	virtual void vAusgeben() const; //virtual nur in Basisklasse notwendig

	virtual void vSimulieren(); //hier nicht const, da es werte ändert
};

#endif
