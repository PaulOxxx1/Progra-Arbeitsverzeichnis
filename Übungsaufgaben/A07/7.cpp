#include <iostream>
#include <cstdlib>
#include "graph.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	if (argc > 1) {		// Anzahl der Schritte uebergeben
		graph g;				// Graph konstruieren
		g.traversal(g.firstNode(),atoi(argv[1]));	// Graph durchqueren
		cout << endl << endl;		// Leerzeilen als Platzhalter
	}

	// Keine Zahl uebergeben
	else {
		cout << "Call with number of steps for traversal.\n";
	}

	return 0;
}
