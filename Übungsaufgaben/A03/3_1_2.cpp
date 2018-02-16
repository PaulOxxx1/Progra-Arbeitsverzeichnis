#include<iostream>
#include<cmath>

using namespace std;

int n;  // Zählt wie oft Funktion f() verwendet wird

// Die mathematische Funktion aus der Aufgabe
double f(double x) {
  n++;
  if (x<=-2) {
    return cos((M_PI/2)*x)+3;
  } else if (x<=0) {
    return 2*x+6;
  } else if (x<=2) {
    return 3*x*x+6;
  } else {
    return 18;
  }
}

// Funktion A() schätzt den Integralwert zur Funktion f() zwischen zwei Grenzen l und r und mit einem gegebenen Epsilon
double A(double l, double r, double eps) {
  double fl = f(l); // Funktionswert an der linken Grenze
  double fr = f(r); // Funktionswert an der rechten Grenze

  // Vergleiche exakten und approximierten Funktionswert an der Stelle (l+r)/2
  if (abs(f((l+r)/2) - (fl+fr)/2) > eps) {
    // Abweichung zu groß, also halbiere Intervallbreite und starte mit neuen Grenzen
    return A(l,(r+l)/2,eps) + A((r+l)/2,r,eps);
  } else {
    // Abweichung < eps, also errechne Fläche des Trapez
    return ((fl+fr)/2)*(r-l);
  }
}

int main() {
  // Deklarierung von Variablen
  double l = -4;
  double r = 4;
  double eps, a;

  // Legende
  cout << "eps: \tEpsilon" << endl;
  cout << "a: \tgeschätzter Integralwert" << endl;
  cout << "n: \tAnzahl der Funktionsauswertungen" << endl;
  cout << "E: \trelativer Fehler" << endl;
  cout << endl;

  // Errechne geschätzten Integralwert für verschiedene Genauigkeiten
  for (int i=1;i<=4;i++) {
    eps=pow(10,-i); // eps = aktuelles Epsilon
    cout << "eps=" << eps << endl;

    n=0; // Zähler zurücksetzen

    /* Ausgabe des geschätzten Integralwerts zu den gegebenen Grenzen und mit aktueller Genauigkeit.
    Funktion wird zweimal aufgerufen, damit die maximale Intervall-Breite eines Trapezes der halben
    Breite des zu berechnenden Integrals entspricht */
    a = A(l,(l+r)/2,eps) + A((l+r)/2,r,eps);

    cout << "\ta=" << a << endl;
    cout << "\tn=" << n << endl;
    cout << "\tE=" << (a-70)/70 << endl;
    cout << endl;
  }

  return 0;
}
