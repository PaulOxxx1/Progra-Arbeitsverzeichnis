#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "funktion.hpp"

class polynom : public funktion {
  int degree;
  std::vector<double> p;
  
public:
  double eval(double x);
  void print();

  polynom(int degree, std::vector<double> p); // Konstruktor
  ~polynom(); // Destruktor
};