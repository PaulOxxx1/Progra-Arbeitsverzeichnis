/*
#include<list>
using namespace std;

class A {
  list<A**> *i;
public:
  A() : i(new list<A**>) {}
  virtual ~A() { delete i; }
  virtual void f()=0;
};

class B : public A {
  double *p;
public:
  B() : p(new double*) {}
  virtual ~B() { delete p; }
  void f() { cout << *(i->begin()) << endl; }
};

int main() {
  A* b=new B; b.f(); delete b;
  return 0;
}
*/

#include<iostream>
#include<list>
using namespace std;

class A {
public:
  list<A**> *i;
  A() : i(new list<A**>) {}
  virtual ~A() { delete i; }
  virtual void f()=0;
};

class B : public A {
  double *p;
public:
  B() : p(new double) {}
  virtual ~B() { delete p; }
  void f() { cout << *(i->begin()) << endl; }
};

int main() {
  A* b=new B; b->f(); delete b;
  return 0;
}