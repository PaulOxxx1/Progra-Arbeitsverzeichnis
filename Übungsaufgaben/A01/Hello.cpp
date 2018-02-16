#include<iostream> // Kapitel iostream der Standardbibliothek einbinden
using namespace std; // Einbindung des Namensbereichs std

int main() {  // Start der main Funktion
  string Name; // Deklaration der String Variable für den Namen
  cout << "Name? "; // Frage den Nutzer nach dem Namen
  cin >> Name; // Eingabe des Namens
  cout << "Hallo " << Name << ", willkommen zur Einfuehrung in die Programmierung!" << endl;  //  Ausgabe eines Strings
  return 0;  // Rückgabewert von 0
} // Ende der main Funktione
