#include<iostream>
#include<list>
using namespace std;

int main(){
    double myDoubles[]={12.15,2.72,73.0,12.77,3.14,12.77,73.35,72.25,15.3,72.25};

    list<double>myList(myDoubles,myDoubles+10);
    list<double>::iterator it;
    cout<<"nodes of myList: ";
    for(it=myList.begin();it!=myList.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"myList.push_front(1.4);"<<endl;
    myList.push_front(1.4);
    cout<<"myList.push_back(1.4);"<<endl;
    myList.push_back(1.4);
    cout<<"nodes of myList : ";
    for(it=myList.begin();it!=myList.end();++it){
        cout<<*it<<" ";
    }

    cout<<endl;
    cout<<endl;

    cout<<"myList.sort();"<<endl;
    myList.sort();
    cout<<"nodes of myList: ";
    for(it=myList.begin();it!=myList.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"myList.unique();"<<endl;
    myList.unique();
    cout<<"nodes of myList: ";
    for(it=myList.begin();it!=myList.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<endl;

    return 0;
    
}