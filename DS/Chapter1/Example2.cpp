#include<iostream>
using namespace std;

bool is_vowel(char letter){
    //Precondition: letter는 대문자 혹은 소문자
    //Postcondition: letter가 모음이면 true, 자음이면 false를 반환한다.
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    is_vowel('A'); //Precondition 만족(true 출력)
    is_vowel('Z'); //Precondition 만족(false 출력)
    is_vowel('?'); //Precondition 불만족

    return 0;
}