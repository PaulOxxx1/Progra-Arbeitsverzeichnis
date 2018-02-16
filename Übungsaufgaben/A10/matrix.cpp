#include "matrix.hpp"

double matrix::getP(const vector<double>& v) {
  assert(v.size() == size);
  double result = 0;
  vector<double> b(size,0);
  // Matrix Vektor Produkt
#pragma omp parallel for
  for (int i=0;i<size;i++) {
    for (int k=0;k<size;k++) {
      b[i] += value[i][k]*v[k];
    }
  }
  // Vektor Vektor Produkt
  for (int i=0;i<size;i++) {
    result += b[i]*v[i];
  }
  return result;
}

// Ausgabe einer Matrix
ostream& operator<<(ostream& s, matrix& a) {
  for (int i=0;i<a.size;i++) {
    for (int j=0;j<a.size;j++) {
      s << "[" << a.value[i][j] << "]";
    }
    s << endl;
  }
  return s;
}

// Konstruktor (mit zufälligen Einträgen)
matrix::matrix(int n): size(n) {
  srand(0);

  value = new double*[n];
  for (int i=0;i<n;i++) {
    value[i] = new double[n];
    for (int j=0;j<n;j++) {
      value[i][j] = 10 * static_cast<double>(rand()) / RAND_MAX;
    }
  }
}

// Destruktor
matrix::~matrix() {
  for (int i=0;i<size;i++) {
    delete value[i];
  }
  delete value;
}