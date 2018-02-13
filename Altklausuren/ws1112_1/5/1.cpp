#include <iostream>
#include <iomanip> // FÜR AUSGABE
#include <cstdlib>
#include <cmath>
using namespace std;

void op(int n, int p, const float* u, const float* v, float**& m) {
  m = new float*[n];
  for (int i=0;i<n;i++) {
    m[i] = new float[p];
    for (int j=0;j<p;j++) {
      m[i][j] = u[i]*v[j];
    }
  }
}

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);
  int p = atoi(argv[2]);
  float* u = new float[n];
  for (int i=0;i<n;i++) u[i]=cos(i);
  float* v = new float[p];
  for (int i=0;i<p;i++) v[i]=cos(i+1);
  float** m;
  
  op(n,p,v,u,m);
  
  // OPTIONALE AUSGABE
  cout << setprecision(3) << fixed;
  for (int i=0;i<n;i++) {
    for (int j=0;j<p;j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  // AUSGABE ENDE
  
  for (int i=0;i<n;i++) delete [] m[i];
  delete [] m; delete [] u; delete [] v;
}