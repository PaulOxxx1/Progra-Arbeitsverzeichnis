#pragma once
#include <iostream>
#include "funktion.hpp"

class integral {
protected:
  double x_links, x_rechts;
  int n;
  
  virtual double computeArea(funktion*)=0;
  
public:
  void print(funktion*);
  
  integral(int, double, double); // Konstruktor
  virtual ~integral();  // Destruktor
};