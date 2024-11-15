#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

//랜덤 실수 생성 함수
double random_real(double min_val, double max_val){
    return min_val+(max_val-min_val)*(double(rand())/RAND_MAX);
}

//프렉탈을 재귀적으로 생성하는 함수
void random_fractal(double left_height, double right_height, double width, double epsilon){
    double mid_height;

    if(width<=epsilon){
        cout<<"display("<<right_height<<") ";
        if(right_height>=0){
            cout<<"|";
            for(int i=0; i<int(right_height);++i){
                cout<<"*";
            }
            cout<<endl;
        }
        else{
            cout<<"* |"<<endl; //음수 높이의 경우 출력
        }
    }
    else{
        mid_height = (left_height+right_height)/2;
        mid_height += random_real(-width,width);

        random_fractal(left_height,mid_height, width/2,epsilon);
        random_fractal(mid_height,right_height,width/2,epsilon);
    }
}

int main(){
    srand(time(0)); //랜덤 시드 초기화

    double left_height = 8.0;
    double right_height = 5.0;
    double width = 10.0;
    double epsilon = 1.0;

    random_fractal(left_height,right_height,width,epsilon);

    return 0;
}