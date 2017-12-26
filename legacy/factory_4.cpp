/*
그런데 문제가 생겼습니다. 태어난 동물은 모두 울음을 터트린다는 부분을 추가
하고 싶은 것입니다. 그래서 소스를 수정하기로 했습니다. 
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
	virtual void NewAnimal() {}
};

class DogFarm : public Farm {
public:
	DogFarm() { cout << "DogFarm is created\n"; }
	~DogFarm() { cout << "DogFarm is destroyed\n"; }
	virtual void NewAnimal() {
		Dog *pDog = new Dog;
		pDog->Speak();
	}
};

class CatFarm : public Farm {
public:
	CatFarm() { cout << "CatFarm is created\n"; }
	~CatFarm() { cout << "CatFarm is destroyed\n"; }
	virtual void NewAnimal() {
		Cat *pCat = new Cat;
	}
};

int main(void) {
	DogFarm _DogFarm;
	_DogFarm.NewAnimal();

	return 0;
}
/*
그런데 문제가 또 있습니다. 이 목장에는 동물이 100마리가 살고 있습니다. 
에구....이제 노가다를 해야되겠군요. 

개에도 추가했듯이 고양이, 소, 닭, 이렇게 추가하기 시작합니다. -_-;
그래야 모든 동물이 태어나서 울음을 터트릴테니까요.
*/