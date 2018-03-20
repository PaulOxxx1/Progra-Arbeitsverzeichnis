#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

class node {
  int v;  // Name/Wert des Knotens
  node *l, *r;  // Zeiger auf Kinderknoten
public:
  // Konstruktor
  node(int v): l(0), r(0), v(v) {}  // zu Beginn hat ein Knoten keine Kinder, also setze die Pointer auf 0
  // (rekursiver) Destruktor
  ~node() { delete l; delete r; } // rufe einfach Destruktor der beiden Kinderknoten auf, falls diese nicht existieren, passiert bei "delete" nichts
  // Zugriffsroutinen für alle Daten (Lesen und Schreiben)
  int& vaccess() { return v; }
  node*& laccess() { return l; }
  node*& raccess() { return r; }
  // (rekursive) Summe
  int sum() {
    int sum = 0;
    if (l) sum += l->sum(); // Summe aller linken Kinder addieren (falls vorhanden)
    if (r) sum += r->sum(); // Summe aller rechten Kinder addieren (falls vorhanden)
    sum += v; // eigenen Wert addieren
    return sum;
  }
  // (rekursive) Ausgabe
  void print() {
    if (l) l->print();  // linke/kleinere Kinder ausgeben
    cout << v << " "; // sich selbst ausgeben
    if (r) r->print();  // rechte/größere Kinder ausgeben
  }
};

class BinTree {
  node* root; // Zeiger auf Wurzelknoten
  unsigned int s; // Anzahl Knoten im Baum
public:
  // Konstruktor
  BinTree(): root(0), s(0) {} // zu Beginn hat ein Baum keine Knoten, nicht mal eine Wurzel
  // Destruktor
  ~BinTree() { delete root; } // starte Deallokation der Knoten mit der Wurzel
  // Summe der Knoten
  int sum() {
    if (root) return root->sum(); // starte Addition der Knoten mit der Wurzel
    else return 0; // es gibt noch gar keine Knoten
  }
  // geordnetes Hinzufügen eines Knotens
  void add(int v) {
    if (!root) root=new node(v); // es gibt noch gar keine Knoten
    else {
      node* p = root; // Hilfspointer
      while (true) {
        if (p->vaccess() < v) { // Wert ist größer als aktueller Knoten
          if (p->raccess()) p=p->raccess(); // es gibt ein rechtes/größeres Kind, also verschiede Pointer 
          else { p->raccess()=new node(v); break; } // es gibt kein rechtes/größeres Kind, also erstelle hier neuen Knoten
        } else {  // Wert ist kleiner als aktueller Knoten
          if (p->laccess()) p=p->laccess(); // es gibt ein linkes/kleineres Kind, also verschiede Pointer 
          else { p->laccess()=new node(v); break; } // es gibt kein linkes/kleineres Kind, also erstelle hier neuen Knoten
        }
      }
    }
    s++;  // Anzahl der Knoten erhöhen
  }
  // Ausgabe
  void print() { if (root) root -> print(); } // starte Ausgabe der Knoten mit der Wurzel
  // Zugriffsroutinen (Lesen)
  int size() { return s; }
};

int main(int argc, char* argv[]) {
  assert(argc==2);
  BinTree tree;
  ifstream in(argv[1]);
  int s, v;
  in >> s;
  for (int i=0;i<s;i++) {
    in >> v;
    tree.add(v);
    cout << tree.size() << ": ";
    tree.print();
    cout << endl;
  }
  cout << tree.sum() << endl;
}