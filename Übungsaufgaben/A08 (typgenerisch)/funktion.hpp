#pragma once
#include <iostream>

template<typename T>
class funktion {
public:
  virtual T eval(T x)=0;
  virtual void print()=0;
  
  virtual ~funktion(){ std::cout << "~funktion" << std::endl; }
};