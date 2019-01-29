#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "funktion.hpp"

template<typename T>
class polynom : public funktion<T> {
  int degree;
  std::vector<T> p;
  
public:
  T eval(T x);
  void print();

  polynom(int degree, std::vector<T> p); // Konstruktor
  ~polynom(); // Destruktor
};