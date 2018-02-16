#include<iostream>
#include<cmath>
#include<climits>
#include<cfloat>

using namespace std;

int main() {
  float f = 236;
  double d = 236;
  long double ld = 236;

  cout << "x=236" << endl;
  cout << "Float:\t\ty=" << 2-(exp(3*f)-12)/(exp(3*f)+10) << endl;
  cout << "Double:\t\ty=" << 2-(exp(3*d)-12)/(exp(3*d)+10) << endl;
  cout << "Long Double:\ty=" << 2-(exp(3*ld)-12)/(exp(3*ld)+10) << endl;

  f = 237;
  d = 237;
  ld = 237;

  cout << "x=237" << endl;
  cout << "Float:\t\ty=" << 2-(exp(3*f)-12)/(exp(3*f)+10) << endl;
  cout << "Double:\t\ty=" << 2-(exp(3*d)-12)/(exp(3*d)+10) << endl;
  cout << "Long Double:\ty=" << 2-(exp(3*ld)-12)/(exp(3*ld)+10) << endl;

  cout << "Stellen für Overflow:" << endl;
  cout << "Float:\t\tx=" << log(FLT_MAX)/3 << endl;
  cout << "Double:\t\tx=" << log(DBL_MAX)/3 << endl;
  cout << "Long Double:\tx=" << log(LDBL_MAX)/3 << endl;

  return 0;
}
