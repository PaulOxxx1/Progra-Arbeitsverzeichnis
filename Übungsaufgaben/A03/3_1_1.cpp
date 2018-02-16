#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {
  srand(time(0));

  float x,y,f;
  int m;

  // Legende
  cout << "n: \tAnzahl zufälliger Punkte" << endl;
  cout << "m: \tAnzahl Punkte unter dem Funktionsgraph" << endl;
  cout << "a: \tgeschätzter Integralwert" << endl;
  cout << "E: \trelativer Fehler" << endl;
  cout << endl;

  for (int n=10;n<=10000;n=n*10) {
    cout << "n=" << n << endl;

    m=0;
    for (int i=1; i<=n; i++) {
      x = -4 + 8 * (static_cast<double>(rand()) / RAND_MAX);
      y = 20 * (static_cast<double>(rand()) / RAND_MAX);

      if (x<=-2) {
        f = cos((M_PI/2)*x)+3;
      } else if (x<=0) {
        f = 2*x+6;
      } else if (x<=2) {
        f = 3*x*x+6;
      } else {
        f = 18;
      }

      if (y<f) m++;
    }

    cout << "\tm=" << m << endl;
    cout << "\ta=" << ((double)160*m)/n << endl;
    cout << "\tE=" << (((double)160*m)/n - 70) / 70 << endl << endl;
  }

  return 0;
}
