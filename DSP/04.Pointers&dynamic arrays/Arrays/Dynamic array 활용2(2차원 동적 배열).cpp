#include<iostream>
using namespace std;
int main() {
	int c, r;
	cout << "n*n 배열의 크기를 입력하세요: ";
	cin >> r >> c;

	int** mat;
	mat = new int* [r];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = i * c + j;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < r; i++) { delete[] mat[i]; }
	delete[] mat;
	return 0;
}