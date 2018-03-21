#include<iostream>
#include<omp.h>
#include<cmath>

using namespace std;

template <class T>
class polynom {
  int n;
  T* coeff;
public:
  polynom(int n, T* c) : n(n) {
    coeff = new T[n+1];
    for (int i=0; i<n+1; i++) coeff[i] = c[i];
  }
  ~polynom() { delete[] coeff; }
  T compute(T x) {
    T sum = 0;
    for (int i=0; i<n+1; i++) sum += coeff[i]*pow(x,i);
    return sum;
  }
  T integral(T l, T r, int m, int threads, double& time) {
    T sum = 0;
    omp_set_num_threads(threads);
    double start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (int i=0; i<m; i++) sum += (r-l)/m*compute(l+(r-l)/m*i+0.5*(r-l)/m);
    double end = omp_get_wtime();
    time = end - start;
    return sum;
  }
};

int main() {
  int n = 3;
  double* c = new double[n+1]{1.0,2.0,1.5,2.5};
  polynom<double> p(n,c);

  double time_1, time_2;
  cout << p.integral(2.0, 5.0, 1000000, 1, time_1) << endl;
  cout << p.integral(2.0, 5.0, 1000000, 2, time_2) << endl;

  cout << "time_1: " << time_1 << endl;
  cout << "time_2: " << time_2 << endl;
  cout << "speedup: " << time_1-time_2 << endl;

  return 0;
}
