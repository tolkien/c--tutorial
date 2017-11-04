#include <iostream>

template<typename F>
void Test(F fn) {
	fn();
}

int main(void) {
	Test([]{
		std::cout << "hello, world\n";
	});

	return 0;
}