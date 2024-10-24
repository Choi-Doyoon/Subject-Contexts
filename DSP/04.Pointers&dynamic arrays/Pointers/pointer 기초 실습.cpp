#include<iostream>
using namespace std;

int main() {
	int a = 7;

	int* ptr = &a;
	cout << "a의 값: " << a << endl;
	cout << "포인터가 가리키는 데이터: " << *ptr << endl;
	cout << "포인터 변수의 값: " << ptr << endl;

	*ptr = 20;
	cout << "포인터가 가리키는 데이터가 변경됨: " << *ptr << endl;
	cout << "포인터 변수의 값은 동일: " << ptr << endl;

	int b = 27;
	ptr = &b;
	cout << "포인터가 가리키는 변수가 변경: " << *ptr << endl;
	cout << "포인터가 가리키는 변수가 변경->데이터의 주소 값도 변경: " << ptr << endl;
	return 0;
}