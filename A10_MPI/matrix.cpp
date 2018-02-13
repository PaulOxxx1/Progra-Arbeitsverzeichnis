#include "matrix.hpp"

double matrix::getP(const vector<double>& v) {
  // Vorbereitungen treffen
  assert(v.size() == size);
  double result = 0;
  vector<double> b(size,0);
  
  // MPI Zeug 
  int id;
  int num_procs;
  MPI_Status* status;
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
  
  // Arbeit senden
  int work = 1;
  for (int i=0;i<size;i++) {
    int target = (i%(num_procs-1))+1;
    MPI_Send(&work, 1, MPI_INT, target, 4, MPI_COMM_WORLD);
    MPI_Send(&value[i][0], size, MPI_DOUBLE, target, 0, MPI_COMM_WORLD);
    MPI_Send(&v[0], size, MPI_DOUBLE, target, 1, MPI_COMM_WORLD);
  }
  
  // Ergebnisse sammeln
  for (int i=0;i<size;i++) {
    MPI_Recv(&b[i], 1, MPI_DOUBLE, (i%(num_procs-1))+1, 2, MPI_COMM_WORLD, status);
  }
  
  // Arbeiter entlassen
  work = 0;
  for (int i=1;i<num_procs;i++) {      
    MPI_Send(&work, 1, MPI_INT, i, 4, MPI_COMM_WORLD);
  }
  
  // Vektor Vektor Produkt berechnen
  for (int i=0;i<size;i++) {
    result += b[i]*v[i];
  }
  
  // Fertig
  return result;
}

// Ausgabe einer Matrix
ostream& operator<<(ostream& s, matrix& a) {
  for (int i=0;i<a.size;i++) {
    for (int j=0;j<a.size;j++) {
      s << "[" << a.value[i][j] << "]";
    }
    s << endl;
  }
  return s;
}

// Konstruktor (mit zufälligen Einträgen)
matrix::matrix(int n): size(n) {
  srand(0);

  value = new double*[n];
  for (int i=0;i<n;i++) {
    value[i] = new double[n];
    for (int j=0;j<n;j++) {
      value[i][j] = 10 * static_cast<double>(rand()) / RAND_MAX;
    }
  }
}

// Destruktor
matrix::~matrix() {
  for (int i=0;i<size;i++) {
    delete value[i];
  }
  delete value;
}