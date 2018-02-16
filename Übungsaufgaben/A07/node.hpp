#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// Knoten eines gerichteten Graphen

class node {

  string label;         // Name des Knotens
  vector<node*> succ;   // Nachfolger
	vector<float> prob;   // Wahrscheinlichkeiten
  int visits;           // Anzahl Besuche

public:

  // Konstruktoren
  /// Konstruiert einen Knoten mit einem gegebenen Namen
  node(string label);

  // Destruktoren
  /// Destruiert einen Knoten und gibt dessen Namen und die Anzahl der Besuche aus
  ~node();

  // Funktionen mit Rueckgabewerten
  string readLabel();
  node* successor(int i);
  float probability(int i);

  // Funktionen
  /// Fuegt eine Kante zu einem anderen Knoten mit einer gegebenen Wahrscheinlichkeit hinzu
  void addEdgeTo(node* destination, float probability);
  /// Sollte aufgerufen werden, wenn Knoten besucht wird
  void visit();
};
