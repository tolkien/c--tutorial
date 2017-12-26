/*
	객체 생성 예제
*/
#include <iostream>

using namespace std;

class Dog {
public:
	Dog() { cout << "dog is born\n"; }
	~Dog() { cout << "dog is dead\n"; }
};

int main(void) {
	Dog _dog;
	return 0;
}