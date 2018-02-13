#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct dep {
  double v;
  bool d;
  dep() : v(0), d(false) {}
  dep(const double& v) : v(v), d(false) {}
  dep& operator+=(const dep& x) {
    v+=x.v;
    d=d||x.d;
    return *this;
  }
};

dep operator*(const dep& x1, const dep& x2) {
  dep y;
  y.v=x1.v*x2.v;
  y.d=x1.d||x2.d;
  return y;
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

bool operator>(const dep& x1, const dep& x2) {
  return x1.v>x2.v;
}

dep operator++(dep& x, int) {
  dep y=x;
  x.v++;
  return y;
}

void f(vector<dep>& x) {
  int n=x.size();
  vector<dep> y(n);
  for (int i=0;i<n;i++) {
    y[i]=sin(x[i])*x[(i+1)%n];
    if (x[i]>y[i]) y[i]+=x[(i+3)%n]++;
  }
  x=y;
}

int main() {
  const int n=10;
  for (int j=0;j<n;j++) {
    vector<dep> x(n,1);
    x[j].d=true;
    f(x);
    for (int i=0;i<n;i++) cout << x[i].d;
    cout << endl;
  }
  return 0;
}
