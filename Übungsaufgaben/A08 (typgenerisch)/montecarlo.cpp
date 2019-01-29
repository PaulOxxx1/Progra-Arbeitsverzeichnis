#include "montecarlo.hpp"

template<typename T>
T montecarlo<T>::computeArea(funktion<T>* fp) {
  int m=0;  // Anzahl Punkte unter dem Graph
  for (int i=0; i<integral<T>::n; i++) {
    // Zufälliger Punkt:
    T x = integral<T>::x_links + (integral<T>::x_rechts-integral<T>::x_links)  * (static_cast<T>(rand()) / RAND_MAX);
    T y = y_unten + (y_oben-y_unten)    * (static_cast<T>(rand()) / RAND_MAX);

    // Vergleich:
    T f = fp->eval(x);
    if (f>0) {  // Graph liegt über x-Achse
      if (0<y&&y<f) m++;
    } else {
      if (0>y&&y>f) m--;
    }
  } 
  
  T area = (integral<T>::x_rechts-integral<T>::x_links) * (y_oben-y_unten); // Komplette Fläche
  return area*((T)m/integral<T>::n);
}

template<typename T>
montecarlo<T>::montecarlo(int n, T x_links, T x_rechts, T y_unten, T y_oben) :  integral<T>(n,x_links,x_rechts), y_unten(y_unten), y_oben(y_oben) {
  srand(time(0));
}
template montecarlo<double>::montecarlo(int, double, double, double, double);

template<typename T>
montecarlo<T>::~montecarlo(){
  std::cout << "~montecarlo" << std::endl;
}


