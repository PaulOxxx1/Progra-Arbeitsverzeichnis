#include <iostream>
using namespace std;

struct A {
  A() { cout << "A"; }
  virtual ~A() { cout << "~A"; }
};

class B: public A {
public:
  B() { cout << "B"; }
  ~B() { cout << "~B"; }
};

struct C: public B {
  C() { cout << "C"; }
  ~C() { cout << "~C"; }
};

void f(A*& v) {
  static int i=41;
  if (i++%2) { f(v); delete v; v=new C; }
  else v=new B;
}

int main() {
  A* w; f(w); delete w; cout << endl; return 42;
}
