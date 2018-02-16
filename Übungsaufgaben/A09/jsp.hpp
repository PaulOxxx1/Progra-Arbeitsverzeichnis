#pragma once
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class jsp {
  // Daten
  double v;
  set<int> nz;
  
public:  
  // Konstruktoren
  jsp(): v(0) {}
  jsp(double v): v(v) {
    static int i = 0;
    nz.insert(i);
    i++;
  }
  
  // Operatoren
  friend jsp operator*(const jsp& a, const jsp& b) {
    jsp c;
    c.v = a.v*b.v;
    c.nz = set<int>(a.nz);
    c.nz.insert(b.nz.begin(),b.nz.end());
    return c;
  }

  friend jsp operator+(const jsp& a, const jsp& b) {
    jsp c;
    c.v = a.v+b.v;
    c.nz = set<int>(a.nz);
    c.nz.insert(b.nz.begin(),b.nz.end());
    return c;
  }

  friend jsp operator-(const jsp& a, const jsp& b) {
    jsp c;
    c.v = a.v-b.v;
    c.nz = set<int>(a.nz);
    c.nz.insert(b.nz.begin(),b.nz.end());
    return c;
  }

  friend jsp operator/(const jsp& a, const jsp& b) {
    jsp c;
    c.v = a.v/b.v;
    c.nz = set<int>(a.nz);
    c.nz.insert(b.nz.begin(),b.nz.end());
    return c;
  }

  friend bool operator<(const jsp& a, const jsp& b) {
    return a.v<b.v;
  }

  friend bool operator>(const jsp& a, const jsp& b) {
    return a.v>b.v;
  }

  friend ostream& operator<<(ostream& s, const jsp& a) {
    s << "v = " << a.v << "; nz = { ";
    for (set<int>::iterator i=a.nz.begin();i!=a.nz.end();++i) {
      s << *i << " ";
    }
    s << "}";
    return s;
  }
  
  friend jsp cos(const jsp& a) {
    jsp b;
    b.v = cos(a.v);
    b.nz = set<int>(a.nz);
    return b;
  }

  jsp& operator=(const double& a) {
    v = a;
    nz.clear();
    return *this;
  }
};
