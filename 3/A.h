struct A {
  int i;
  A(const int& i): i(i) {}
};

ostream& operator<<(ostream& s, const A& a);