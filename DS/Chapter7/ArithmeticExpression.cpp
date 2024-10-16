#include<iostream>
#include<stack>
#include<cctype>
#include<cstring>
using namespace std;

double read_and_evaluate(istream& ins){
    const char DECIMAL='.';
    const char RIGHT_PARENTHESIS=')';

    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;

    while(ins && ins.peek()!='\n'){
        if(isdigit(ins.peek())||(ins.peek()==DECIMAL)){
            ins>>number;
            numbers.push(number);
        }
        else if(strchr("+-*/",ins.peek())!=NULL){
            ins>>symbol;
            operations.push(symbol);
        }
        else if(ins.peek()==RIGHT_PARENTHESIS){
            ins.ignore();
            evaluate_stack(numbers,operations);
        }
        else{ins.ignore();}
    }
    return numbers.top();
}

void evaluate_stack(stack<double>& numbers, stack<char>& operations){
    double operand1,operand2;
    operand2=numbers.top();
    numbers.pop();
    operand1=numbers.top();
    numbers.pop();

    switch(operations.top()){
        case'+':
            numbers.push(operand1+operand2); 
            break;
        case'-':
            numbers.push(operand1-operand2); 
            break;
        case'*':
            numbers.push(operand1*operand2); 
            break;
        case'/':
            numbers.push(operand1/operand2); 
            break;
    }
    operations.pop();
}