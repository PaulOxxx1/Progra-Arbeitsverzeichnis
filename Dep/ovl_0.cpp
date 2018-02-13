#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void f(vector<double>& x) {
  int n=x.size();
  vector<double> y(n);
  for (int i=0;i<n;i++)
    y[i]=sin(x[i])*x[(i+1)%n];
  x=y;
}

int main() {
  const int n=10;
  vector<double> x(n,1);
  f(x);
  for (int i=0;i<n;i++) cout << x[i] << endl;
  return 0;
}
