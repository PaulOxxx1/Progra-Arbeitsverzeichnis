#include<cstdlib>
#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<cfloat>

using namespace std;

// Die Klasse logger sorgt lediglich dafür, dass ein Wert v ausgegeben wird
class logger {
protected:
  logger(double v) { cout << "logger=" << v << endl; } 
};

class fd : public logger {
  double v, vs;
public:
  // Konstruktoren (Hier muss auch logger initialisiert werden! Mit dem Wert, der ausgegeben werden soll.)
  fd(double v): v(v), vs(v), logger(v) {}
  fd(): v(0), vs(0), logger(0) {}
  // Zugriffsroutinen
  double& v_ref () { return v;}
  double& vs_ref () { return vs;}
  // "Störfunktion"
  double s() { double h=abs(vs)*sqrt(DBL_EPSILON); vs+=h;
    return h;
  }
  // Operatoren/Funktionen als Elementfunktionen
  fd operator++(int) {
    fd y(*this);  // unveränderte Kopie des Originalwerts speichern
    v++; vs++;  // Original verändern
    return y; // Kopie zurückgeben
  }

  // Zugriffsrechte
  friend fd sin(const fd&);
  friend fd operator*(const fd& a, const fd& b);
  friend fd operator-(const fd& a, const fd& b);
  friend void operator+=(fd& a, const fd& b);
  friend ostream& operator<<(ostream& o, const fd& x);
  friend int main(int, char**);
};

// Operatoren/Funktionen als Nichtelementfunktionen
fd sin(const fd& x) {
  fd y(sin(x.v)); // Neues Objekt mit berechnetem Wert konstruieren, damit logger etwas sinnvolles ausgibt
  y.vs = sin(x.vs);
  return y;
}
fd operator*(const fd& a, const fd& b) {
  fd y(a.v*b.v); // Neues Objekt mit berechnetem Wert konstruieren, damit logger etwas sinnvolles ausgibt
  y.vs = a.vs*b.vs;
  return y;
}
fd operator-(const fd& a, const fd& b) {
  fd y(a.v-b.v); // Neues Objekt mit berechnetem Wert konstruieren, damit logger etwas sinnvolles ausgibt
  y.vs = a.vs-b.vs;
  return y;
}
void operator+=(fd& a, const fd& b) {
  a.v+=b.v;
  a.vs+=b.vs;
}
// Optional! Hab ich hauptsächlich zum Testen gebraucht.
ostream& operator<<(ostream& o, const fd& x) {
  o << "v=" << x.v << " vs=" << x.vs << endl;
  return o;
}

// Funktion
template<class T>
void f(const vector<T>& x, T& y) {
  y=0;
  for (unsigned int i=0;i<x.size();i++) {
    T v=1e-3*(y++)-sin(x[i]);
    cout << v;
    y+=v*v;
  }
}

int main(int c, char* v[]) {
  assert(c==2); cout.precision(15);
  unsigned int n=atoi(v[1]);  // Anzahl Einträge des Eingabevektors
  vector<fd> x(n); fd y;
  // Initialisierung von x mittels Iterator
  for (vector<fd>::iterator j=x.begin();j!=x.end();j++) {
    double i;
    cout << "Wert? ";
    cin >> i;
    *j = fd(i);
  }
  cout << "Welchen Eintrag stören? ";
  unsigned int i; cin >> i; assert(i<n);
  double s=x[i].s();  // i-ten Eintrag stören
  f(x,y); // Funktion anwenden
  cout << "dy/dx[" << i << "]~" << (y.vs_ref()-y.v_ref())/s << endl;  // Ableitung ausgeben
  return 0;
}
