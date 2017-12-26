/*
모든 동물이 농장에서만 태어난다고 하면,
농장을 만들어야 개가 만들어지고 고양이가 만들어 지겠죠?

이제 클라이언트에서 Dog.NewAnimal()만 해주면 다 될것 같습니다.
하지만 이 그림은 객체가 많아 질 경우 안 좋은 점들이 생깁니다.
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