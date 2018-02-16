#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <mpi.h>

using namespace std;

int measure_roundtrip(const vector<int> & vertices, const vector<pair<pair<int,int>,short> > & edges) {
  vector<int>::const_iterator vert_iter, vert_iter_prev;
  vector<pair<pair<int,int>,short> >::const_iterator edge_iter;
  
  int roundtrip_length = 0;
  vert_iter = vertices.begin();
  vert_iter_prev = vert_iter;
  vert_iter++;
  
  for (; vert_iter != vertices.end(); vert_iter++) {
    for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++) {
      if (((*edge_iter).first.first == *vert_iter_prev && (*edge_iter).first.second == *vert_iter) || 
          ((*edge_iter).first.second == *vert_iter_prev && (*edge_iter).first.first == *vert_iter)) {
        roundtrip_length += (*edge_iter).second;
      }
    }
    
    vert_iter_prev = vert_iter;
  }
  
  return roundtrip_length;
}

int main(int argc, char const *argv[]) {
  const int n = 5;  // Anzahl Städte
  vector<int> vertices; // Vektor aus Städten
  vector<pair<pair<int,int>,short> > edges; // Vektor aus Verbindungen zwischen Städten (Straßen)
  vector<int>::const_iterator iter, iter2;  // Iteratoren
  
  // Hinzufügen aller Städte
  for (int i=0;i<n;i++) {
    vertices.push_back(i);
  }
  
  srand(0); // Zufall
  // Durch alle Städte iterieren und alle untereinander verbinden
  for (iter = vertices.begin(); iter != vertices.end(); iter++) {
    iter2 = iter;   // Aktuelle Stadt zwischenspeichern
    iter2++;    // zur nächsten Stadt springen
    // alle weiteren Städte durchgehen
    for (; iter2 != vertices.end(); iter2++) {
      pair<int,int> p = make_pair(*iter, *iter2); // Städtepaar erstellen
      short d = floor((double)rand() / RAND_MAX * 1000);  // zufällige Distanz zwischen Städten würfeln
      
      pair<pair<int,int>,short> e = make_pair(p,d); // Verbindung aus Städtepaar und Distanz erstellen
      edges.push_back(e); // Verbindung speichern
      
      // Ausgabe der neuen Verbindung
      cout << *iter << " / " << *iter2 << " / " << d << endl;
    }
  }
  
  
  int shortest_roundtrip = 9999999; // Variable für kürzesten Weg zwischen allen Städten erstellen
  int roundtrip_length = measure_roundtrip(vertices,edges);
  cout << roundtrip_length << endl;
  
  /*while (next_permutation(vertices.begin(), vertices.end())) {
    if 
  }*/
  
  return 0;
}