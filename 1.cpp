#include <iostream>
using namespace std;

struct A {
  int i;
  A(const int& i): i(i) {}
};

ostream& operator<<(ostream& s, const A& a) {
  s << a.i;
  return s;
}

template<typename T>
void print(const T& i) {
  cout << i << endl;
}

template<typename F, typename S>
void print(const S& a, const F& b) {
  cout << a << " " << b << endl;
}

int main(int argc, char const *argv[]) {
  int i=42;
  print(i);
  A a(43);
  print(a, a);
  return 0;
}