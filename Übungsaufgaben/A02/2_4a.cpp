#include<iostream>

using namespace std;

int main() {
  // Allokation
  int** p;
  int* v;
  int w;
  int i;

  // Pointer füllen
  p = new int*;
  *p = &i;
  v = &i;

  // Deallokation
  delete p;

  return 0;
}
