#include<iostream>

using namespace std;

int main() {
  // Allokation
  int j;
  int* v[4];
  int i;

  // Pointer füllen
  v[0] = new int;
  v[1] = &i;
  v[2] = &j;
  v[3] = v[0];

  // Deallokation
  delete v[0];

  return 0;
}
