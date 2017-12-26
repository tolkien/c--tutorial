/*
아주 많은 양의 노가다가 필요해지는 것입니다. 모든 서브 클래스들을 뒤져서
그 클래스마다 메소드를 추가하는 노가다...으...
역시 프로그램은 노가다란 말인가 하고있을 쯔음... 
 
GOF가 나타납니다. 팩토리 메소드를 사용해 하고 말이죠.^^; 
 
서브클레스에는 손을 대지 않습니다. 그냥 농장 클래스만 바꾸면 됩니다.
그럼 모두 적용됩니다. 앗싸! 
*/
#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {}
	~Animal() {}
	virtual void Speak() = 0;
};

class Dog : public Animal {
public:
	Dog() { cout << "dog is born\n"; }
	~Dog() { cout << "dog is dead\n"; }
	void Speak() { cout << "bark, bark\n"; }
};

class Cat : public Animal {
public:
	Cat() { cout << "cat is born\n"; }
	~Cat() { cout << "cat is dead\n"; }
	void Speak() { cout << "mew, mew\n"; }
};

class Farm {
public:
	Farm() { cout << "Farm is created\n"; }
	~Farm() { cout << "Farm is destroyed\n"; }
	void NewAnimal() {
		Animal *pAnimal = CreateAnimal();
		pAnimal->Speak();
	}

	virtual Animal *CreateAnimal() = 0;
};

class DogFarm : public Farm {
public:
	DogFarm() { cout << "DogFarm is created\n"; }
	~DogFarm() { cout << "DogFarm is destroyed\n"; }
	Animal *CreateAnimal() {
		return new Dog;
	}
};

/*
이런 식으로 수정하는 겁니다. 어떤 동물이 태어나는 지는 DogFarm이
결정권을 가지고 있지만 실행하는 함수는 Farm에 있습니다.  그러므로
Farm에다 울음을 터트리는 함수를 넣으면 되는 겁니다. 앗싸~ 코딩 줄었다. 
*/

class CatFarm : public Farm {
public:
	CatFarm() { cout << "CatFarm is created\n"; }
	~CatFarm() { cout << "CatFarm is destroyed\n"; }
	Animal *CreateAnimal() {
		return new Cat;
	}
};

int main(void) {
	DogFarm _DogFarm;
	_DogFarm.NewAnimal();

	return 0;
}
