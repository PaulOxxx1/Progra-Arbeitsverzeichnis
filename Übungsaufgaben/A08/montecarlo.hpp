#pragma once
#include <cstdlib>
#include "integral.hpp"

class montecarlo : public integral {
  double y_unten, y_oben;
  
  double computeArea(funktion*);
  
public:
  montecarlo(int, double, double, double, double);  // Konstruktor
  ~montecarlo();
};