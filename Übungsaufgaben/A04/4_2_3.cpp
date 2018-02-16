#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
  const int n=500;  // Konstante fuer # der Zeilen/Spalten der Matrix

  // EINLESEN DER MATRIX UND DES VEKTORS
  ifstream Ain("A.txt");
  ifstream Bin("b.txt");

  int zeilA;
  Ain >> zeilA;
  int spalA;
  Ain >> spalA;
  int zeilB;
  Bin >> zeilB;
  int spalB;
  Bin >> spalB;

  // Überprüfen der Größe der Matrix und des Vektors
  if ((zeilA != n) || (spalA != n) || (zeilB != n) || (spalB != 1)) {
    cout << "FEHLER: Groesse der Matrix und/oder des Vektors ungueltig! n=" << n << endl;
    return 0;
  }

  vector<vector<double> > a(n, vector<double>(n,0));  // Matrix
  vector<double> b(n,0);                              // Vektor
  vector<double> x(n,0);                              // Loesung

  for (int z=0; z<n; z++) {
    for (int s=0; s<n; s++) {
      Ain >> a[z][s];
    }
    Bin >> b[z];
  }

  for (int i=0; i<n; i++) {
    x[i] = 0;
  }

  Ain.close();
  Bin.close();

  // ALGORITHMUS
  // Auf Dreiecksform bringen
  for (int i=1; i<n; i++) {         // Gehe durch jede Zeile (ausser der letzten)
    for (int j=i+1; j<=n; j++) {
      // Ziehe die i-te Zeile c mal von allen Zeilen nach der i-ten Zeile ab
      double c = a[j-1][i-1]/a[i-1][i-1];

      for (int k=1; k<=n; k++) {
        a[j-1][k-1] -= c * a[i-1][k-1];
      }

      b[j-1] -= c*b[i-1];
    }
  }

  // Matrix liegt in Dreiecksform vor
  // Als naechstes alle gefundenen Loesungen rueckwaerts einsetzen
  for (int i=n; i>=1; i--) {
    double t=0; // Steht fuer die Summe in der Formel

    for (int j=i+1; j<=n; j++) {
      t += a[i-1][j-1] * x[j-1];
    }

    x[i-1] = (b[i-1] - t) / a[i-1][i-1];
  }

  // Ausgabe der Loesung in eine Textdatei
  ofstream Xout("x.txt");
  for (int i=0; i<n; i++) {
    Xout << x[i] << endl;
  }
  Xout.close();

  return 0;
}
