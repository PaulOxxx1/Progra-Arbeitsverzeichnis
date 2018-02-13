#include <iostream>
using namespace std;

#include "A.h"
#include "stack.h"

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