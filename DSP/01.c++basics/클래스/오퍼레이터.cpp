#include<iostream>
using namespace std;

class Complex{
    private:
    float real;
    float imag;
    public:
    Complex(float r=0,float i=0):real(r), imag(i) {}
    Complex operator + (const Complex& obj){
        return Complex(real+obj.real, imag+obj.imag);
    }
    void display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

int main(){
    Complex c1(1.1,2.2), c2(3.3,4.4);
    Complex c3=c1+c2;
    c3.display(); //4.4+6.6i
    return 0;
}