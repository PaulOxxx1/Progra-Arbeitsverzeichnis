#include <iostream>
using namespace std;

class A {
  int i;
public:
  A(int i) : i(i) {};
  friend A operator-(const A&);
  friend A operator+(const A&, const A&);
  friend ostream& operator<<(ostream&, const A&);
};

A operator-(const A& x) {
  return A(x.i);
}

A operator+(const A& y, const A& x) {
  return A(y.i-x.i);
}

ostream& operator<<(ostream& s, const A& x) {
  s << x.i; return s;
}

template<class S>
void f(const S& x, S& y) { y=-(x+-y)+-x; }

int main(int c, char* v[]) {
  A y(2), x(3);
  f(y,x);
  cout << x << c << y << endl;
  return 42;
}