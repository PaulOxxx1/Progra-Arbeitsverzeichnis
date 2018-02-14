#include <iostream>
#include <cstdlib>
using namespace std;

struct A {
  int i;
  A(int i): i(i) {}
  ~A() { cout << i << endl; }
};

int main(int c, char* v[]) {
  A** a = new A*[c];
  for (int i=0;i<atoi(v[1]);i++) a[i]=new A(i);
  for (int i=0;i<atoi(v[1]);i++) delete a[i];
  delete [] a;
  return 0;
}