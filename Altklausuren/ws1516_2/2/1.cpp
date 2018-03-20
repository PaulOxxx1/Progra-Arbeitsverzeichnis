#include <iostream>
#include <cstdlib>
using namespace std;

struct B {
  int v;
  B(int v) : v(v) {
    cout << v;
  }
  ~B() {
    cout << v/2;
  }
};

class A{
  B* b;
public:
  A(B* b) : b(b) {}
  ~A(){
    if (b !=0){
      delete b;
    }
  }
};

int main(int c, char *v[]) {
  for (int i=1; i < c; ++i) {
    B* b = new B(atoi(v[i]));
    A a(b);
  }
  cout << endl;
  return 0;
}
