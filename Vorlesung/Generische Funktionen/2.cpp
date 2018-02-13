#include <list>
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
struct stack {
  list<T> v;
  void push(const T& i);
  const T& top() { return v.back(); }
  void pop() { v.pop_back(); }
  bool empty() { return v.size()==0; }
  unsigned int size() { return v.size(); }
};

template<typename T>
void stack<T>::push(const T& i) { v.push_back(i); }

int main(int argc, char const *argv[]) {
  stack<A> s;
  s.push(1);
  cout << s.top() << endl;
  cout << s.size() << endl;
  cout << s.empty() << endl;
  s.pop();
  cout << s.size() << endl;
  cout << s.empty() << endl;  
  return 0;
}