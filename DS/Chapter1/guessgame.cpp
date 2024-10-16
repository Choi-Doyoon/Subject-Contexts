#include<cassert>
#include<iostream>
using namespace std;

void guess_game(int n){
    int guess;
    char answer;
    assert(n >= 1);
    cout<<"Think of a whole number from 1 to "<<n<<"."<<endl;
    answer='N';
    for(guess=n;(guess>0)&&(answer!='Y')&&(answer!='y');--guess){
        		cout << "Is your number " << guess << "?" << endl;
		cout << "Please answer Y or N, and press return: ";
		cin >> answer;
	}
	if ((answer == 'Y') || (answer == 'y'))
	{
		cout << "I knew it all along." << endl;
	}
	else //1부터 n까지 전부 no이면 출력
	{
		cout << "I think you are cheating!" << endl;
	}
}
int main()
{
	int n; //정수 n 선언
	cout << "Insert a number about n: ";
	cin >> n; //n 입력
	guess_game(n); //void문 실행
}