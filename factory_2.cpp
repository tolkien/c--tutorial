/*
SimplePizzaFactory 로 분리되기 전 코드에는
피자를 만드는 코드가 PizzaStore와 연결되긴 했지만 유연하진 못했습니다.
팩토리 메소드 패턴을 이용하면 이를 해결할 수 있습니다.

factory_1.png

PizzaStore 클래스의 주문 과정은 모든 피자가게에서 동일하게 이루어진다고 할 때,
달라지는 것은 계속 말했듯이 생성입니다. PizzaStore의 서브 클래스(자식 클래스)를 만들어
그 내부에서 CreatePizza() 를 구현한다면 자식 클래스마다 다른 스타일의 피자를 생성할 수 있게됩니다.
만약 새로운 스타일의 피자를 추가 생성하고 싶다면, 클래스를 추가하면되고,
삭제하고 싶다면 클래스를 삭제하면 되는 것입니다.
*/

// PizzaStore.h
#pragma once
class Pizza;

// 피자 가게
class PizzaStore {
private:
	// 피자 생성
	virtual Pizza* CreatePizza(char* pType);
public:
	// 피자 주문
	Pizza* OrderPizza(char* pType);
};

// 뉴욕 피자 가게
class NYPizzaStore : public PizzaStore {
private:
	Pizza* CreatePizza(char* pType);
};

// 시카고 피자 가게
class ChicagoPizzaStore : public PizzaStore {
private:
	Pizza* CreatePizza(char* pType);
};

// PizzaStore.cpp
#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

using namespace std;

// 피자 가게
// 피자 생성
Pizza* PizzaStore::CreatePizza(char* pType) {
	Pizza* pizza = NULL;
	return pizza;
}

// 피자 주문
Pizza* PizzaStore::OrderPizza(char* pType) {
	Pizza* pizza = NULL;
	// 피자 주문하는 곳에서 피자를 생성하게 한다.
	pizza = CreatePizza(pType);

	// 준비
	pizza->Prepare();
	// 굽기
	pizza->Bake();
	// 자르기
	pizza->Cut();
	// 포장
	pizza->Package();

	return pizza;
}

// 뉴욕 피자가게
Pizza* NYPizzaStore::CreatePizza(char *pType) {
	Pizza* pizza - NULL;

	if(strcmp(pType,"치즈")) {
		pizza = new NYStyleCheesePizza;
	} else if(strcmp(pType,"햄")) {
		pizza = new NYStyleHamPizza;
	} else if(strcmp(pType,"조개")) {
		pizza = new NYStyleClamPizza;
	} else if(strcmp(pType,"파인애플")) {
		pizza = new NYStylePinePizza;
	} else {
		cout << "no such menu\n";
	}

	return pizza;
}

// 시카고 피자가게
Pizza* ChicagoPizzaStore::CreatePizza(char *pType) {
	Pizza* pizza - NULL;

	if(strcmp(pType,"치즈")) {
		pizza = new ChStyleCheesePizza;
	} else if(strcmp(pType,"햄")) {
		pizza = new ChStyleHamPizza;
	} else if(strcmp(pType,"조개")) {
		pizza = new ChStyleClamPizza;
	} else if(strcmp(pType,"파인애플")) {
		pizza = new ChStylePinePizza;
	} else {
		cout << "no such menu\n";
	}

	return pizza;
}
/*
OrderPizza 함수에서는 Pizza 객체를 가지고 여러 작업을 하지만
실제로 어떤 클래스에서 작업이 처리되고 있는지는 전혀 알 수가 없습니다
 이 말은 즉 PizzaStore와 Pizza클래스가 완전히 분리되있는 것을 말합니다.

NYPizzaStore에서 주문을 하면 뉴욕 스타일 피자가 만들어질 것이고,
ChicagoPizzaStore에서 주문을 하면 시카고 스타일 피자가 만들어질 것입니다.
이것이 서브 클래스에서 실시간으로 결정하는 것을 의미하진 않습니다.

NYPizzaStore를 선택했다면 OrderPizza() 함수 입장에서는
그 서브클래스에서 피자의 종류를 결정한다고 할 수 있을 것입니다.
실제로는 우리가 선택하는 PizzaStore의 서브 클래스의 종류에 따라 결정되지만,
만들어지는 피자의 종류를 해당 서브클래스 에서 결정한다고 할 수 있습니다.

모든 팩토리 패턴에서는 객체 생성을 캡슐화 합니다. 팩토리 메소드 패턴에서는
서브클래스가 어떤 클래스를 만들기 결정하게 함으로써 객체 생성을 캡슐화합니다.

factory_3.png

위 다이어그램에서 보면 PizzaStore가 있고, 그 서브클래스로 NY, Chicago가 있습니다.
또한 여러 피자 클래스들이 있습니다.
PizzaStore는 추상 클래스로 서브클래스에서 객체를 생성할 때 사용할 함수의 이름을 정의합니다.
하위 서브 클래스의 CreatePizza 함수가 팩토리 멧드 입니다. 이 함수에서 객체를 생산합니다.
각각 서브클래스가 따로 존재하기 때문에 CreatePizza 함수를 통해 다양하게 구현할 수 있습니다.

Pizza 클래스는 팩토리로 제품을 생산하는 용도로 사용됩니다.
팩토리 메소드 패턴에서는 객체를 생성하기 위한 인터페이스(위에서는 PizzaStore)를 정의하는데,
어떤 클래스의 인스턴스를 만들지는 서브 클래스(NY,Chicago PizzaStore)에서 결정하게 되고,
클래스의 인스턴스를 생성하는 일을 서브클래스에서 하게 됩니다.
*/

/*
맨 처음에 보았던 간단한 팩토리는 팩토리 메소드 패턴과 꽤 비슷하나
일회용에 불과하기때문에 유연하지 않습니다. 반면에 팩토리 메소드 패턴을 이용하면
어떤 구현을 사용할지를 서브클래스에서 결정하는 프레임워크를 만들 수 있다는 결정적인 차이가 있습니다.

팩토리 메소드 패턴은 구체적으로 어떤 클래스의 객체를 생성할지 미리 알지 못할 경우에 유용합니다.
계속 말했듯이 팩토리 메소드 패턴은 서브클래스를 추가해나가는 형태니까요.
때문에 어떤 객체를 생성할 것인지 상관없이 프로그래밍이 가능하며,
직접 생성자를 호출해 객체를 생성하는 것보다는 유연하고 확장성있는 구조입니다.

단점이라고 말하면 생성할 객체의 종류가 달라질때 마다 새로운 하위클래스를 정의해야 하므로
클래스가 많아진다는 것이 있겠 습니다.
*/

/*
추상 팩토리 패턴과 팩토리 메소드 패턴의 차이를 알아두면 좋습니다.
둘다 객체를 만드는 일을 하지만, 팩토리 메소드 패턴은 상속을 통해 객체를 만들고,
추상 팩토리 패턴은 객체 구성을 통해 만듭니다.

추상 팩토리 패턴은 새로운 것을 추가하려면 인터 페이스를 바꿔야하고,
훨씬 더 크고 복잡한 인터페이스를 가지고 있습니다.
*/