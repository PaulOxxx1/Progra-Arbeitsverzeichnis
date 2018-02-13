#include <iostream>
//using namespace std;

template<typename T>
class abstract_vector {
protected:
  virtual ~abstract_vector() {}
  virtual T& operator[](int)=0;
  virtual void print()=0;
};

class vector: public abstract_vector<int> {
  int *v; int s;
public:
  vector(int s): s(s) {
    v = new int[s];
    for (int i=0;i<s;i++) {
      v[i] = 0;      
    }
  }
  ~vector() { delete [] v; }
  int& operator[](int i) { return v[i]; }
  void print();
};

void vector::print() {
  for (int i=0;i<s;i++) {
    std::cout << v[i] << " ";   
  }
  std::cout << std::endl;
}

class matrix : public abstract_vector<vector> {
  vector **v; int s;
public:
  matrix(int s): s(s) { 
    v = new vector*[s];
    for (int i=0;i<s;i++) {
      v[i] = new vector(s);
    } 
  }
  ~matrix() {
    for (int i=0;i<s;i++) {
      delete v[i];
    }
    delete [] v;
  }
  vector& operator[](int i);
  void print() {
    for (int i=0;i<s;i++) {
      v[i]->print();
    }
  }
};

vector& matrix::operator[](int i) {
  return *v[i];
}

int main() {
  matrix m(2);
  m.print();
  m[0][1]=1;
  m[1][0]=2;
  m.print();
  return 0;
}




