#include <vector>
#include <memory>

#include "AktiveFahrzeuge.h"
#include "Fahrzeug.h"

std::vector<std::unique_ptr<Fahrzeug>> AktiveFahrzeuge = {}; //muss hier definiert werden, wegen extern


