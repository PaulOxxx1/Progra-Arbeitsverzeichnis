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

    // Standardkonstruktor -> erteilt einer Variable zunächste den Ableitungswert 1, da dx/dx = 1 ist
    A() : v(0), dvdx(1) {}
    // impliziter Konstruktor für Konstanten -> erteilt einer Konstante den Ableitungswert 0, da dc/dx = 0 ist
    A(const float& v) : v(v), dvdx(0) {}    

    // Folgende Dinge sind alle nicht notwendig, insbesondere weil keine dynamischen Daten (auf dem Heap) verwaltet werden:
    // Destruktoren, Kopierkonstruktoren, Zuweisungsoperatoren

    void print() { cout << v << " " << dvdx << endl; }
};



// --- OPERATOREN ---
// mit "impliziter Typkonvertierung" benötigt man sogar nur 3 statt 7 Operatoren

// u * w
// -> wird benötigt, um zB "x*x*x" auszurechnen
A operator*(const A& u, const A& w) {
    A result;
    result.v = u.v * w.v;
    result.dvdx = u.dvdx * w.v + w.dvdx * u.v;
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

// u - w
// wird benötigt, um Terme des Polynoms zu subtrahieren
A operator-(const A& u, const A& w) {
    A result;
    result.v = u.v - w.v;
    result.dvdx = u.dvdx - w.dvdx;
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