#include "riemann.hpp"

double riemann::computeArea(funktion* fp) {
  double eps = (x_rechts-x_links)/n;
  double result = 0;
  for (int i=0; i<n; i++) {
    result += eps * fp->eval(x_links+(i+0.5)*eps);
  } 
  return result;
}

riemann::riemann(int n, double x_links, double x_rechts): integral(n, x_links, x_rechts) {}

riemann::~riemann(){
  std::cout << "~riemann" << std::endl;
}