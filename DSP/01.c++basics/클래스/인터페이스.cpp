//클래스가 제공해야하는 케서드의 집합
//순수 가상 함수만으로 구성된 클래스
//클래스가 여러 인터페이스를 상속 받을 수 있음.
#include<iostream>
using namespace std;

//인터페이스 정의
class Drawable {
public:
	virtual void draw() const = 0;
	virtual ~Drawable() {}
};

//Circle 클래스: Drawable 인터페이스의 구현
class Circle : public Drawable {
public:
	void draw() const override {
		cout << "Drawing Circle" << endl;
	}
};

//Rectangle 클래스: Drawable 인터페이스 구현
class Rectangle : public Drawable {
public:
	void draw() const override {
		cout << "Drawing Rectangle" << endl;
	}
};

int main() {
	Drawable* shapes[2];
	shapes[0] = new Circle();
	shapes[1] = new Rectangle();

	for (int i = 0; i < 2; ++i) {
		shapes[i]->draw();
	}

	delete shapes[0];
	delete shapes[1];

	return 0;
}