#include<iostream>
using namespace std;

int main() {
  const int n=3, m=2;
  int **T[n];
  for (int i=0; i<n; i++){
    T[i] = new int*[m];
    for (int j=0; j<m; j++){
      T[i][j] = new int[m];
    }
  }

  for (int i=n-1; i>-1; i--){
    for (int j=m-1; j>-1; j--){
      for (int k=m-1; k>-1; k--){
        cout << (&T[i][j][k]) << endl;
      }
    }
  }

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      delete[] T[i][j];
    }
    delete[] T[i];
  }
  
  return 0;
}
