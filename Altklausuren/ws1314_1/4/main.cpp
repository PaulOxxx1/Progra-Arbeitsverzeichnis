#include<iostream>
#include<cassert>

class vector {
  int n;
  double* v;
public:
  vector(int n): n(n) {
    v = new double[n];
    for (int i=0;i<n;i++) {
      v[i] = 0.0;
    }
  }
  ~vector() { delete [] v; }
  double& operator[](int i) { return v[i]; }
};

class matrix {
  int n;
  vector** v;
public:
  matrix(int n): n(n) {
    v = new vector*[n];
    for (int i=0;i<n;i++) {
      v[i] = new vector(n);
    }
  }
  ~matrix() {
    for (int i=0;i<n;i++) {
      delete v[i];
    }
    delete [] v;
  }
  vector& operator[](int i) { return *(v[i]); }
  matrix operator*(const matrix& a) {
    assert(n == a.n);
    matrix c(n);
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        for (int k=0;k<n;k++) {
          c[i][j] += v[i][0][k]*a.v[k][0][j];
        }
      }  
    }
    return c;
  }
  matrix(const matrix& b): n(b.n) {
    v = new vector*[n];
    for (int i=0;i<n;i++) {
      v[i] = new vector(n);
      for (int j=0;j<n;j++) {
        (*(v[i]))[j] = (*(b.v[i]))[j];
      }
    }
  }
  matrix& operator=(const matrix& b) {
    if (this==&b) return *this;
    assert(n==b.n);
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        (*(v[i]))[j] = (*(b.v[i]))[j];
      }
    }
    return *this;
  }
};

int main() {
  const int n=2;
  matrix a(n),b(n),c(n);
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      a[i][j]=2*i+j;
      b[i][j]=i+2*j;
    }
  }
  c=a*b;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      std::cout << b[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      std::cout << c[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}