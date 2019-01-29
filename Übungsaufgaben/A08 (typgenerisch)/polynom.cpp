#include "polynom.hpp"

template<typename T>
T polynom<T>::eval(T x) {
  T result = 0;
  for (int i=0;i<=degree;i++) {
    result += pow(x,i) * p[i];
  }
  return result;
}

template<typename T>
void polynom<T>::print() {
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

template<typename T>
polynom<T>::polynom(int degree, std::vector<T> p) : degree(degree), p(p) {
  assert(p.size()==degree+1);    // Brauche genug Koeffizienten
}
template polynom<double>::polynom(int, std::vector<double>);

template<typename T>
polynom<T>::~polynom(){
  std::cout << "~polynom" << std::endl;
}