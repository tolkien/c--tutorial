#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void) {
	int data[4] = {1, 2, 3, 4};
	cout << accumulate(data, data+4, 5);

	return 0;
}