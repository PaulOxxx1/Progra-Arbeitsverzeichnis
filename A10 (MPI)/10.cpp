#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[]) {
  // Erwartet die Groesse der Matrix
  assert(argc==2);

  int size = atoi(argv[1]);
  double result = 0;
  double** matrix;
  double* vector;
  double* vector2;

  // MPI Zeug
  MPI_Init(&argc, &argv);
  int id;
  int num_procs;
  MPI_Status* status;
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
  
  assert(num_procs > 1);

  int work = 1;

  // Hauptprozess
  if (id == 0) {
    // Matrix und Vektor erstellen
    srand(0);
    vector = new double[size];
    vector2 = new double[size];
    for (int i=0;i<size;i++) {
      vector[i] = (double)rand()/RAND_MAX*10;
      vector2[i] = 0;
    }
    
    srand(0);
    matrix = new double*[size];
    for (int i=0;i<size;i++) {
      matrix[i] = new double[size];
      for (int j=0;j<size;j++) {
        matrix[i][j] = 10 * static_cast<double>(rand()) / RAND_MAX;
      }
    }
    
    // An die Arbeit
    for (int i=1;i<num_procs;i++) {
      MPI_Send(vector, size, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);      
    }
    for (int i=0;i<size;i++) {
      int target = (i%(num_procs-1))+1;
      MPI_Send(&work, 1, MPI_INT, target, 4, MPI_COMM_WORLD);
      MPI_Send(matrix[i], size, MPI_DOUBLE, target, 0, MPI_COMM_WORLD);
      MPI_Recv(&vector2[i], 1, MPI_DOUBLE, (i%(num_procs-1))+1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    // int num_workers = num_procs-1;
    // for (int i=1;i<=num_workers;i++) {
    //   int min = ((i-1)/num_workers)*size;
    //   int max = ( i   /num_workers)*size-1;
    //   for (int j=min;j<=max;j++) {
    //     MPI_Send(&work, 1, MPI_INT, i, 4, MPI_COMM_WORLD);
    //     MPI_Send(matrix[j], size, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
    //     MPI_Send(vector, size, MPI_DOUBLE, i, 1, MPI_COMM_WORLD); 
    //   }
    // }
        
    // Arbeiter entlassen
    work = 0;
    for (int i=1; i<num_procs; i++) {
      MPI_Send(&work, 1, MPI_INT, i, 4, MPI_COMM_WORLD);
    }
        
    // Vektor Vektor Produkt berechnen
    for (int i=0;i<size;i++) {
      result += vector2[i]*vector[i];
    }

    // Ergebnis ausgeben
    cout << result << endl;

  // Nebenprozesse
  } else {
    double* a = new double[size];
    double* b = new double[size];
    double c;
    // Vektor empfangen
    MPI_Recv(b, size, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, status);
    // Arbeit flag empfangen
    MPI_Recv(&work, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, status);
    while (work) {
      // Matrix Zeile empfangen
      MPI_Recv(a, size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, status);
      c = 0;
      for (int i=0;i<size;i++) {
        c += a[i]*b[i];
      }
      // Ergebnis senden
      MPI_Send(&c, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
      // Arbeit flag empfangen
      MPI_Recv(&work, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, status);
    }
    delete [] a;
    delete [] b;
  }
  
  MPI_Finalize();
  return 0;
}