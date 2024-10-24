#include<iostream>
using namespace std;

class Animal {
public:
	virtual void makeSound() const {
		cout << "Animal sound" << endl;
	}
};

class Dog : public Animal {
public:
	void makeSound() const override{
		cout << "Woof" << endl;
	}
};

int main() {
	Animal* animal = new Dog();
	animal->makeSound();
	delete animal;
	return 0;
}