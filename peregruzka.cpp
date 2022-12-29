#include <iostream>
#include <string>
using namespace std;
#include <windows.h>
 
class Cursor
{
private:
    int *first = new int;
    int *second = new int;
 
public:
    Cursor(int X=500, int Y=200)
    {
        *first = X;
        *second = Y;
    }
    void changex(int x)
    {
        if (x > 0 && x <= GetSystemMetrics(SM_CXSCREEN))
            *first = x;
        else
            cout << "Неверное значение, превыщающее границы." << endl;
    }
    void changey(int y)
    {
        if (y > 0 && y <= GetSystemMetrics(SM_CYSCREEN))
            *second = y;
        else
            cout << "Неверное значение, превыщающее границы." << endl;
    }
    void Display()
    {
        SetCursorPos(*first, *second);
        cout << "Значение X=" << *first << ". Значение Y=" << *second << endl;
    }
    ~Cursor()
    {
        delete first;
        delete second;
    }
};
void inputValue(int &temp)
{
 
    while (true)
    {
        cin >> temp;
        if (cin.fail() || temp<0 )
        {
            cout << "Введено некоректное значение.";
        }
        else break;
    }
}
void inputValue(char &temp)
{
    while (true)
    {
        cin >> temp;
        if (cin.fail())
        {
            cout << "Введено некоректное значение.";
        }
        else if (temp=='s' || temp=='e' || temp=='x' || temp=='y') break;
    }
}

//Перегрузка ввода и вывода
istream operator >> (istream& in, Cursor& acc)
{
    return in >> acc.number;
}

ostream operator >> (ostream& out, Cursor& acc)
{
    return out >> acc.name;
}

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int x, y;
        char choice;
        cout << "Введите X и Y координаты курсора.\n";
        inputValue(x);
        inputValue(y);
        Cursor coord(x, y);
        while (true)
        {
        cout << "Что делать дальше? s - show on display, e - edit X or Y\n";
        inputValue(choice);
        if (choice == 's')
            coord.Display();
        if (choice == 'e')
        {
            cout << "X или Y координату?\n";
            inputValue(choice);
            if (choice == 'x')
            {
                cout << "Введите новое значение.\n";
                inputValue(x);
                coord.changex(x);
            }
            if (choice == 'y')
            {
                cout << "Введите новое значение.\n";
                inputValue(y);
                coord.changey(y);
            }
        }
    }
    system("pause");
}
