#include <ostream>
using namespace std;
#include "A.h"

ostream& operator<<(ostream& s, const A& a) {
  s << a.i;
  return s;
}