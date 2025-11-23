//Include Guard
#ifndef PROGRAMM_H_
#define PROGRAMM_H_

enum class ProgrammStatus {
	Startup,
	Erstellen,
	Simulationsvorbereitung,
	Simulation, //Tanken ist zugehörig zu Simulation => kein eigener Programmstatus
	Killed
};

namespace Programm {
	void Startup();
	void Erstellen();
	void Simulationsvorbereitung();
	void Simulation();
	void Tanken();
	void Kill();
}

void vSchaffeObjekt();

extern ProgrammStatus PROGRAMM_STATUS;

#endif
