#include <iostream>
#include <string>
class Animal {
private:
	std::string name;
public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	Animal& operator+(const Animal& a) {
		name += a.name;
		return *this;
	}
};
int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName();
	getchar();
	return 0;
}
/*Operator를 member function으로 구현할 경우, 해당 operator의 인자는 1) 현재
오브젝트와 2) 직접 명시된 인자이다.하지만 현재 오브젝트(this)는 컴파일러가 가정하기
때문에 직접 명시하지 않는다.가령, 실습 4에서
Animal & operator+(const Animal & a) {
	name += a.name;
	return *this;
}
는 const Animal& a를 인자로 받지만 사실 내부적으로는 this도 함께 인자로 받는것이다.
즉, Animal& operator+(this, const Animal& a) {
	... 가 됨.
		위 예제에서 name += a.name은 결국 현재 오브젝트의 name 값을 인자 a의 name과
		합성하는 것이므로, dog 오브젝트의 name 값이 변조된다.반면, 실습 3에서는 Animal
		temp라는 임시 객체에 this.name 과 a.name이 합성된 값을 저장하고, temp를 리턴하므로,
		dog.name의 값은 원래 값을 유지한다.*/