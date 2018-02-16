#include "polynom.hpp"

double polynom::eval(double x) {
  double result = 0;
  for (int i=0;i<=degree;i++) {
    result += pow(x,i) * p[i];
  }
  return result;
}

void polynom::print() {
  std::cout << "f(x) = ";
  bool nullfunktion = true;
  for (int i=0;i<=degree;i++) {
    if (p[i]) {   // Ignoriere Nullterme
      nullfunktion = false;
      // Vorzeichen
      if (p[i]>0) {
        if (i>0) std::cout << " + ";
      } else {
        std::cout << " - ";
      }
      // Koeffizient
      std::cout << abs(p[i]);
      // Potenz
      if (i>0) std::cout << " * x^" << i; 
    }
  }
  if (nullfunktion) {   // Nullfunktion
    std::cout << "0";
  }
}

polynom::polynom(int degree, std::vector<double> p) : degree(degree), p(p) {
  assert(p.size()==degree+1);    // Brauche genug Koeffizienten
}

polynom::~polynom(){
  std::cout << "~polynom" << std::endl;
}