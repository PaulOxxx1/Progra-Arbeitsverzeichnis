#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include "matrix.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  // Erwartet die Groesse der Matrix
  assert(argc==2);
  int size = atoi(argv[1]);
  
  // Matrix und Vektor erstellen
  matrix A(size);
  srand(0);
  vector<double> v(size);
  for (int i=0;i<size;i++) {
    v[i] = (double)rand()/RAND_MAX*10;
  }
  
  // Anzahl der Threads aendern
  for (int threads=2;threads<=16;threads=threads*2) {
    omp_set_num_threads(threads);
    cout << "Anzahl Threads: ";
    cout << threads << endl;
    
    /*
    cout << setprecision(3) << fixed;
    cout << "Matrix:" << endl;
    cout << A;
    cout << endl;
    */
    
    /*
    cout << "Vektor:" << endl;
    for (int i=0;i<size;i++) {
      cout << "[" << v[i] << "]" << endl;
    }
    cout << endl;
    */
    
    cout << "Ergebnis: ";
    double timediff;
    timediff = omp_get_wtime();
    cout << A.getP(v) << endl;
    timediff = omp_get_wtime() - timediff;
    cout << "Laufzeit: " << timediff << endl;
  }
  
  return 0;
}