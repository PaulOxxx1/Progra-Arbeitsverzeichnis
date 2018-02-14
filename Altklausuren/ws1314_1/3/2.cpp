#include<cstdlib>
#include<iostream>

class A {
public:
  int i;
  A(int j) : i(j) { i--; }
  void f(int j) { i*=j; }
};

int main(int c, char* v[]) {
  A a(std::atoi(v[1])); a.f(std::atoi(v[2]));
  std::cout << a.i << std::endl;
  return 0;
}