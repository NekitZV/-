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

class Cursor
{
private:
  int x;
  int y;
  int size;
  char shape;

public:
  Cursor(int x_coord, int y_coord, int size_cursor, char shape_cursor)
    : x(x_coord), y(y_coord), size(size_cursor), shape(shape_cursor)
  {
  }

  void setShape(char shape_cursor)
  {
    shape = shape_cursor;
  }

  void setCoords(int x_coord, int y_coord)
  {
    x = x_coord;
    y = y_coord;
  }

  void setSize(int size_cursor)
  {
    if (size_cursor >= 1 && size_cursor <= 15)
      size = size_cursor;
  }
};
