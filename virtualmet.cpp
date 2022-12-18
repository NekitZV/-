#include <iostream>
#include <sstream>
using namespace std;

class Money
{
    long roubles;
    unsigned int copecks;
    float wholeSum;
    void splitUp()
    {
        roubles = (int)wholeSum;
        copecks = (int)((wholeSum - (int)wholeSum) * 100);
    };
public:
    void get()
    {
        cin >> wholeSum;
        splitUp();
    };
    string show()
    {
        stringstream out;
        string str;
        out << roubles << ",";
        if (copecks < 10)
        {
            out << "0";
        }
        out << copecks;
        str = out.str();
        return str;
    };
    Money operator+ (Money arg)
    {
        Money temp;
        temp.wholeSum = this->wholeSum + arg.wholeSum;
        temp.splitUp();
        return temp;
    };
    Money operator- (Money arg)
    {
        Money temp;
        temp.wholeSum = this->wholeSum - arg.wholeSum;
        temp.splitUp();
        return temp;
    };
    float operator/ (Money arg)
    {
        float temp;
        temp = this->wholeSum / arg.wholeSum;
        return temp;
    };
    Money operator/ (float arg)
    {
        Money temp;
        temp.wholeSum = this->wholeSum / arg;
        temp.splitUp();
        return temp;
    };
    Money operator* (float arg)
    {
        Money temp;
        temp.wholeSum = this->wholeSum * arg;
        temp.splitUp();
        return temp;
    };
    bool operator== (Money arg)
    {
        return (this->wholeSum == arg.wholeSum);
    };
    bool operator!= (Money arg)
    {
        return (this->wholeSum != arg.wholeSum);
    };
    bool operator> (Money arg)
    {
        return (this->wholeSum > arg.wholeSum);
    };
    bool operator< (Money arg)
    {
        return (this->wholeSum < arg.wholeSum);
    };
    bool operator>= (Money arg)
    {
        return (this->wholeSum >= arg.wholeSum);
    };
    bool operator<= (Money arg)
    {
        return (this->wholeSum <= arg.wholeSum);
    };
};
