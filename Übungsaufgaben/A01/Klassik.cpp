#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main() {
  float p=0,x=0,y=0;
  int i,m;
  float z=0,n=0;
  ifstream in("points.dat");
  in >> m;
  i=0;
  while (i<m) {
    in >> x >> y;
    z=z + y*sin(0.75*pow(x,3));
    n=n + pow(sin(0.75*pow(x,3)),2);
    i++;
  }
  p=z/n;
  cout << "Neues x? "; cin >> x;
  y=p*sin(0.75*pow(x,3));
  cout << "p=" << p << endl;
  cout << "y=" << y << endl;
  in.close();
  return 0;
}
