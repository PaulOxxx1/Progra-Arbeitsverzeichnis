#include<cstdlib>
#include<cassert>
#include<iostream>
using namespace std;

// Abstrakte Basisklasse B mit rein virtueller Funktion print()
class B {
    virtual void print() = 0;   // das =0 sorgt für eine "rein" virtuelle Funktion
};

struct A : B {
    float v, dvdx;

    // Konstruktor -> erteilt einer Variable zunächste den Ableitungswert 1, da dx/dx = 1 ist
    A() : v(0), dvdx(1) {}

    // Folgende Dinge sind alle nicht notwendig, insbesondere weil keine dynamischen Daten (auf dem Heap) verwaltet werden:
    // Destruktoren, Kopierkonstruktoren, Zuweisungsoperatoren

    void print() { cout << v << " " << dvdx << endl; }
};


// --- OPERATOREN ---
// obwohl in der Aufgabe 7 Stück gefordert waren, funktionert der Code auch nur mit 6

// u * w
// -> wird benötigt, um zB "x*x*x" auszurechnen
A operator*(const A& u, const A& w) {
    A result;
    result.v = u.v * w.v;
    result.dvdx = u.dvdx * w.v + w.dvdx * u.v;
    return result;
}

// c * w
// -> wird benötigt, um zB "42.0*x" auszurechnen
A operator*(const float& c, const A& w) {
    A result;
    result.v = c * w.v;
    result.dvdx = w.dvdx * c;
    return result;
}

// u + w
// wird benötigt, um Terme des Polynoms zu addieren
A operator+(const A& u, const A& w) {
    A result;
    result.v = u.v + w.v;
    result.dvdx = u.dvdx + w.dvdx;
    return result;
}

// u + c
// wird benötigt, um letzten Term von den beiden f2 Funktionen zu addieren, weil hier ein int auf der rechten Seite steht
// ... welcher automatisch in einen float konvertiert werden kann
A operator+(const A& u, const float& c) {
    A result;
    result.v = u.v + c;
    result.dvdx = u.dvdx;
    return result;
}

// u - w
// wird benötigt, um Terme des Polynoms zu subtrahieren
A operator-(const A& u, const A& w) {
    A result;
    result.v = u.v - w.v;
    result.dvdx = u.dvdx - w.dvdx;
    return result;
}

// u - c
// wird benötigt, um der letzten Term von f1 zu addieren, weil hier ein int auf der rechten Seite steht
// ... welcher automatisch in einen float konvertiert werden kann
A operator-(const A& u, const float& c) {
    A result;
    result.v = u.v - c;
    result.dvdx = u.dvdx;
    return result;
}


// Testfunktionen
A f1(const A x) {
    A y;
    y = 42.42*x*x*x - 42.0*x*x - 4.2*x + 0.42*x - 42;
    return y;
}

A f2(const A& x) {
    return -42.42*x*x*x - 42.0*x*x - 4.2*x + 0.42*x + 42;
}

void f2(A x, A& y) {
    A z=x*x*x;
    y = 42.42*z - 42.0*x*x - 4.2*x + 0.42*x + 42;
}


// Hauptfunktion (könnte so aussehen...)
int main() {
    A x1; x1.v = 2;
    f1(x1).print();

    A x2; x2.v = 2;
    f2(x2).print();
    
    A y, x3; x3.v = 2;
    f2(x3,y);
    y.print();

    return 0;
}