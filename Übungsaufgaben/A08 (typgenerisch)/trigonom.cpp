#include "trigonom.hpp"

template<typename T>
T trigonom<T>::eval(T x) {
  return a*sin(x) + b*cos(x) + c;
}

template<typename T>
void trigonom<T>::print() {
  std::cout << "f(x) = ";
  if (a||b||c) {
    if (a) {
      std::cout << a << " * sin(x)";
    }
    if (b) {
      if (a) std::cout << " + ";
      std::cout << b << " * cos(x)";
    }
    if (c) {
      if (a||b) std::cout << " + ";
      std::cout << c;
    }
  } else {
    std::cout << "0";
  }
}

template<typename T>
trigonom<T>::trigonom(T a, T b, T c): a(a), b(b), c(c) {}
template trigonom<double>::trigonom(double,double,double);

template<typename T>
trigonom<T>::~trigonom(){
  std::cout << "~trigonom" << std::endl;
}


