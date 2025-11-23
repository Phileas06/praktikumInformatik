#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdexcept>

#include "programm.h"
#include "Eingabeverwaltung.h"
#include "Ausgabeverwaltung.h"
#include "AktiveFahrzeuge.h"
#include "Zeit.h"
#include "PKW.h"
#include "Fahrrad.h"


ProgrammStatus PROGRAMM_STATUS = ProgrammStatus::Startup;

using namespace std; //std wird hier oft genutzt

string name = "";
double dMaxGeschwindigkeit;
double dVerbrauch;
double dTankvolumen;
double dGetankteMenge;
double dTankMenge;
bool bIstPKW;
bool bGibtTankvolumen; //Optional
bool bNeuesFahrzeug;
bool bNachtanken;
int iID;

void vSchaffeObjekt() {
	if (bIstPKW) {
		AktiveFahrzeuge.push_back(make_unique<PKW>(name, dMaxGeschwindigkeit, dVerbrauch, (bGibtTankvolumen ? dTankvolumen : 55)));
	} else { //Fahrrad erstellen
		AktiveFahrzeuge.push_back(make_unique<Fahrrad>(name, dMaxGeschwindigkeit));
	}
}

void Programm::Startup() {
	//ABFRAGE
	cout 	<< "Erstelle dein erstes Fahrzeug:" << endl
			<< "├ Name: ";
	name = sLiesString(StringParameter::Woerter);

	cout 	<< "├ Maximale Geschwindigkeit des Fahrzeugs: ";
	dMaxGeschwindigkeit = liesZahl<double>(ZahlenParameter::PositivUndNull);

	cout 	<< "├ Möchtest du ein PKW erstellen?" << endl
			<< "├ [J] PKW" << endl
			<< "└ [N] Fahrrad" << endl;


	if ( (bIstPKW = bVerwalteJN()) ) {
		cout << "Gib den Verbrauch (l/100km) ein: ";
		dVerbrauch = liesZahl<double>(ZahlenParameter::NurPositiv);

		cout	<< "Möchtest du das Tankvolumen spezifizieren? (sonst 55l)" << endl
				<< "├ [J] Ja" << endl
				<< "└ [N] Nein" << endl;

		if ( (bGibtTankvolumen = bVerwalteJN()) ) {
			cout << "Gib Tankvolumen ein: ";
			dTankvolumen = liesZahl<double>(ZahlenParameter::NurPositiv);
		} else {
			dTankvolumen = 55;
		}
	}

	vSchaffeObjekt();

	Programm::Erstellen();
}

void Programm::Erstellen() {
	PROGRAMM_STATUS = ProgrammStatus::Erstellen;

	do {
		cout 	<< "Möchtest du ein weiteres Fahrzeug erstellen?" << endl
				<< "├ [J] Ja" << endl
				<< "└ [N] Nein" << endl;


		switch(bNeuesFahrzeug = bVerwalteJN()) {
		case 1: //FAHRZEUG ERSTELLEN

			cout 	<< "┌ Name: ";
			name = sLiesString(StringParameter::Woerter);

			cout 	<< "├ Maximale Geschwindigkeit des Fahrzeugs: ";
			dMaxGeschwindigkeit = liesZahl<double>(ZahlenParameter::PositivUndNull);

			cout 	<< "├ Möchtest du ein PKW erstellen?" << endl
					<< "├ [J] PKW" << endl
					<< "└ [N] Fahrrad" << endl;

			if ( (bIstPKW = bVerwalteJN()) ) {
					cout << "Gib den Verbrauch (l/100km) ein: ";
					dVerbrauch = liesZahl<double>(ZahlenParameter::NurPositiv);

					cout	<< "Möchtest du das Tankvolumen spezifizieren? (sonst 55l)" << endl
							<< "├ [J] Ja" << endl
							<< "└ [N] Nein" << endl;

					if ( (bGibtTankvolumen = bVerwalteJN()) ) {
						cout << "Gib Tankvolumen ein: ";
						dTankvolumen = liesZahl<double>(ZahlenParameter::NurPositiv);
					} else {
						dTankvolumen = 55;
					}
				}

				vSchaffeObjekt();


			break;
		case 0: //ERSTELLEN ABBRECHEN
			PROGRAMM_STATUS = ProgrammStatus::Simulationsvorbereitung;
		}

	} while(PROGRAMM_STATUS == ProgrammStatus::Erstellen);

	Programm::Simulationsvorbereitung();
}

void Programm::Simulationsvorbereitung() { //Programmstatus wird bereits in Erstellen aktualisiert
	cout << "Wähle dein Simulationstakt aus: ";
	dTaktRate = liesZahl<double>(ZahlenParameter::NurPositiv);

	PROGRAMM_STATUS = ProgrammStatus::Simulation;
	Programm::Simulation();
}

using namespace std; //da hier oft benutzt

void Programm::Simulation() {
	bool bFortführen;

	while (PROGRAMM_STATUS == ProgrammStatus::Simulation) {
		PROGRAMM_STATUS = ProgrammStatus::Simulation;

		vErhöheGlobalTakt();

		//Überschrift
		if (AktiveFahrzeuge.size() >= 1) {
			Fahrzeug::vKopf();
		} else { //Keine Fahrzeuge die simuliert werden können
			std::cerr << "Keine Fahrzeuge zum simulieren!" << std::endl;
			Programm::Kill();
		}


		//Ausgeben der Daten

		for (const auto& ptr : AktiveFahrzeuge) {
			(*ptr).vSimulieren();
			cout << *ptr; //Gibt Werte durch überladenen Operator aus
			cout << endl;
		}

		//Tanken?
		Programm::Tanken();

		//Weitermachen?
		cout 	<< "Simulation fortführen?" << endl
				<< "├ [J] Ja" << endl
				<< "└ [N] Nein, Simulation beenden" << endl;
		if ( (bFortführen = bVerwalteJN()) ) {
			//Ja, fortführen
			continue;
		} else {
			return;
		}

	};
}

void Programm::Tanken() {
	cout 	<< "Möchtest du Fahrzeuge auftanken?" << endl
					<< "├ [J] Ja" << endl
					<< "└ [N] Nein" << endl;
			if ( (bNachtanken = bVerwalteJN()) ) {
				//Nachtanken
				cout << "Gib die ID des Fahrzeugs ein, das du auftanken möchtest:";
				iID = liesZahl<int>(ZahlenParameter::PositivUndNull);
				cout << "Wie viel Liter willst du Tanken (0 = Auftanken)?";
				dTankMenge = liesZahl<double>(ZahlenParameter::PositivUndNull); //Null ist auftanken

				try {
					dGetankteMenge = AktiveFahrzeuge.at(iID - (Fahrzeug::getMaxID() - AktiveFahrzeuge.size()))->dTanken(dTankMenge); //Korrektur falls Objekte erstellt, die nicht in AktiveFahrzeuge gespeichert wurden
					cout << "Es wurden " << dGetankteMenge << "l getankt." << endl;
				} catch (const std::out_of_range& error) {
					std::cerr << "Es existiert kein Element unter dieser Adresse!" << std::endl;
					return Programm::Tanken();
				} catch(...) {
					std::cerr << "Unbekannter Fehler. Programm wird beendet" << std::endl;
					Programm::Kill();
				}

				//Erneut Fragen, ob weiteres Fahrzeug
				return Programm::Tanken();
			}
}

void Programm::Kill() {
	PROGRAMM_STATUS = ProgrammStatus::Killed;
	cout << "Programm wurde erfolgreich beendet." << endl;
	std::exit(EXIT_SUCCESS);
}















