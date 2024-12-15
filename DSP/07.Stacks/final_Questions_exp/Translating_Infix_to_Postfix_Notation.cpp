#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& expr){
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
            while(!operations.empty() && operations.top()!='('){
                postfix += operations.top();
                operations.pop();
            }
            operations.pop();
        }
        else{
            while(!operations.empty() && precedence(operations.top())>=precedence(c)){
                postfix += operations.top();
                operations.pop();
            }
            operations.push(c);
        }
    }
    while(!operations.empty()){
        postfix += operations.top();
        operations.pop();
    }
    return postfix;
}

int main(){
    string expr = "A+B*C-D/E";
    string postfix = infixToPostfix(expr);
    cout<<"Infix: "<<expr<<endl;
    cout<<"Postfix: "<<postfix<<endl;

    return 0;
}