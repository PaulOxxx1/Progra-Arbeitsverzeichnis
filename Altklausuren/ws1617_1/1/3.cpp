#include <iostream>
#include <cstdlib>
using namespace std;

class A {
  int v;
public:
  A(): v(0) {}
  A(int v): v(v) {}
  void print() {
    cout << v;
  }
};

class As {
  int s;
  A* v;
public:
  As(unsigned int s): s(s), v(new A[s]) {
    for (unsigned int i=0;i<s;i++) v[i]=i+1;
  }
  ~As() { delete [] v; }
  As(const As& x) {
    s=x.s; v=new A[x.s];
    for (unsigned int i=0;i<s;i++) v[i]=x.v[i];
  }
  As& operator=(const As& x) {
    if (this==&x) return *this;
    if (x.s!=s) {
      delete [] v;
      s=x.s;
      v=new A[s];
    }
    for (unsigned int i=0;i<s;i++) v[i] = x.v[i];
    return *this;
  }
  void print() {
    for (unsigned int i=0;i<s;i++) v[i].print();
  }
};

class Ass {
  unsigned int s;
  As **v;
public:
  Ass(unsigned int s): s(s), v(new As*[s]) {
    for (unsigned int i=0;i<s;i++) v[i] = new As(s);
  }
  ~Ass() {
    for (unsigned int i=0;i<s;i++) delete v[i];
    delete [] v;
  }
  Ass(const Ass& x) {
    s=x.s; v=new As*[x.s];
    for (unsigned int i=0;i<s;i++) v[i]=new As(s);
  }
  Ass& operator=(const Ass& x) {
    if (this==&x) return *this;
    if (x.s!=s) {
      for (unsigned int i=0;i<s;i++) delete v[i];
      delete [] v;
      s=x.s;
      v= new As*[s];
      for (unsigned int i=0;i<s;i++) v[i] = new As(s);
    }
    for (unsigned int i=0;i<s;i++) *v[i]=*(x.v[i]);
    return *this;
  }
  void print() {
    for (unsigned int i=0;i<s;i++) v[i]->print();
  }
};

int main(int c, char* v[]) {
  Ass x(atoi(v[1]));
  x.print();
  return 0;
}