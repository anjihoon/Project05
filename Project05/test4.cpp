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
/*Operator�� member function���� ������ ���, �ش� operator�� ���ڴ� 1) ����
������Ʈ�� 2) ���� ��õ� �����̴�.������ ���� ������Ʈ(this)�� �����Ϸ��� �����ϱ�
������ ���� ������� �ʴ´�.����, �ǽ� 4����
Animal & operator+(const Animal & a) {
	name += a.name;
	return *this;
}
�� const Animal& a�� ���ڷ� ������ ��� ���������δ� this�� �Բ� ���ڷ� �޴°��̴�.
��, Animal& operator+(this, const Animal& a) {
	... �� ��.
		�� �������� name += a.name�� �ᱹ ���� ������Ʈ�� name ���� ���� a�� name��
		�ռ��ϴ� ���̹Ƿ�, dog ������Ʈ�� name ���� �����ȴ�.�ݸ�, �ǽ� 3������ Animal
		temp��� �ӽ� ��ü�� this.name �� a.name�� �ռ��� ���� �����ϰ�, temp�� �����ϹǷ�,
		dog.name�� ���� ���� ���� �����Ѵ�.*/