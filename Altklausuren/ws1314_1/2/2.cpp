#include <iostream>
using namespace std;

class B {
public:
  ~B() { cout << "D" <<  endl; }
};

class D : public B {
public:
  D() { cout << "B"; }
  ~D() { cout << "A"; }
};

int main(int c, char* v[]) {
  cout << v[0] << endl;
  D d; B& br=d;
  return 0;
}