#include "riemann.hpp"

template<typename T>
T riemann<T>::computeArea(funktion<T>* fp) {
  T eps = (integral<T>::x_rechts-integral<T>::x_links)/integral<T>::n;
  T result = 0;
  for (int i=0; i<integral<T>::n; i++) {
    result += eps * fp->eval(integral<T>::x_links+(i+0.5)*eps);
  } 
  return result;
}

template<typename T>
riemann<T>::riemann(int n, T x_links, T x_rechts): integral<T>(n, x_links, x_rechts) {}
template riemann<double>::riemann(int, double, double);

template<typename T>
riemann<T>::~riemann(){
  std::cout << "~riemann" << std::endl;
}
