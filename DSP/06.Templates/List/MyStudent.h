#ifndef MyStudent_H
#pragma once
#include<string>
#include<string.h>
#include<iostream>

#define MAX_NAME_LEN 32
using namespace std;

namespace mystudent{
    class Student{
    public:
    Student(){
        this->id=-1;
        memset(this->name,0x00,MAX_NAME_LEN+1);
        this->score=-1.0;
    }

    Student(int id, string name, double score){
        this->id=id;
        memcpy(this->name,name.c_str(),MAX_NAME_LEN);
        this->score=score;
    }

    void setID(int id){this->id=id;}
    void setName(string name){
        memcpy(this->name,name.c_str(),MAX_NAME_LEN);
    }
    void setScore(double score){this->score=score;}

    int getID(void){return this->id;}
    string getName(void){return string(this->name);}
    double getScore(void){return this->score;}

    private:
    int id;
    char name[MAX_NAME_LEN+1];
    double score;
};
}
#endif