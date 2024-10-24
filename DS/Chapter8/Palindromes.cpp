#include<queue>
#include<stack>
#include<cctype>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
    queue<char> q;
    stack<char> s;
    char letter;
    queue<char>::size_type mismatches=0;
    cout<<"Enter a line and I will see if it's a palindrome: "<<endl;

    while(cin.peek()!='\n'){
        cin>>letter;
        if(isalpha(letter)){
            q.push(toupper(letter));
            s.push(toupper(letter));
        }
    }

    while((!q.empty()) && (!s.empty())){
        if(q.front()!=s.top()){
            ++mismatches;
        }
        q.pop();
        s.pop();
    }

    if(mismatches == 0){
        cout<<"That is a palindrome."<<endl;
    }
    else{
        cout<<"That is not a palindrome."<<endl;
    }
    return EXIT_SUCCESS;
}