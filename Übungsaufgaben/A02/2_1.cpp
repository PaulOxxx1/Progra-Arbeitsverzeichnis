#include <cstring>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>

using std::cout;
using std::endl;

template<class T>
void to_bin(T v)
{
	union
	{
		T value;
		unsigned char bytes[sizeof(T)];
	};
	memset(&bytes, 0, sizeof(T));
	value=v;
	// assumes little endian machine
	for (size_t i = sizeof(T);i>0;i--)
	{
		unsigned char pot=128;
		for (int j = 7;j>=0;j--,pot/=2)
			if (bytes[i-1]&pot)
				cout << "1";
			else
				cout << "0";
		cout << " ";
	}
	cout << endl;
}

int main() {
	using namespace std;

	int x=-7; to_bin(x);
	x=127; to_bin(x);
	x=INT_MAX; to_bin(x);
	x=INT_MAX+1; to_bin(x);

	float y=-7; to_bin(y);
	y=127; to_bin(y);
	y=FLT_MAX; to_bin(y);
	y=FLT_MAX+1; to_bin(y);

	double z=-7; to_bin(z);
	z=127; to_bin(z);
	z=DBL_MAX; to_bin(z);
	z=DBL_MAX+1; to_bin(z);

	cout << sizeof(x) << endl;
	cout << sizeof(y) << endl;
	cout << sizeof(z) << endl;

	return 0;
}
