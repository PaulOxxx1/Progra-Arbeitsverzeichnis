#pragma once
#include "integral.hpp"

class riemann : public integral {
  double computeArea(funktion*);
  
public:
  riemann(int, double, double); // Konstruktor
  ~riemann(); // Destruktor
};