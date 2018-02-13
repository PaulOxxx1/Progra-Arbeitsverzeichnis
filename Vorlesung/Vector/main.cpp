#include<iostream>
#include<cassert>

struct refable {
  virtual double& operator[](int)=0;
};

struct countable {
  static int c;
  countable() { ++c; };
  ~countable() { --c; };
};

int countable::c=0;

struct vector : refable, countable {
  int s;
  double* v;
  vector(int s) : s(s), v(new double[s]) {}
  ~vector() { delete [] v; }
  vector(const vector& x) : s(x.s), v(new double[x.s]) {
    for (int i=0;i<s;i++) v[i]=x.v[i];
  }
  vector& operator=(const vector& x) {
    assert(s==x.s);
    if (this==&x) return *this; 
    for (int i=0;i<s;i++) v[i]=x.v[i];
    return *this;
  }
  double& operator[](int i) {
    assert(i>=0&&i<s); return v[i];
  }
  vector operator+(const vector& x) {
    assert(s=x.s); 
    vector y(s);
    for (int i=0;i<s;i++) y.v[i]=v[i]+x.v[i];
    return y;
  }
};

std::ostream& operator<<(std::ostream& o, const vector& v) {
  o << "[ "; 
  for (int i=0;i<v.s;i++) o << v.v[i]<< " "; 
  o << "]"; 
  return o;
}

int main() {
  const int n=3;
  vector v(n);
  for (int i=0;i<n;i++) v[i]=i+1; 
  std::cout << v << std::endl;
  v=v+v;
  std::cout << v << std::endl;
  std::cout << countable::c << std::endl;
  return 0;
}
