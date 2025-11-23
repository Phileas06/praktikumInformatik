#include <iostream>
#include <limits>
#include <cctype>

#include "Eingabeverwaltung.h"

//LIES ZAHLEN


//LIES STRINGS
std::string sLiesString(StringParameter parameter)
{
    std::string sEingabe = "";
    std::getline(std::cin, sEingabe);

    if (!std::cin.fail())
    { // ERFOLG
        if (!sEingabe.empty())
        {
            switch (parameter)
            {
            case StringParameter::Woerter: // alles erlaubt ausser Zahlen am Anfang
                if (!isdigit(sEingabe[0]))
                { // ERFOLG
                    return sEingabe;
                }
                else
                {
                    std::cerr << "Erstes Wort darf nicht mit Zahl beginnen!" << std::endl;
                    return sLiesString(parameter);
                }
                break;
            case StringParameter::NurWort: // Nur Buchstaben und Zahlen erlaubt => Kein Leerzeichen

                // Überprüfung ob Mehrere Wörter (Leerzeichen vorhanden)
                for (int i = 0; i < (int) sEingabe.length(); ++i)
                {
                    if (sEingabe[i] == ' ' && i != (int) sEingabe.length() - 1) // Letzter Buchstabe darf Leerzeichen enthalten
                    {
                        std::cerr << "Nur ein Wort erlaubt!" << std::endl;
                        return sLiesString(parameter);
                    }
                };

                // Erster Charakter Zahl?
                if (!isdigit(sEingabe[0]))
                {
                    return sEingabe;
                }
                else
                {
                    std::cerr << "Eingabe darf nicht mit Zahl beginnen!" << std::endl;
                    return sLiesString(parameter);
                }
                break;
            default:
                throw std::runtime_error("Fehler beim Übergeben des Operators! sLiesString() braucht operator als Argument!");
            }
        } else {
        	std::cerr << "Leere Eingabe nicht erlaubt" << std::endl;
        	return sLiesString(parameter);
        }
    }
    else
    {
    	std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Falsche Eingabe!" << std::endl;
        return sLiesString(parameter);
    }


};

//LIES CHAR
char cLiesChar()
{
    char cEingabe = ' ';
    std::cin >> cEingabe;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Überreste im puffer bereinigen

    if (!std::cin.fail()) // Keine Konvertierungsfehler bei Char => nur eof kann Fehler auslösen
    {
        if (isalpha(cEingabe)) // Prüft ob Buchstabe
        {
            // ERFOLG
            return tolower(cEingabe);
        }
        std::cerr << "Nur Buchstaben!" << std::endl;
        return cLiesChar();
    }
    else
    {
        std::cin.clear();
        std::cerr << "Fehler bei der Ausgabe" << std::endl;
        return cLiesChar();
    }
}

bool bVerwalteJN() {
	int cInputChar;
	do {
		cInputChar = cLiesChar();
		switch (cInputChar) {
		case 'j':
			return true;
			break;
		case 'n':
			return false;
			break;
		default:
			std::cerr << "Fehler bei der Eingabe!" << std::endl;
			continue;
		}

	} while (true);
}


