#include <vector>
#include <iostream>
using namespace std;

void f(int k, const double *const v, vector<const double*>& w) {
  for (int i=0; i<k; i++) w.push_back(v+i);
}

int main() {
  const int k=5;
  double *u=new double[k];
  vector<const double*> w;
  f(k,u,w);
  for (int i=0;i<k;i++) { cout << (w[i] == u+i) << endl; }
  delete [] u;
  return 0;
}