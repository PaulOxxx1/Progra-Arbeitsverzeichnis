#pragma once
#include <iostream>
#include <cmath>
#include "funktion.hpp"

template<typename T>
class trigonom : public funktion<T> {
  T a,b,c;
  
public:
  T eval(T x);
  void print();
  
  trigonom(T a, T b, T c); // Konstruktor
  ~trigonom();  // Destruktor
};