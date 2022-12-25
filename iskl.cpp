#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Prog1 {};

class Prog2 {
    string msg;
public:
    Prog2(const string& s) : msg(s) {}
    const char* message() const { return msg.c_str(); }
};

class Prog3 : public invalid_argument {
    double num;
public:
    Prog3(const string msg, double n) : invalid_argument(msg), num(n) {}
    double arg() const { return num; }
};

double root1(double a, double b) {
    return -b / a;
}

double root2(double a, double b) throw() {
    return -b / a;
}

double root3(double a, double b) throw(invalid_argument) {
    if (a == 0.0)
        throw invalid_argument("delenie on 0");
    return -b / a;
}

double root4_1(double a, double b) throw(Prog1) {
    if (a == 0.0)
        throw Prog1();
    return -b / a;
}

double root4_2(double a, double b) throw(Prog2) {
    if (a == 0.0)
        throw Prog2("delenie on 0");
    return -b / a;
}

double root4_3(double a, double b) throw(Prog3) {
    if (a == 0.0)
        throw Prog3("Wrong argument", a);
    return -b / a;
}

void launcher(double (*func)(double, double)) {
    double a, b;
    cout << "Vvedite a=";
    cin >> a;
    cout << "Vvedite b=";
    cin >> b;
    cout << "koren lin uravnenia: " << func(a, b) << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "found koren ax+b=0\n";

    try {
        launcher(root1);
    }
    catch (...) {
        cout << "iskluchenie in root1" << endl;
    }

    try {
        launcher(root2);
    }
    catch (...) {
        cout << "iskluchenie in root2" << endl;
    }

    try {
        launcher(root3);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        launcher(root4_1);
    }
    catch (Prog1) {
        cout << "iskluchenie Prog1 in root4_1" << endl;
    }

    try {
        launcher(root4_2);
    }
    catch (Prog2& e) {
        cout << e.message() << endl;
    }

    try {
        launcher(root4_3);
    }
    catch (Prog3& e) {
        cout << e.what() << " " << e.arg() << endl;
    }
}
