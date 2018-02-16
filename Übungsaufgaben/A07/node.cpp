#include "node.hpp"

// Konstruktoren
node::node(string _label): label(_label), visits(0) {}

// Destruktoren
node::~node() {
  cout << "Deallocating \"" << label << "\"." << endl << "Visits: " << visits << endl;
}

// Funktionen mit Rueckgabewerten
string node::readLabel() {return label;}
node* node::successor(int i) {return succ[i];}
float node::probability(int i) {return prob[i];}

// Funktionen
void node::addEdgeTo(node* destination, float probability) {
  succ.push_back(destination);
  prob.push_back(probability);
}
void node::visit() {visits++;}
