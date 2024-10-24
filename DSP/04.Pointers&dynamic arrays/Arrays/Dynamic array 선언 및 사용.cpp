#include<iostream>
using namespace std;

int main() {
	int* arr = new int[5] {1, 2, 3, 4, 5};

	cout << "배열의 크기를 입력하세요(현재 배열의 크기는 5입니다.): ";
	int len;
	cin >> len;

	for (int i = 0; i < len; i++) { cout << arr[i] << endl; }

	delete[] arr;

	return 0;
}