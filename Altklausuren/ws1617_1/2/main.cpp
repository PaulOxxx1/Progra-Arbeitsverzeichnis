#include <cassert>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class land_t {
  bool besucht;
  unsigned int i;
  land_t* v;
  struct nachbar_t {
    land_t* n;
    nachbar_t* v;
    nachbar_t(): n(0), v(0) {}
  } *nachbarn;
public:
  land_t(int i): i(i), besucht(false), v(0), nachbarn(0) {}
  
  void neuer_nachbar(land_t* nb) {
    if (nachbarn == 0) {
      nachbarn = new nachbar_t();
      nachbarn->n = nb;
    } else {
      nachbar_t* p = new nachbar_t();
      p->n = nb;
      p->v = nachbarn;
      nachbarn = p;
    }
  }
  
  void ausgabe() {
    cout << i << " ( ";
    nachbar_t* n = nachbarn;
    while (n!=0) { cout << n->n->i << " "; n=n->v; }
    cout << ")" << endl;
  }
  
  bool erreichbar(land_t* b) {
    if (b==this and besucht==false) {
      cout << i << " ";
      return true;
    } else {
      if (besucht) {
        return false;
      } else {
        besucht = true;
        bool result = false;
        nachbar_t* p = nachbarn;
        while (p) {
          result = p->n->erreichbar(b);
          if (result) break;
          p = p->v;
        }
        cout << i << " ";
        return result;
      }
    }
  }
  
  friend class landkarte_t;
};

class landkarte_t {
  land_t* laender;
public:
  land_t* finde_land(int id) {
    land_t* p = laender;
    while (p->i!=id and p!=0) {
      p = p->v;
    }
    assert(p!=0);
    return p;
  }
  
  landkarte_t(ifstream& in) {
    int n=0; int id=0;
    in >> n; in >> id; n--;
    laender = new land_t(id);
    for (int i=0;i<n;i++) {
      in >> id;
      land_t* p = new land_t(id);
      p->v = laender;
      laender = p;
    }
    in >> n;
    for (int i=0;i<n;i++) {
      int a,b;
      in >> a;
      in >> b;
      finde_land(a)->neuer_nachbar(finde_land(b));
      finde_land(b)->neuer_nachbar(finde_land(a));
    }
  }
  
  ~landkarte_t() {
    land_t* p = laender;
    while (p) {
      p = p->v;
      delete laender;
      laender = p;
    }
  }
  
  bool erreichbar(land_t* a, land_t* b) {
    cout << "Erreichbar " << a->i;
    cout << "->" << b->i << "? ";
    bool e = a->erreichbar(b);
    if (e) {
      cout << "JA" << endl;
    } else {
      cout << "NEIN" << endl;
    }
    land_t* p = laender;
    while (p) {
      p->besucht = false;
      p = p->v;
    }
    return e;
  }
  
  void ausgabe() {
    land_t* l=laender;
    while (l!=0) { l->ausgabe(); l=l->v; }
  }
};

int main(int c, char* v[]) {
  assert(c==2);
  ifstream in(v[1]);
  landkarte_t l(in);
  l.ausgabe();
  l.erreichbar(l.finde_land(0),l.finde_land(6));
  l.erreichbar(l.finde_land(0),l.finde_land(0));
  l.erreichbar(l.finde_land(5),l.finde_land(7));
  in.close();
  return 0;
}