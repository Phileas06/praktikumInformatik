#include "Fahrzeug.h"
#include <string> //best practice aber nicht notwendig, include guards regelt

//Default-Konstruktor
Fahrzeug::Fahrzeug() : p_iID(p_iMaxID++) {
	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name noch nicht zugewiesen" << endl
			<< "└ ID: " << p_iID << endl;
}

//Benutzerdefinierter Konstruktor
Fahrzeug::Fahrzeug(std::string fahrzeugName) : p_sName(fahrzeugName), p_iID(p_iMaxID++) {


	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name: " << p_sName << endl
			<< "└ ID: " << p_iID << endl;
}

//Konstruktor fahrzeugName + MaxGeschwindigkeit
Fahrzeug::Fahrzeug(std::string fahrzeugName, double maxGeschwindigkeit) : p_iID(p_iMaxID++), p_sName(fahrzeugName), p_dMaxGeschwindigkeit(maxGeschwindigkeit) {
	cout 	<< "┌ Fahrzeug erstellt!" << endl
			<< "├ Name: " << p_sName << endl
			<< "├ Maximale Geschwindigkeit: " << endl
			<< "└ ID: " << p_iID << endl;
}

Fahrzeug::~Fahrzeug() {
	cout 	<< "┌ Fahrzeug zerstört!" << endl
			<< "├ " << ((p_sName == "") ? "Name nicht vergeben" : p_sName) << endl //hier klammern da cout niedrigere prio hat
			<< "└ ID: " << p_iID << endl;
}

std::string Fahrzeug::getName() const {
	return this->p_sName;
}
