/*
팩토리 패턴은 대표적인 생성 패턴중 하나로 느슨한 결합을 이용한 디자인입니다.

객체의 인스턴스를 만드는 작업이 항상 공개되어있어야 하는 것은 아니며,
공개를 할 때 객체간 결합의 문제가 발생할 수도 있습 니다. 팩토리 패턴을 이용해 불필요한 의존성을 없앨 수 있습니다.
구조를 설계할 때 인터페이스에 맞춰서 코딩하면 변화에 열려있는 코드가 됩니다.
패턴에서 가장 중요한 것중 하나는 캡슐화라는 개념으로 바뀌는 부분과 바뀌지 않는 부분을 분리하고,
바뀌는 부분을 묶어두는 것입니다.

팩토리에서의 캡슐화는 생성을 묶어놓습니다.
*/

/* Simple Factory */
Pizza OrderPizza(char* pType) {
	Pizza m_pizza;

	// 피자 생성
	if(strcmp(pType,"치즈")) {
		m_pizza = new CheesePizza();
	} else if(strcmp(pType,"햄")) {
		m_pizza = new HamPizza();
	} else if(strcmp(pType,"파인애플")) {
		m_pizza = new PinePizza();
	}
	// 준비
	m_pizza.Prepare();
	// 굽기
	m_pizza.Bake();
	// 자르기
	m_pizza.Cut();
	// 포장
	m_pizza.Package();

	return m_pizza;
}

/*
위 코드에서 피자 생성부분을 보겠습니다.
메뉴를 추가하거나 삭제할 때 이 부분이 주로 변경되고, 그 외의 부분은 변경되지 않습니다.
변경되는 부분과 변경되지 않는 부분을 알았으니 변경되는 부분을 캡슐화 해보겠습니다.
*/

class SimplePizzaFactory {
public:
	Pizza CreatePizza(char* pType) {
		Pizza m_pizza;

		// 피자 생성
		if(strcmp(pType,"치즈")) {
			m_pizza = new CheesePizza();
		} else if(strcmp(pType,"햄")) {
			m_pizza = new HamPizza();
		} else if(strcmp(pType,"파인애플")) {
			m_pizza = new PinePizza();
		}
		return m_pizza;
	}
};

class PizzaStore {
private:
	SimplePizzaFactory factory;

public:
	PizzaStore(SimplePizzaFactory _factory) {
		factory = _factory;
	}

	Pizza OrderPizza(char* pType) {
		Pizza m_pizza;

		// 피자 생성
		m_pizza = factory.CreatePizza(pType);

		// 준비
		m_pizza.Prepare();
		// 굽기
		m_pizza.Bake();
		// 자르기
		m_pizza.Cut();
		// 포장
		m_pizza.Package();

		return m_pizza;
	}
};

/*
SimplePizzaFactory 클래스에서 하는 일은 피자를 생성하는 일 뿐입니다.
이렇게 피자를 생성하는 작업을 한 클래스에 캡슐화 시켜놓으면
어떤 구현을 변경해야 하는경우 이 팩토리 클래스만 변경하면 되기 때문에
보다 변화에 열려있는 코드가 됩니다.
PizzaStore 클래스를 보면 생성자에 팩토리 객체 전체가 전달됩니다.
생성 부분에서는 그냥 팩토리를 써서 피자 객체를 만드는 것을 볼 수 있습니다.
new 연산자 대신 팩토리 객체에 있는 CreatePizza 함수를 사용했기 때문에
인스턴스를 만들 필요가 없습니다.
지금까지 보신 것은 간단한 팩토리로 이는 디자인 패턴이라고 할 수는 없습니다.
하지만 팩토리 패턴에 대한 이해를 위해 짚고 넘 어가는 것이 좋습니다.
*/