#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <iostream>
using namespace std;

class Fahrzeug {
private:
	std::string p_sName = "";
	const int p_iID; //nicht mit 0 vorbesetzen da const. Muss spätestens im Konstruktor definiert werden
	static inline int p_iMaxID = 0;
public:

	//Default-Konstruktor
	Fahrzeug();

	//Benutzerdefinierter Konstruktor
	Fahrzeug(std::string fahrzeugName);

	//Default-Destruktor
	~Fahrzeug();
};

#endif
