#include <iostream>
#include <cstdlib>
#include "jsp.hpp"
using namespace std;

template<typename T>
void f(T x1, T x2, T& y1, T& y2) {
  T a, b, c, d;
  
  a = x1 * x2;
  b = x1 + x2;
  if (a < b) {
    c = a - 10.3;
    d = 0.5 + cos(x1);
  } else {
    c = a / 0.1;
    d = 0.1 * c;
  }
  if (c < 5) {
    c = 10;
  }

  y1 = c;
  y2 = d;
}

int main(int argc, char *argv[]) {
  jsp x1 = atof(argv[1]);
  jsp x2 = atof(argv[2]);
  jsp y1, y2;
  f(x1,x2,y1,y2);
  cout << x1 << endl << x2 << endl;
  cout << y1 << endl << y2 << endl;

  double dx1 = atof(argv[1]);
  double dx2 = atof(argv[2]);
  double dy1, dy2;
  f(dx1,dx2,dy1,dy2);
  cout << dx1 << endl << dx2 << endl;
  cout << dy1 << endl << dy2 << endl;
}
