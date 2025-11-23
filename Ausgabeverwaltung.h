//Include Guard
#ifndef AUSGABEVERWALTUNG_H_
#define AUSGABEVERWALTUNG_H_

#include <iostream>

#include "Fahrzeug.h"

//Operator << überladen, sodass wir Fahrzeuge mit cout << *aPKW ... ausgeben können
std::ostream& operator<<(std::ostream& ostream, const Fahrzeug& fahrzeug);


#endif
