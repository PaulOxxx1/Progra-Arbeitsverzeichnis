#include<iostream>

using namespace std;

int main() {
  // Allokation
  int****** p;
  int*** q;
  int**** i;
  int j;

  // Pointer füllen
  p = new int*****;
  *p = &i;
  i = &q;
  q = new int**;
  *q = new int*;
  **q = &j;

  // Deallokation
  delete *q;
  delete q;
  delete p;

  return 0;
}
