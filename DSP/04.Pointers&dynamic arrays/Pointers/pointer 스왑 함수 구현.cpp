#include<iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int m = 1, n = 2;

	cout << "스왑 이전 m,n-> " << m << ", " << n << endl;
	swap(&m, &n);
	cout << "스왑 이후 m,m-> " << m << ", " << n << endl;

	return 0;
}