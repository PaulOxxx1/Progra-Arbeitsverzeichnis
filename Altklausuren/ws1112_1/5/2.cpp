#include <iostream>
#include <iomanip> // FÜR AUSGABE
#include <cstdlib>
#include <cmath>
#include <mpi.h>
using namespace std;

void op(int n, int p, const float* u, const float* v, float**& m) {
  int rank;
  int size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  // Hauptprozess:
  if (rank==0) {
    // Nur der Hauptprozess bekommt eine Matrix
    m = new float*[n];
    for (int i=0;i<n;i++) {
      m[i] = new float[p];
    }
    // Jede Zeile füllen
    for (int i=0;i<n;i++) {
      if (i%size==0) { // Zeile selbst ausrechnen
        for (int j=0;j<p;j++) m[i][j] = u[i]*v[j];
      } else { // Zeile empfangen
        MPI_Recv(m[i], p, MPI_FLOAT, i%size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      }
    }

  // Nebenprozesse:
  } else {
    float* a = new float[p]; // Hilfsvektor für Zeile
    for (int i=rank;i<n;i+=size) {
      // Nur manche Zeilen ausrechnen und an Hauptprozess senden
      for (int j=0;j<p;j++) a[j] = u[i]*v[j];
      MPI_Send(a, p, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);      
    }
    delete [] a;
  }
}

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  int n = atoi(argv[1]);
  int p = atoi(argv[2]);
  // ALLE Prozesse haben beide Vektoren
  float* u = new float[n];
  for (int i=0;i<n;i++) u[i]=cos(i);
  float* v = new float[p];
  for (int i=0;i<p;i++) v[i]=cos(i+1);
  float** m;
  
  op(n,p,v,u,m);
  
  // OPTIONALE AUSGABE
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank==0) {
    cout << setprecision(3) << fixed;
    for (int i=0;i<n;i++) {
      for (int j=0;j<p;j++) {
        cout << m[i][j] << " ";
      }
      cout << endl;
    }
  }
  // AUSGABE ENDE
  
  if (rank==0) {
    // Nur der Hauptprozess darf die Matrix löschen,
    // die Nebenprozesse haben keine
    for (int i=0;i<n;i++) delete [] m[i];
    delete [] m;
  }
  delete [] u; delete [] v;
  
  MPI_Finalize();
  return 0;
}