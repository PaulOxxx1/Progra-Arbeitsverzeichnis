#include<iostream>

using namespace std;

int main() {
  // Allokation
  int* v[2];
  int i;
  int*** p;

  // Pointer füllen
  p = new int**;
  *p = &v[0];
  v[1] = new int[2];
  v[0] = &v[1][1];

  // Deallokation
  delete[] v[1];
  delete p;

  return 0;
}
