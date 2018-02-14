#include <iostream>

int c=4;
class A {
public:
  A() { c--; }
};

int main() {
  A *a,b;
  while (c) {
    a=new A;
    std::cout << c << std::endl;
    delete a;
  }
  return 0;
}