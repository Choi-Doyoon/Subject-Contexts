#include<iostream>
using namespace std;

int main() {
	int* arr = new int[5] {1, 2, 3, 4, 5};

	int error_size = sizeof(arr) / sizeof(*arr); //data 영역에 저장된 변수의 사이즈
	int arr_size = _msize(arr) / sizeof(*arr); //heap 영역에 저장된 변수의 사이즈

	cout << "sizeof를 이용한 틀린 배열의 사이즈: " << error_size << endl;
	cout << "_msize를 이용한 올바른 배열의 사이즈: " << arr_size << endl;

	delete[] arr;
	return 0;
}