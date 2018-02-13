#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <mpi.h>
using namespace std;

class matrix {
  int size;
  double** value;
public:
  double getP(const vector<double>&);
  friend ostream& operator<<(ostream& s, matrix& a);
  matrix(int);
  ~matrix();
};