#include<iostream>
#include<stack>
#include<string>
using namespace std;

string infixToPostfixFullyParenthesized(const string& expr){
    string postfix = "";
    stack<char> operations;

    for(int i=0; i<expr.length(); i++){
        char c = expr[i];

        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            operations.push(c);
        }
        else if(c==')'){
            char op = operations.top();
            operations.pop();
            postfix +=op;
            if(!operations.empty()){
                operations.pop();
            }
        }
        else{
            operations.push(c);
        }
}