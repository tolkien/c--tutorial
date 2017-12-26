#include <iostream>
#include <string>
#include <thread>

using namespace std;

void message1() { cout << "Write a message\n"; }

int main(int argc, char **argv) {
	thread foo( []() {
		cout << "Hello World\n";
	});

	thread thr1(message1);

	thr1.join();
	foo.join();

	return 0;
}