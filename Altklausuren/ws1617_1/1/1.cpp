#include <iostream>
using namespace std;

int main() {
  const int n = 4;
  int** x[n];
  for (int i=0;i<n;i++) {
    x[i]=new int*[i+1];
    for (int j=0;j<i+1;j++) {
      x[i][j] = new int;
      x[i][j][0] = j+1;
    }
  }
  int*** p=&x[0];
  for (int i=0;i<n;i++,p++) {
    int** q=p[0];
    for (int j=0;j<i+1;j++) {
      cout << q[j][0] << endl;
    }
  }
  for (int i=0;i<n;i++,p++) {
    for (int j=0;j<i+1;j++) {
      delete x[i][j];
    }
    delete [] x[i];
  }
  return 0;
}