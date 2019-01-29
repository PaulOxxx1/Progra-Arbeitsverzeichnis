#pragma once
#include <cstdlib>
#include "integral.hpp"

template<typename T>
class montecarlo : public integral<T> {
  T y_unten, y_oben;
  
  T computeArea(funktion<T>*);
  
public:
  montecarlo(int, T, T, T, T);  // Konstruktor
  ~montecarlo();
};