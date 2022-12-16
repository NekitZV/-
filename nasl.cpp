#include <iostream>
#include <cmath>
using namespace std;

class Pair {
    public:
    float first = 1 + rand() % 10;
    float second = 1 + rand() % 10;
    float sum();
    float div();
};

class Money : Number{
    public:
    int pow1;
    float Pow();
    float Log();
};

float Pair::sum(){
    cout << first << " + " << second << " = " << first + second << endl;
    return(first + second);
}

float Pair::div(){
    cout << first << " / " << second << " = " << first / second << endl;
    return(first / second);
}

float Money::Pow(){
    int rand1 = 1 + rand() % 15;
    cout << first << "^" << rand1 << " = " << pow(first, rand1) << endl;
    cout << second << "^" << rand1 << " = " << pow(second, rand1) << endl;
    return pow(first, rand1), pow(second, rand1);
}

float Money::Log(){
    cout << "log(" << first << ") = " << log(first) << endl;
    cout << "log(" << second << ") = " << log(second) << endl;
    return log(first), log(second);

}

int main(){
    Pair p;
    Money m;
    m.Pow();
    m.Log();
    p.sum();
    p.div();
}
