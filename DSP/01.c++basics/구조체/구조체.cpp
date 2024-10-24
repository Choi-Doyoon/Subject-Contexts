#include<iostream>
#include<string>
using namespace std;

struct Person{
    string name;
    int age;
    double height;
};

//구조체의 초기화
Person person1={"Alice",29,174};

int main(){
    //구조체 데이터 접근
    person1.name="Alice";
    person1.age=30;
    person1.height=5.6;

    cout<<person1.name<<endl;
    cout<<person1.age<<endl;
    cout<<person1.height<<endl;

    //구조체 포인터 연산자(구조체 포인터로 구조체 멤버를 참조 할 떄 "->"연산자를 사용)
    Person person2={"Alice",30,174};
    Person* ptr=&person2;
    cout<<(*ptr).name<<endl;
    cout<<ptr->name<<endl;
    //27행과 28번행은 똑같은 의미이다.
}