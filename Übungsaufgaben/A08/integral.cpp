#include "integral.hpp"

void integral::print(funktion* fp) {
  std::cout << "Integral von ";
  fp->print();
  std::cout << ": " << computeArea(fp) << std::endl;
}

integral::integral(int n, double x_links, double x_rechts): n(n), x_links(x_links), x_rechts(x_rechts) {}

integral::~integral(){
  std::cout << "~integral" << std::endl;
}