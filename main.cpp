#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Programm.h"
#include "Ausgabeverwaltung.h"
#include "AktiveFahrzeuge.h"
#include "Zeit.h"

void vAufgabe_1() {
	Fahrzeug Zug("ICE");
	auto BMW = std::make_shared<Fahrzeug>("BMW");

	BMW.use_count();
	auto geliehenerBMW = BMW;
	BMW.use_count();

	Fahrzeug BUS;
	Fahrzeug* Porsche911 = new Fahrzeug("Porsche911"); // erstellt objekt und speichert auf heap
	delete Porsche911;

	auto FerrariPtr = std::make_unique<Fahrzeug>("Ferrari");
	auto BugattiChiron = std::make_unique<Fahrzeug>("Bugatti Chiron");

	//Shared Pointer
	auto Tesla = std::make_shared<Fahrzeug>("Tesla");


	//vektor erzeugen mit den elementen der unique pointer
	std::vector<std::unique_ptr<Fahrzeug>> UniqueFahrzeuge;

	UniqueFahrzeuge.push_back(std::move(FerrariPtr)); //Move, sonst wird probiert, Kopie zu erstellen
	UniqueFahrzeuge.push_back(std::move(BugattiChiron));

	UniqueFahrzeuge.clear();

	std::vector<std::shared_ptr<Fahrzeug>> SharedFahrzeuge;
	SharedFahrzeuge.push_back(BMW);
	SharedFahrzeuge.push_back(std::move(FerrariPtr));


}

void vAufgabe_1a() {
	Programm::Startup();
}

void vAufgabe_2() {

	vSetTimePoint(3); // hier true, um 3 Stunden bis Tankfüllung zu signalisieren
	Programm::Startup();

	//Logik für Tanken nach 3h in Globaler Uhr


	//Noch implementieren
}

void vAufgabe_3() { //ACHTUNG:: MANUELLES ERSTELLEN VON FAHRZEUGEN OHNE HINZUFÜGEN ZU AKTIVEFAHRZEUGE => FEHLER (bspw. ID Tanken wird verschoben
	Fahrzeug ZUG("ICE", 130);
	PKW Audi("Audi", 130, 8.4, 80);

	PKW FakeAudi("FakeAudi", 90, 9.5, 40);

	auto BMW = std::make_unique<PKW>("BMW", 131, 4.2, 100);
	auto Mountainbike = std::make_unique<Fahrrad>("Mountainbike", 25);

	AktiveFahrzeuge.push_back(std::move(BMW));
	AktiveFahrzeuge.push_back(std::move(Mountainbike));


	Fahrzeug::vKopf();
	std::cout << ZUG << std::endl;
	std::cout << Audi << std::endl;
	std::cout << *AktiveFahrzeuge[0] << std::endl;
	std::cout << *AktiveFahrzeuge[1] << std::endl;

	Programm::Simulationsvorbereitung();

	std::cout << ((ZUG < Audi) ? "Zug hat weniger Strecke zurueckgelegt, als der Audi" : "Zug hat mehr Strecke zurueckgelegt als der Audi") << std::endl;

	std::cout << FakeAudi << std::endl;

	FakeAudi = Audi;

	std::cout << FakeAudi << std::endl;
}

using namespace std;
extern double dGlobaleZeit;
double dEpsilon = 0.001;

void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{13};
    double dTakt = 0.4;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 231, 11.4));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 19.8));
    for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken(0);
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}

int main() {
	std::cout << std::fixed;
	std::cout.precision(2);

	//vAufgabe_1();
	//vAufgabe_1a(); //Normales Programm
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_Probe();

	vAufgabe_AB1();

	Programm::Kill();
	return 0;
}
