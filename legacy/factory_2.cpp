/*
죽었다는 말이 안나오죠? 함수를 벗어나도 소멸하지 않습니다.
그러므로 이제 main에서 직접 생성해 줄 필요가 없어집니다.

그럼 이렇게 고쳐 보겠습니다.
*/
#include <iostream>

using namespace std;

class Dog {
public:
	Dog() { cout << "dog is born\n"; }
	~Dog() { cout << "dog is dead\n"; }
};

class DogFarm {
public:
	DogFarm() {}
	~DogFarm() {}

	Dog *pdog;
	void DogCreate() {
		pdog = new Dog;
	}
};

int main(void) {
	DogFarm _DogFarm;
	_DogFarm.DogCreate();

	return 0;
}