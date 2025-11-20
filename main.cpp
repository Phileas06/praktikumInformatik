#include <iostream>
#include <memory>
#include <vector>
#include <cstdio>

#include "programm.h"
#include "Fahrzeug.h"
#include "GlobaleZeit.h"
#include "activeVehicles.h"

std::vector<std::unique_ptr<Fahrzeug>> activeVehicles;

void vCreateVehicle(std::string name, double maxVelocity) {
	activeVehicles.push_back(std::make_unique<Fahrzeug>(name, maxVelocity));
}

void clearBuffer() {
	std::cin.ignore(1000, '\n'); //leert den buffer, um fehlerhafte eingaben zu korrigieren
}

void vScanString(std::string& name) {

	while (true) {
		// 1. Eingabe
		std::getline(std::cin, name);
		if (!name.empty()) { // Prüft, ob das Lesen erfolgreich war
			// Erfolg

			break;
		} else {
			// 2. Fehlerbehebung
			std::cout << "Fehler beim Einlesen." << std::endl;
			std::cin.clear(); // Setzt das Fehler-Flag zurück
			//clearBuffer();
			std::cout << "Erneut eingeben:" << std::endl;
			continue;
		}
	}
}

void vAufgabe_1a() {
	char input;
	std::string name;
	double maxVelocity;
	while(PROGRAMM_STATUS == Programm::isCreating) {
		std::cout << "Möchtest du ein weiteres Fahrzeug erstellen?" << std::endl << "[J] Ja" << std::endl << "[N] Nein" << std::endl;
		std::cin >> input; //debug, was wenn zahl, wenn string
		clearBuffer();
		switch (input) {
			case 'n':
				PROGRAMM_STATUS = Programm::isSimulating;
				vGlobalClock();
				break;
			case 'j':
				std::cout << "Gib den Namen des Fahrzeuges ein: " << std::endl;
				vScanString(name);


				std::cout << "Gib die maximale Geschwindigkeit des Fahrzeugs ein:" << std::endl;
				std::cin >> maxVelocity;
				clearBuffer();
				vCreateVehicle(name, maxVelocity);
				break;
			default: continue;
		}
	}
}

int main() {
	vAufgabe_1a();
	return 0;
}
