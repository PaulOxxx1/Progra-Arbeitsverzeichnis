#include <iostream>
#include <cstdlib>
using namespace std;

struct A {
  int i;
  A(int i): i(i) {}
  ~A() { cout << i-1; }
  void print() { cout << i; }
};

class B {
  A* a;
public:
  B(A* a): a(a) { }
  ~B() { delete a; }
  void print() { a->print(); }
};

int main(int c, char* v[]) {
  for (int i=0;i<c;i++) {
    B* b=new B(new A(i+atoi(v[1])));
    b->print();
    delete b;
  }
  cout << endl;
  return 0;
}