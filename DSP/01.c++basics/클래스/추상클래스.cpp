#include<iostream>
using namespace std;

//추상 클래스(하나 이상의 순수 가상 함수를 가진 클래스)
class Shape {
public:
	//순수 가상 함수
	virtual void draw() const = 0;
	//소멸자 생성
	virtual ~Shape() {
		cout << "Shape destructor" << endl;
	}
};

class Circle : public Shape {
public:
	void draw() const override {
		cout << "Drawing Circle" << endl;
	}
	//소멸자 생성
	~Circle() {
		cout << "Circle destructor" << endl;
	}
};

int main() {
	//Shape shape; //Error: cannot instantiate abstract class
	Shape* shape = new Circle();
	shape->draw();
	
	delete shape;
	return 0;
}