#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>
#include <stdexcept>
using namespace std;

template <typename T>
class dnode {
public:
    T data;          
    dnode* next;
    dnode* prev;  

    dnode(T value) : data(value), next(nullptr), prev(nullptr) {}
};

//Implement a ourDeque class template using a doubly-linked list(40 points)
template<typename T>
class ourDeque{
private:
    dnode<T>* head;
    dnode<T>* tail;
    int dequesize;
public:
    //constructor
    ourDeque() : head(nullptr), tail(nullptr), dequesize(0) {}

    //copy constructor
    ourDeque(const ourDeque& other) : head(nullptr), tail(nullptr), dequesize(0) {
        dnode<T>* current = other.head;
        while(current){
            push_back(current->data);
            current = current->next;
        }
    }

    //destructor
    ~ourDeque(){
        while(!empty()){
            pop_front();
        }
    }

    void push_back(T value){
        dnode<T>* newNode = new dnode<T>(value);
        if(tail){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else{
            head = tail = newNode;
        }
        dequesize++;
    }

    void push_front(T value){
        dnode<T>* newNode = new dnode<T>(value);
        if(head){
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else{
            head = tail = newNode;
        }
        dequesize++;
    }

    T pop_back(){
        if(tail){
            dnode<T>* temp = tail;
            tail = tail->prev;
            if(tail){
                tail->next = nullptr;
            }
            else{
                head = nullptr;
            }
            delete temp;
            
            dequesize--;
        }
        return 0;
    }

    T pop_front(){
        if(head){
            dnode<T>* temp = head;
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
            else{
                tail = nullptr;
            }
            delete temp;
            dequesize--;
        }
        return 0;
    }

    bool empty() const{ return dequesize == 0;}
    int size() const{ return dequesize;}

    ourDeque<T>& operator =(const ourDeque<T>& other){
        if(this != &other){
            while(!empty()){
                pop_front();
            }
            dnode<T>* current = other.head;
            while(current){
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    T front() const{return head ? head->data : throw runtime_error("Deque is empty");}
    T back() const{return tail ? tail->data : throw runtime_error("Deque is empty");}
};

//Implement a class evaluator that reads an infix expression from the user, converts it to a postfix expression, and evaluates the postfix expression(45 points)
class evaluator {
public:
    string read_expression() {
        cout << "Enter an infix expression: ";
        string expression;
        getline(cin, expression);
        return expression;
    }

    string convert_to_postfix(const string& infix) {
        string postfix;
        ourDeque<char> operators;

        for (size_t i = 0; i < infix.length(); ++i) {
            char token = infix[i];

            if (isdigit(token) || token == '.') {
                postfix += token;
                while (i + 1 < infix.length() && (isdigit(infix[i + 1]) || infix[i + 1] == '.')) {
                    postfix += infix[++i];
                }
                postfix += " ";
            } 
            else if (isalpha(token)) {
                postfix += token;
                postfix += " ";
            } 
            else if (token == '(') {
                operators.push_back(token);
            } 
            else if (token == ')') {
                while (!operators.empty() && operators.back() != '(') {
                    postfix += operators.back();
                    postfix += " ";
                    operators.pop_back();
                }
                operators.pop_back();
            } 
            else {
                while (!operators.empty() && precedence(operators.back()) >= precedence(token)) {
                    postfix += operators.back();
                    postfix += " ";
                    operators.pop_back();
                }
                operators.push_back(token);
            }
        }

        while (!operators.empty()) {
            postfix += operators.back();
            postfix += " ";
            operators.pop_back();
        }

        return postfix;
    }

    double evaluate_postfix(const string& postfix) {
        ourDeque<double> operands;
        istringstream iss(postfix);
        string token;
        map<string, double> variables;

        while (iss >> token) {
            if (isdigit(token[0]) || (token[0] == '.' && token.size() > 1)) {
                operands.push_back(stod(token));
            } 
            else if (isalpha(token[0])) {
                if (variables.find(token) == variables.end()) {
                    cout << "Enter value for " << token << ": ";
                    double value;
                    cin >> value;
                    variables[token] = value;
                }
                operands.push_back(variables[token]);
            } 
            else {
                double right = operands.back(); operands.pop_back();
                double left = operands.back(); operands.pop_back();
                operands.push_back(apply_operator(left, right, token[0]));
            }
        }

        return operands.back();
    }

private:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    double apply_operator(double left, double right, char op) {
        switch (op) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return left / right;
            default: throw runtime_error("Invalid operator");
        }
    }
};

//main function(15 points)
int main() {
    evaluator evaluator;
    string choice;

    do {
        string infix = evaluator.read_expression();
        string postfix = evaluator.convert_to_postfix(infix);
        double result = evaluator.evaluate_postfix(postfix);

        cout << "Infix expression: " << infix << endl;
        cout << "Postfix expression: " << postfix << endl;
        cout << "Evaluation result: " << result << endl;

        cout << "Do you want to evaluate another expression? (yes/no): ";
        cin >> choice;
        cin.ignore();
    } while (choice == "yes");

    return 0;
}