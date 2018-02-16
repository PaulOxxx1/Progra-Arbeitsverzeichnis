#include "trigonom.hpp"

double trigonom::eval(double x) {
  return a*sin(x) + b*cos(x) + c;
}

void trigonom::print() {
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

trigonom::trigonom(double a, double b, double c): a(a), b(b), c(c) {}

trigonom::~trigonom(){
  std::cout << "~trigonom" << std::endl;
}

