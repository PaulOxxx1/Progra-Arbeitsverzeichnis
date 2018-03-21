#include<cassert>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;


class list_element{
  int v;
  list_element *p, *n;

public:
  // Konstruktor
  list_element(int v) : v(v), p(0), n(0) {}
  // Zugriffsroutinen
  list_element*& p_access() { return p; }
  list_element*& n_access() { return n; }
  // Ausgabe vorwärts (rekursiv)
  void print_forwards(){
    cout << v << " ";
    if (n) {
      n->print_forwards();
    }
  }
  // Ausgabe rückwärts (rekursiv)
  void print_backwards(){
    cout << v << " ";
    if (p) {
      p->print_backwards();
    }
  }
};


class history{
  unsigned int s, max_s;
  list_element *f, *l;

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
  // Listenelement
  void add_list_element(list_element *e){
    if (s) {
      l->n_access() = e;
      e->p_access() = l;
      l = e;
    } else {
      f = e;
      l = e;
    }
    s++;
    if (s>max_s){
      f = f->n_access();
      delete f->p_access();
      f->p_access() = 0;
      s--;
    }
  }
  // Ausgabe vorwärts (rekursiv)
  void print_forwards() {
    if (s) {
      f->print_forwards();
      cout << endl;
    }
  }
  // Ausgabe rückwärts (rekursiv)
  void print_backwards() {
    if (s) {
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
