#include <list>
using namespace std;

template<typename T>
struct stack {
  list<T> v;
  void push(const T& i);
  const T& top() { return v.back(); }
  void pop() { v.pop_back(); }
  bool empty() { return v.size()==0; }
  unsigned int size() { return v.size(); }
};

#include "stack.cpp"