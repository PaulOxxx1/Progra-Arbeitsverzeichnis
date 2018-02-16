#include<iostream>

using namespace std;

int main() {
  // Allokation
  int* a;
  int*** b;
  int c;
  int d;

  // Pointer füllen
  b = new int**;
  a = new int;
  *b = new int*;
  **b = &d;

  // Deallokation
  delete *b;
  delete a;
  delete b;

  return 0;
}
