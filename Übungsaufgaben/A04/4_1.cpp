#include<iostream>
#include<fstream>

using namespace std;

int main() {
  ifstream Ain("A.txt");
  ifstream Vin("v.txt");

  int zeilM;  Ain >> zeilM;
  int spalM;  Ain >> spalM;
  int zeilV;  Vin >> zeilV;
  int spalV;  Vin >> spalV;

  if ((spalM != zeilV) || (spalV != 1)) {
    cout << "FEHLER: Vektorprodukt lässt sich nicht bilden!";
    return 0;
  }

  double* Vektor = new double[zeilM];

  for (int z=0;z<zeilM;z++) {
    Vin >> Vektor[z];
  }

  for (int z=0;z<zeilM;z++) {
    double b=0;
    for (int s=0;s<spalM;s++) {
      double a;
      Ain >> a;
      b += a*Vektor[s];
    }
    cout << b << endl;
  }

  Ain.close();
  Vin.close();

  // Deallokation
  delete [] Vektor;

  return 0;
}
