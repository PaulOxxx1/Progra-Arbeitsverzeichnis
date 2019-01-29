#include <vector>
#include "polynom.hpp"
#include "trigonom.hpp"
#include "riemann.hpp"
#include "montecarlo.hpp"

using namespace std;

typedef double TYPE;

int main() {

	funktion<TYPE>* F[2];
	integral<TYPE>* I[2];

	vector<TYPE> p(4);
	p[0] = 3.0;
	p[1] = 0.0;
	p[2] = 0.7;
	p[3] = -1.2;
	int degree = 3;
	TYPE a = 0.2, b = 0.8, c = 2.4;
	int n = 10000;
	TYPE x_lb = 0.0, x_ub = 4.0, y_lb = -80, y_ub = 8.0;

	F[0] = new polynom<TYPE>(degree, p);
	F[1] = new trigonom<TYPE>(a, b, c);
	I[0] = new riemann<TYPE>(n, x_lb, x_ub);
	I[1] = new montecarlo<TYPE>(n, x_lb, x_ub, y_lb, y_ub);

	for (int f = 0; f < 2; f++) {
		for (int i = 0; i < 2; i++) {
			I[i]->print(F[f]);
		}
	}

	delete F[0];
	delete F[1];
	delete I[0];
	delete I[1];

	return 0;
}
