#include <iostream>
#include <memory>
#include <vector>

#include "Fahrzeug.h" //niemals cpp datei hier importieren

auto testToCheckUniquePointer(std::unique_ptr<Fahrzeug> ptr) {
	std::cout << "Funktionswechsel hat geklappt!" << ptr->getName() << std::endl;
	return ptr;
}

enum class Programm {
	isKilled,
	isRunning,
	isSimulating,
	status = Programm::isRunning
};


void vAufgabe_1a() {
	char input;
	std::string name;
	double maxVelocity;
	while(Programm::status == Programm::isRunning) {
		std::cout << "Möchtest du ein weiteres Fahrzeug erstellen?" << std::endl << "[J] Ja" << std::endl << "[N] Nein" << std::endl;
		std::cin >> input; //debug, was wenn zahl, wenn string
		switch (input) {
			case 'n':
				std::cout << "Straßennetz wird simuliert..." << std::endl; // << "Zum Abbrechen [X] drücken" << std::endl; //wie handle ich programm abbruch?
				Programm::status = Programm::isSimulating;

				break;
			case 'j':
				std::cout << "Gib den Namen des Fahrzeuges ein: " << std::endl;
				std::cin >> name;
				std::cout << "Gib die maximale Geschwindigkeit des Fahrzeugs ein:" << std::endl;
				std::cin >> maxVelocity;
				break;
			default: continue;
		}
	}
}

auto vAufgabe_1() {
	Fahrzeug Zug("ICE");
	auto BMW = std::make_shared<Fahrzeug>("BMW");


	std::shared_ptr<Fahrzeug> geliehenerBMW = BMW;
	Fahrzeug BUS;
	Fahrzeug Skateboard;
	Fahrzeug* Porsche911 = new Fahrzeug("Porsche911"); // erstellt objekt und speichert auf heap





	//std::cout << BMW.use_count() << endl; // gibt 2 aus
	//BMW.reset(); //resettet referenzzähler auf 1
	//std::cout << BMW.use_count() << endl; //gibt null aus weil auf nullptr und nullptr hat kein referenzzähler
	//geliehenerBMW.reset();
	//geliehenerBMW.reset(); //setzt referenzzähler auf 0 => wird gelöscht

	auto FerrariPtr = std::make_unique<Fahrzeug>("Ferrari");
	auto BugattiChiron = std::make_unique<Fahrzeug>("Bugatti Chiron");

	FerrariPtr = testToCheckUniquePointer(std::move(FerrariPtr));

	std::cout << "Test" << FerrariPtr->getName() << std::endl;

	//Shared Pointer
	auto Tesla = std::make_shared<Fahrzeug>("Tesla");


	//vektor erzeugen mit den elementen der unique pointer
	std::vector<std::unique_ptr<Fahrzeug>> v_upFahrzeuge;

	v_upFahrzeuge.push_back(std::move(FerrariPtr)); //kopie wird erstellt! nicht möglich! Daher move
	v_upFahrzeuge.push_back(std::move(BugattiChiron));

	//shared pointer vector

	std::vector<std::shared_ptr<Fahrzeug>> v_spFahrzeuge;

	v_spFahrzeuge.push_back(Tesla);
	v_spFahrzeuge.push_back(BMW);
	v_spFahrzeuge.push_back(geliehenerBMW);; //keine extra kopie muss gemacht werden
	v_spFahrzeuge.push_back(std::move(v_upFahrzeuge.at(0)));
	std::cout << "Anzahl der Referenzen von BMW:::" << BMW.use_count() << std::endl;

	/*
	for (std::vector<shared_ptr<Fahrzeug>>::iterator it = v_spFahrzeuge.begin(); it != v_spFahrzeuge.end(); ++it) {
		std::cout << (*it ? (*it)->getName() : "Nicht gefunden") << endl;
	}
	*/

	Fahrzeug McLaren("McLaren", 350);
	Fahrzeug* Mercedes = new Fahrzeug("Mercedes", 150);
	auto RollsRoyce = std::make_unique<Fahrzeug>("RollsRoyce", 120);
	auto OpelCorsa = std::make_shared<Fahrzeug>("Opel Corsa", 30);

	v_spFahrzeuge.push_back(std::move(OpelCorsa));
	v_spFahrzeuge.push_back(std::move(RollsRoyce));
	v_spFahrzeuge.push_back(std::make_unique<Fahrzeug>(McLaren));

	for (std::vector<std::shared_ptr<Fahrzeug>>::iterator it = v_spFahrzeuge.begin(); it != v_spFahrzeuge.end(); ++it) {
		std::cout << "Maximalgeschwindidkeit: " << (*it)->getMaxVelocity() << std::endl;
	}



	Fahrzeug::vKopf();
	Porsche911->vAusgeben();
	std::cout << std::endl;
	McLaren.vAusgeben();
	std::cout << std::endl;

	delete Mercedes;
	delete Porsche911;
}


int main () {


	vAufgabe_1();
	return 0;
}
