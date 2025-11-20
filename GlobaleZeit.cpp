#include <iostream>
#include <cctype> //für tolower
#include <iomanip>
#include "programm.h"
#include "activeVehicles.h"
#include "Fahrzeug.h"
#include "PKW.h"

double iTaktRate; //Simulationsschritte pro Stunde
double dGlobaleZeit = 0.0;

void vKillProgramm() {
	std::cout << "Programm wurde erfolreich beendet." << std::endl;
	PROGRAMM_STATUS = Programm::isKilled;
	return;
}

void vGlobalClock() {
	std::cout << "Wie viele Stunden pro Simulationsschritt sollen vergehen?" << std::endl;
	std::cin >> iTaktRate; //muss debuggen später!!!


	char input;
	while (PROGRAMM_STATUS == Programm::isSimulating) {
		//GlobaleZeit erhöhen
		dGlobaleZeit += iTaktRate;

		//Simulation und Ausgabe der Daten:
		Fahrzeug::vKopf();
		std::cout << std::endl << std::setw(LENGTH_TANKINHALT + LENGTH_GESAMTVERBRAUCH + LENGTH_UNTERKLASSE + LENGHT_GESAMTSTRECKE + LENGHT_MAXGESCHWINDIGKEIT + LENGHT_NAME);
		std::cout << std::setfill('-');
		std::cout << "-" << std::endl;
		std::cout << std::setfill(' ');
		for (auto it = activeVehicles.begin(); it != activeVehicles.end(); ++it) {
			(*it)->vSimulieren();
			(*it)->vAusgeben();
			std::cout << std::endl;
		}


		//Continue?
		do {
			std::cout 	<< std::setw(20) << std::left << "[N]" << "Nächster Simulationsschritt" << std::endl
						<< std::setw(20) << std::left << "[X]" << "Programm terminieren" << std::endl;
		    std::cin >> input;

		    if (tolower(input) != 'n' && tolower(input) != 'x') {
		        std::cout << "Eingabe fehlerhaft!" << std::endl;

		        if (std::cin.fail()) {
		            std::cin.clear();
		        }
		        std::cin.ignore(100000, '\n');

		    }
		} while (tolower(input) != 'x' && tolower(input) != 'n');

		if (tolower(input) == 'x') {
			vKillProgramm();
		}
	}
}
