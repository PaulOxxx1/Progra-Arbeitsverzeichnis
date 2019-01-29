#pragma once
#include "integral.hpp"

template<typename T>
class riemann : public integral<T> {
  T computeArea(funktion<T>*);
  
public:
  riemann(int, T, T); // Konstruktor
  ~riemann(); // Destruktor
};