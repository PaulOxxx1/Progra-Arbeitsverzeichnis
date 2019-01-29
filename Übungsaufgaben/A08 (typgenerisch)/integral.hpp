#pragma once
#include <iostream>
#include "funktion.hpp"

template<typename T>
class integral {
protected:
  T x_links, x_rechts;
  int n;
  
  virtual T computeArea(funktion<T>*)=0;
  
public:
  void print(funktion<T>* fp) {
    std::cout << "Integral von ";
    fp->print();
    std::cout << ": " << computeArea(fp) << std::endl;
  }
  
  integral(int n, T x_links, T x_rechts): n(n), x_links(x_links), x_rechts(x_rechts) {}
  virtual ~integral() { std::cout << "~integral" << std::endl; }
};