#include "graph.hpp"

// Konstruktoren
graph::graph() {
  srand(time(NULL));

  nodes = new node*[10];

  nodes[0] = new node("\n");
  nodes[1] = new node("Affen ");
  nodes[2] = new node("Fische ");
  nodes[3] = new node("faulenzen ");
  nodes[4] = new node("fischen ");
  nodes[5] = new node("lieben ");
  nodes[6] = new node("Bananen ");
  nodes[7] = new node("Fische ");
  nodes[8] = new node("Wasser ");
  nodes[9] = new node("Sonne ");

  nodes[0]->addEdgeTo(nodes[1], 0.5);
  nodes[0]->addEdgeTo(nodes[2], 0.5);
  nodes[1]->addEdgeTo(nodes[3], 0.3);
  nodes[1]->addEdgeTo(nodes[4], 0.3);
  nodes[1]->addEdgeTo(nodes[5], 0.4);
  nodes[2]->addEdgeTo(nodes[4], 0.5);
  nodes[2]->addEdgeTo(nodes[5], 0.5);
  nodes[3]->addEdgeTo(nodes[0], 1.0);
  nodes[4]->addEdgeTo(nodes[6], 0.5);
  nodes[4]->addEdgeTo(nodes[7], 0.5);
  nodes[5]->addEdgeTo(nodes[6], 0.25);
  nodes[5]->addEdgeTo(nodes[7], 0.25);
  nodes[5]->addEdgeTo(nodes[8], 0.25);
  nodes[5]->addEdgeTo(nodes[9], 0.25);
  nodes[6]->addEdgeTo(nodes[0], 1.0);
  nodes[7]->addEdgeTo(nodes[0], 1.0);
  nodes[8]->addEdgeTo(nodes[0], 1.0);
  nodes[9]->addEdgeTo(nodes[0], 1.0);
}

// Destruktoren
graph::~graph() {
  for (int i=0; i<10; i++) {
    delete nodes[i];
  }
  delete [] nodes;
}

// Funktionen mit Rueckgabewerten
node* graph::firstNode() {return nodes[0];}

// Funktionen
/** Die Funktion durchquert den Graphen ab dem gegebenen Anfangsknoten `current` und
 * fuer eine bestimmte Anzahl an Schritten, `steps`.
 *
 * Bei jedem Besuch eines Knotens wird dessen Name ausgegeben und dessen Zaehler inkrementiert. Danach wird
 * ein zufaelliger Nachfolgeknoten ausgewaehlt, wobei die Kantengewichte zu den Knoten bestimmen, mit welcher
 * Wahrscheinlichkeit der entsprechende Pfad verwendet wird.
 *
 * Fuer `steps=0` wird trotzdem der gegebene Startknoten besucht.
 */
void graph::traversal(node* current, int steps) {
  cout << current->readLabel();   // Ausgabe des Knotens

  current->visit();               // Zaehler inkrementieren

  // Naechsten Knoten auswaehlen
  float zufall = static_cast<double>(rand())/RAND_MAX;
  int i=-1;
  while (zufall>=0) {
    zufall -= current->probability(++i);
  }

  // Sprung zum naechsten Knoten
  if (steps > 0) traversal(current->successor(i), --steps);
}
