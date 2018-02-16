#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "node.cpp"
using namespace std;

/// Spezifischer gerichteter Graph G = (V, E) mit 10 Knoten.
/**
 * V = {0,1,2,3,4,5,6,7,8,9}
 *
 * E = {{0,1},{0,2},{1,3},{1,4},{1,5},{2,4},{2,5},{3,0},{4,6},{4,7},{5,6},{5,7},{5,8},{5,9},{6,0},{7,0},{8,0},{9,0}}
 *
 * Der Graph kann durchquert werden.
 */

class graph {

  node** nodes;   // Alle Knoten des Graphen

public:

  // Konstruktoren
  graph();

  // Destruktoren
  ~graph();

  // Funktionen mit Rueckgabewerten
  node* firstNode();

  // Funktionen
  /// Durchquert den Graphen
  void traversal(node* current, int steps);
};
