#include <iostream>
using namespace std;

int main() {
  const int n=3;
  int **i[n]={new int*[n],new int*[n], new int*[n]};
  int k;
  for (int j=0;j<n;j++)
    for (k=0;k<n;k++) {
      i[j][k]=new int[n];
      for (int l=0;l<n;l++) i[j][k][l]=j+k+l;
    }
  for (int j=0;j<n;j++) i[j][j][j]-=k;
  for (int j=0;j<n-1;j++)
    for (k=0;k<n-1;k++)
      cout << i[0][j][k] << endl;
  for (int j=0;j<n;j++) {
    for (k=0;k<n;k++)
      delete [] i[j][k];
    delete [] i[j];
  }
  return 0;
}