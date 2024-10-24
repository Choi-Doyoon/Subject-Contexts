#include<cassert> //assert문 때문에 포함
#include<iostream>
#include<cmath>
using namespace std;

void write_sqrt(double x){
    //Precondition: x >= 0
    //Pstcondition: The square root of x has been written to the standard output.
    assert(x>=0);
    cout << "The square root of " << x << " is " << sqrt(x) << endl;
}

int main(){
    double x;
    write_sqrt(-10.0); //Preconditioden 불만족
    write_sqrt(0); //Precondition 만족
    write_sqrt(5.6); //Precondition 만족

    return 0;
}