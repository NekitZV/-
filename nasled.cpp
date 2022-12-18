#include <iostream>
#include <cmath>
using namespace std;

class Number {
    public:
    float first;
    float second;
    float sum();
    float div();
};

class Real : public Number{
    public:
    int pow1;
    Real(float First, float Second, float Pow){
        first = First;
        second = Second;
        pow1 = Pow;
    }
    float Pow();
    float Log();
};

float Number::sum(){
    cout << first << " + " << second << " = " << first + second << endl;
    return(first + second);
}

float Number::div(){
    cout << first << " / " << second << " = " << first / second << endl;
    return(first / second);
}

float Real::Pow(){
    cout << first << "^" << pow1 << " = " << pow(first, pow1) << endl;
    cout << second << "^" << pow1 << " = " << pow(second, pow1) << endl;
    return pow(first, pow1), pow(second, pow1);
}

float Real::Log(){
    cout << "log(" << first << ") = " << log(first) << endl;
    cout << "log(" << second << ") = " << log(second) << endl;
    return log(first), log(second);

}

int main(){
    float a, b, p;

    cout << "Enter first, second, and power: ";
    cin >> a >> b >> p; 

    Real r = Real(a, b, p) ;
    r.Pow();
    r.Log();
    r.sum();
    r.div();
}
