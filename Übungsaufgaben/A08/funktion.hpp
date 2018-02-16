#pragma once

class funktion {
public:
  virtual double eval(double x)=0;
  virtual void print()=0;
  
  virtual ~funktion(){std::cout << "~funktion" << std::endl;};
};