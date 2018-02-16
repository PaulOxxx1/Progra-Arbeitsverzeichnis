#include<iostream>

using namespace std;

int main() {
  // Allokation
  int**** p;
  int* q;
  int* i;

  // Pointer füllen
  p = new int***;
  *p = new int**[2];
  (*p)[0] = &i;
  (*p)[1] = &q;
  q = new int;

  // Deallokation
  delete q;
  delete[] *p;
  delete p;

  return 0;
}
