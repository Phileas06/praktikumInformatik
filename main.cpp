#include <iostream>
#include <memory>

#include "Fahrzeug.h" //niemals cpp datei hier importieren

auto vAufgabe_1() {
	Fahrzeug Zug("ICE");
	auto BMW = std::make_shared<Fahrzeug>("BMW");


	std::shared_ptr<Fahrzeug> geliehenerBMW = BMW;
	Fahrzeug BUS;
	Fahrzeug Skateboard;
	Fahrzeug* Porsche911 = new Fahrzeug("Porsche911"); // erstellt objekt und speichert auf heap


	delete Porsche911;
	BMW.reset(); //resettet referenzzähler auf 1
	geliehenerBMW.reset(); //setzt referenzzähler auf 0 => wird gelöscht

	auto FerrariPtr = std::make_unique<Fahrzeug>("Ferrari");
	auto BugattiChiron = std::make_unique<Fahrzeug>("Bugatti Chiron");

	//Shared Pointer
	auto Tesla = std::make_shared<Fahrzeug>("Tesla");

}


int main () {


	vAufgabe_1();
	return 0;
}
