#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

class matrix {
  // Daten
  int s, **m;
  
public:
  // Konstruktor
  matrix(ifstream& in) {
    in >> s;
    m = new int*[s];
    for (int i=0; i<s; i++) {
      m[i] = new int[s];
      for (int j=0; j<s; j++) {
        in >> m[i][j];
      }
    }
  }
  
  // Destruktor
  ~matrix() {
    for (int i=0; i<s; i++){ 
      delete[] m[i];
    }
    delete[] m;
  }
  
  int trace() { 
    int p = 0;
    for (int i=0; i<s; i++){
      p += m[i][i];
    }
    return p;
  }
  
  // Kopierkonstruktor
  matrix(const matrix& n) {
    m = new int*[s];
    for (int i=0; i<s; i++) {
      *m = new int[s];
      for (int j=0; j<s; j++) {
        m[i][j] = n.m[i][j];
      }
    }
  }

  // Zuweisungsoperator
  matrix& operator=(const matrix& n) {
    assert(s==n.s);
    for (int i=0; i<s; i++) {
      for (int j=0; j<s; j++) {
        m[i][j] = n.m[i][j];
      }
    }
    return *this;
  }
  
  void print(ofstream& out){
    out << s << endl;
    for(int j=0;j<s;j++)
      for(int i=0;i<s;i++)
        out << m[j][i] << " ";
    out << endl;
  }
};

class matrix_list_element {
  matrix *m;
  matrix_list_element *next;
public:
  matrix_list_element(matrix* m): m(m), next(0) {}

  ~matrix_list_element() {
    delete next;
    delete m;
  }

private:
  matrix_list_element(const matrix_list_element&);
  matrix_list_element& operator=(const matrix_list_element&);
 
  friend class matrix_list;
}; 

// Klasse matrix_list
class matrix_list {
  matrix_list_element* head;
public:
  matrix_list() : head(0) {};

  ~matrix_list() {
    if (head) delete head;
  }
  
  void add_matrix(matrix* m) {
    if (head) {
      // min 1 Element
      matrix_list_element* p = head;
      while (p->next) p = p->next;
      p->next = new matrix_list_element(m);
    } else {
      // Leere Liste
      head = new matrix_list_element(m);
    }
  }

  matrix* max() {
    if (head) {
      // min 1 Element
      matrix_list_element* current = head;
      matrix_list_element* highest = head;
      while (current->next) {
        if(current->m->trace() > highest->m->trace()){
          highest = current;
        }
        current = current->next;
      }
      return highest->m;
    } else {
      // Leere Liste
      return 0;
    }
  }
  
private:
  matrix_list(const matrix_list&);
  matrix_list& operator=(const matrix_list&);
};

int main(int c, char* v[]) {
  assert(c==3);
  ifstream in(v[1]);
  ofstream out(v[2]);
  int l; in >> l;
  matrix_list ml;
  for (int i=0;i<l;i++)
    ml.add_matrix(new matrix(in));
  ml.max()->print(out);
  return 0;
}