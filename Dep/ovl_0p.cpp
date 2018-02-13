#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct dep {
  double v;
  bool d;
  dep() : v(0), d(false) {}
  dep(const double& v) : v(v), d(false) {}
};

dep operator*(const dep& x, const dep& y) {
  dep z;
  z.v = x.v*y.v;
  z.d = x.d||y.d;
  return z;
}

dep sin(const dep& x) {
  dep y;
  y.v=sin(x.v);
  y.d=x.d;
  return y;
}

ostream& operator<<(ostream& s, const dep& x) {
  s << "(" << x.v << "," << x.d << ")";
  return s;
}

void f(vector<dep>& x) {
  int n=x.size();
  vector<dep> y(n);
  for (int i=0;i<n;i++)
    y[i]=sin(x[i])*x[(i+1)%n];
  x=y;
}

int main() {
  const int n=10;
  vector<dep> x(n,1);
  x[0].d=true;
  f(x);
  for (int i=0;i<n;i++) cout << x[i] << endl;
  return 0;
}
