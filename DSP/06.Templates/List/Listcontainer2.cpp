#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include "MyStudent.h"
using namespace std;
using namespace mystudent;

int main(){
    list<Student> stuList;
    while(1){
        string input;

        cout<<"<< ID (input \'q\' to terminate): ";
        cin>>input;

        if(input.compare("q")==0){
            cout<<">> Terminate input."<<endl;
            break;
        }

        int id=stoi(input);
        string name="";
        cout<<"<<Name: ";
        cin>>name;
        double score=-1.0;
        cout<<"<<Score: ";
        cin>>score;
        Student stu(id,name,score);
        stuList.push_back(stu);
        cout<<">> Successfully added to list!"<<endl;
    }

    ofstream fout("StudentList.txt", ios_base::out);
    list<Student>::iterator iter;
    for(iter=stuList.begin(); iter!=stuList.end();++iter){
        fout<<(*iter).getID()<<endl;
        fout<<(*iter).getName()<<endl;
        fout<<(*iter).getScore()<<endl;
    }

    fout.close();

    cout<<">> "<<stuList.size()<<" student's info was successfully saved." <<endl;
    return 0;
}