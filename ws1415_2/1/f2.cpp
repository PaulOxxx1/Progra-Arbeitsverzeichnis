template<class T>
class A {
  T** p; double q;
  A(int i) : p(new T*[i]) { q=1; }
  virtual ~A() { delete [] p; }
  void f(T);
};

template<class S>
void f(S q) {}

// Fehlerfrei