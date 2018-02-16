#include "montecarlo.hpp"

double montecarlo::computeArea(funktion* fp) {
  int m=0;  // Anzahl Punkte unter dem Graph
  for (int i=0; i<n; i++) {
    // Zufälliger Punkt:
    double x = x_links + (x_rechts-x_links)  * (static_cast<double>(rand()) / RAND_MAX);
    double y = y_unten + (y_oben-y_unten)    * (static_cast<double>(rand()) / RAND_MAX);

    // Vergleich:
    double f = fp->eval(x);
    if (f>0) {  // Graph liegt über x-Achse
      if (0<y&&y<f) m++;
    } else {
      if (0>y&&y>f) m--;
    }
  } 
  
  double area = (x_rechts-x_links) * (y_oben-y_unten); // Komplette Fläche
  return area*((double)m/n);
}

montecarlo::montecarlo(int n, double x_links, double x_rechts, double y_unten, double y_oben) :  integral(n,x_links,x_rechts), y_unten(y_unten), y_oben(y_oben) {
  srand(time(0));
}

montecarlo::~montecarlo(){
  std::cout << "~montecarlo" << std::endl;
}


