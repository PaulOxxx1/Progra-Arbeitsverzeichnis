#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

class matrix {
  int s, **m;
public:
  matrix(ifstream& in) {
    in >> s;
    m = new int*[s];
    for (int i=0;i<s;i++) {
      m[i] = new int[s];
      for (int j=0;j<s;j++) {
        in >> m[i][j];
      }
    }
  }
  
  ~matrix() {
    for (int i=0;i<s;i++) {
      delete [] m[i];
    }
    delete [] m;
  }
  
  matrix(const matrix& a) {
    s = a.s;
    m = new int*[s];
    for (int i=0;i<s;i++) {
      m[i] = new int[s];
      for (int j=0;j<s;j++) {
        m[i][j] = a.m[i][j];
      }
    }
  }
  
  matrix& operator=(const matrix& a) {
    assert(a.s == s);
    for (int i=0;i<s;i++) {
      for (int j=0;j<s;j++) {
        m[i][j] = a.m[i][j];
      }
    }
    return *this;
  }
  
  int trace() {
    int result = 0;
    for (int i=0;i<s;i++) {
      result += m[i][i];
    }
    return result;
  }
  
  void print(ofstream& out) {
    out << s << endl;
    for (int j=0;j<s;j++)
      for (int i=0;i<s;i++)
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
    if (next) {
      delete next;
    }
    delete m;
  }

private:
  matrix_list_element(matrix_list_element&);
  matrix_list_element& operator=(matrix_list_element&);
  
  friend class matrix_list;
};

class matrix_list {
  matrix_list_element* head;
public:
  matrix_list(): head(0) {};
  
  ~matrix_list() {
    delete head;
  }
  
  void add_matrix(matrix* m) {
    matrix_list_element* p = head;
    matrix_list_element* hp = head;
    while (hp) {
      p = hp;
      hp = hp->next;
    }
    if (p) {
      p->next = new matrix_list_element(m);
    } else {
      head = new matrix_list_element(m);
    }
  }
  
  matrix* max() {
    matrix_list_element* p = head;
    matrix_list_element* hp = head;
    while (p) {
      if (p->m->trace() >= hp->m->trace()) {
        hp = p;
      }
      p = p->next;
    }
    return hp->m;
  }
  
private:
  matrix_list(matrix_list&);
  matrix_list& operator=(matrix_list&);
};

int main(int c, char* v[]) {
  assert(c==3);
  ifstream in(v[1]);
  ofstream out(v[2]);
  int l; in >> l;
  matrix_list ml;
  for (int i=0;i<l;i++) {
    ml.add_matrix(new matrix(in));
  }
  ml.max()->print(out);
  return 0;
}