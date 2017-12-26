/*
자 위와 같이 만들면 문제가 있죠. 블럭을 벋어나면 사라진다는 거죠. 
그렇기 때문에 object를 생성하는 코드만 따로 만들어 놓을 수가 없습니다. 
정적으로 생성하여서는 불가는 한거죠. 그러므로 동적으로 생성해야 합니다. 
  
그럼 이번에서 계속 존재하도록 만들어 보겠습니다.
*/
#include <iostream>

using namespace std;

class Dog {
public:
	Dog() { cout << "dog is born\n"; }
	~Dog() { cout << "dog is dead\n"; }
};

int main(void) {
	Dog *_dog = new Dog;
	return 0;
}