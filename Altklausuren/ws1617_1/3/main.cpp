#include<stdlib>
#include<iostream>

class logger {
protected:
  logger(double v) { cout << "logger=" << v << endl; } 
};

class fd : public logger {
  double v, vs;
public:
  // Konstruktoren (2 Punkte)
  // ... TODO
  double& v_ref () { return v;}
  double& vs_ref () { return vs;}
  double s() { double h=abs(vs)*sqrt(DBL_EPSILON); vs+=h;
    return h;
  }
  // Operatoren/Funktionen als Elementfunktionen (x Punkte)
  // ... TODO

  // Zugriffsrechte (y Punkte)
  // ... TODO
};

// Operatoren/Funktionen als Nichtelementfunktionen (z Punkte; x+y+z=14)
// ... TODO

template<class T>
void f(const vector<T>& x, T& y) {
  y=0;
  for (unsigned int i=0;i<x.size();i++) {
    T v=1e−3*(y++)−sin(x[i]);
    y+=v*v;
  }
}

int main(int c, char* v[]) {
  assert(c==2); cout.precision(15);
  unsigned int n=atoi(v[1]);
  vector<fd> x(n); fd y;
  // Initialisierung von x mittels Iterator (2 Punkte)
  // ... TODO
  unsigned int i; cin >> i; assert(i<n);
  double s=x[i].s();
  f(x,y);
  cout << "dy/dx[" << i << "]~" << (y.vs_ref()−y.v_ref())/s << endl;
  return 0;
}
