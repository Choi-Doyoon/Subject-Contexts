#ifndef USEFUL_H
#define USEFUL_H
#include<iostream>
#include<cassert>
#include<cctype>
#include<cstdlib>
using namespace std;

namespace useful{
    void display(double x){
        const char STAR='*';
        const char BLANK=' ';
        const char VERTICAL_BAR='|';
        const int LIMIT=39;
        int i;

        if(x<-LIMIT){
            x=-LIMIT;
        }
        else if(x>LIMIT){
            x=LIMIT;
        }
        for(i=-LIMIT;i<0;i++){
            if(i>=x){cout<<STAR;}
            else{cout<<BLANK;}
        }
        cout<<VERTICAL_BAR;
        for(i=1;i<=LIMIT;i++){
            if(i<=x){cout<<STAR;}
            else{cout<<BLANK;}
        }
        cout<<endl;
    }

    void eat_line(){
        char next;
        do{
            cin.get(next);
        } while(next != '\n');
    }

    bool inquire(const char query[]){
        char answer;

        do{
            cout<<query<<" [ Yes or No]"<<endl;
            cin>>answer;
            answer=toupper(answer);
            eat_line();
        } while((answer!='Y')&&(answer!='N'));
        return (answer=='Y');
    }

    double random_fraction(){return rand()/double(RAND_MAX);}

    double random_real(double low,double high){
        assert(low<=high);
        return low+random_fraction()*(high-low);
    }
}
#endif