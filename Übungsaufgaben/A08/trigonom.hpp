#pragma once
#include <iostream>
#include <cmath>
#include "funktion.hpp"

class trigonom : public funktion {
  double a,b,c;
  
public:
  double eval(double x);
  void print();
  
  trigonom(double, double, double); // Konstruktor
  ~trigonom();  // Destruktor
};