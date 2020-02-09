#include <iostream>
#include <cstdlib>
using namespace std;

int f(int a, int& b, int c) {
  static int d=1;
  cout << d++ << ": " << a << ", " << b << endl;
  if (b>c) return 1;
  b+=a*b;
  return f(a,b,63);
}

int main(int c, char* v[]) {
  int a=c;
  cout << a*f(1,a,atoi(v[1])) << endl;      // so steht die Zeile in der Aufgabenstellung...
  // cout << f(1,a,atoi(v[1]))*a << endl    // ...vermutlich sollte es aber eigentlich so da stehen!
  return 0;
}
