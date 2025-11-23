//Include Guard
#ifndef EINGABEVERWALTUNG_H_
#define EINGABEVERWALTUNG_H_

#include <limits>
#include <cmath>

enum class ZahlenParameter
{
    NurPositiv,
    NurNegativ,
    Alles,
    PositivUndNull,
    NegativUndNull
};

enum class StringParameter {
	NurWort,
	Woerter
};

//LiesZahl muss wegen template in header Datei definiert werden:
template <typename Rueckgabetyp>
Rueckgabetyp liesZahl(ZahlenParameter parameter) {
	Rueckgabetyp value = 0; //Garbage Value verhindern
	    std::cin >> value;

	    // Fehler suche:
	    if (!std::cin.fail()) //ERFOLG
	    {
	    	if (std::abs(value) > 1000) {
	    		std::cerr << "Fehler: Maximaler Wert: 1000" << std::endl;
	    		return liesZahl<Rueckgabetyp>(parameter);
	    	}

	        switch (parameter)
	        {
	        case ZahlenParameter::NurPositiv:
	            if (value > 0)
	            { // NUMBER
	                return value;
	            }
	            else
	            {
	                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
	                return liesZahl<Rueckgabetyp>(parameter);
	            }
	            break;
	        case ZahlenParameter::NurNegativ:
	            if (value < 0)
	            { // NUMBER
	                return value;
	            }
	            else
	            {
	                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
	                return liesZahl<Rueckgabetyp>(parameter);
	            };
	            break;
	        case ZahlenParameter::Alles:
	            return value;
	            break;
	        case ZahlenParameter::NegativUndNull:
	            if (value <= 0)
	            { // NUMBER
	                return value;
	            }
	            else
	            {
	                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
	                return liesZahl<Rueckgabetyp>(parameter);
	            }
	            break;
	        case ZahlenParameter::PositivUndNull:
	            if (value >= 0)
	            { // NUMBER
	                return value;
	            }
	            else
	            {
	                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
	                return liesZahl<Rueckgabetyp>(parameter);
	            }
	            break;
	        default:
	            std::cout << "Fehler bei der Eingabe: Ungültiger ZahlenParameter" << std::endl;
	            return 0;
	        }
	    }
	    else // Fehler
	    {


	        std::cin.clear(); // setzt Fehlerflags zurück (auch wenn keine gesetzt wurden)
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // max größe des stream bis zum zeichen \n
	        std::cerr << "Fehler bei der Eingabe" << std::endl;
	        return liesZahl<Rueckgabetyp>(parameter);
	    }
}

std::string sLiesString(StringParameter parameter);

char cLiesChar();

bool bVerwalteJN();

#endif
