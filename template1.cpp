#include <iostream>

using namespace std;

template<typename T>
void __swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int i1 = 1, i2 = 2;
	cout << i1 << ", " << i2 << endl;

	__swap(i1, i2);
	cout << i1 << ", " << i2 << endl;

	double d1 = 3.1, d2 = 3.2;
	cout << d1 << ", " << d2 << endl;

	__swap(d1, d2);
	cout << d1 << ", " << d2 << endl;

	return 0;	
}