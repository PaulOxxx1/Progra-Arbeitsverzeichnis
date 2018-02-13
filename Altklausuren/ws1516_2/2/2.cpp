#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void f(const int i, char* b) {
  static string a = "He";
  switch (i) {
    case 2:
      cout << "l";
    case 7:
      cout << "l";
      break;
    case 1:
      if (i%2!=1) {
        cout << "no";
      }
      break;
    case 3:
      cout << a;
      break;
    default:
      cout << b[4];
  }
}

int main(int argc, char* argv[]) {
  int i = atoi(argv[1]);
  while (i>=0) {
    f(i,argv[0]);
    i--;
  }
  cout << " " << argv[2] << endl;
  return 0;
}