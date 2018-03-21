#include<cassert>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;


class list_element {
  int v;  // Zahl
  list_element *p, *n;  // Vorgänger/Nachfolger

public:
  // Konstruktor
  list_element(int v) : v(v), p(0), n(0) {}
  // Zugriffsroutinen (Lesen & Schreiben)
  list_element*& p_access() { return p; }
  list_element*& n_access() { return n; }
  // Ausgabe vorwärts (rekursiv)
  void print_forwards() {
    cout << v << " "; // gib mich selbst aus
    if (n) n->print_forwards(); // sage meinem Nachfolger, er soll sich ausgeben, falls es einen gibt
  }
  // Ausgabe rückwärts (rekursiv)
  void print_backwards() {
    cout << v << " "; // gib mich selbst aus
    if (p) p->print_backwards(); // sage meinem Vorgänger, er soll sich ausgeben, falls es einen gibt
  }
};


class history{
  unsigned int s, max_s;  // aktuelle und maximale Länge
  list_element *f, *l;  // erstes und letztes Element

public:
  // Konstruktor
  history(int max_s) : max_s(max_s), s(0), f(0), l(0) {}
  // Destruktor
  ~history() {
    if (s) {
      while (f->n_access()) {
        f = f->n_access();
        delete f->p_access();
      }
      delete f;
    }
  }
  // Element hinzufügen
  void add_list_element(list_element *e) {
    if (max_s) {  // nur hinzufügen, falls Liste überhaupt Elemente haben darf
      if (s) {  // es gibt schon Elemente, also hänge e hinten dran
        l->n_access() = e;
        e->p_access() = l;
        l = e;
      } else {  // es gibt noch keine Elemente, e ist das erste und letzte Element
        f = e;
        l = e;
      }
      s++;  // Counter erhöhen
      if (s>max_s){ // Liste ist zu lang, also schneide erstes Element ab 
        f = f->n_access();
        delete f->p_access();
        f->p_access() = 0;
        s--;
      }
    }
  }
  // Ausgabe vorwärts (rekursiv)
  void print_forwards() {
    if (s) {  // gebe nur Listen aus, die nicht leer sind
      f->print_forwards();
      cout << endl;
    }
  }
  // Ausgabe rückwärts (rekursiv)
  void print_backwards() {
    if (s) {  // gebe nur Listen aus, die nicht leer sind
      l->print_backwards();
      cout << endl;
    }
  }
};


int main (int c, char *v[]){
  assert (c==3);
  ifstream in(v[1]);
  int l; in >> l;
  int m=atoi(v[2]);
  history h(m);
  for (int i=0;i<l;i++) {
    int j; in >> j;
    h.add_list_element(new list_element(j));
    h.print_forwards();
    h.print_backwards();
  }
  return 0;
}
