using namespace std;

class Cursor {
private:
    int gor;
    int ver;
    string vid;
    int ras;


public:
    Cursor();
    Cursor(const Cursor&);
    Cursor(int, int, string, int);
    void Read();
    void Ismen_Coordinat(int, int);
    void Ismen_Vida(string);
    void Ismen_Rasmera(int);
    void Obnul();
    void Vostanovit(const Cursor&);
    void Otchet();
    friend ostream& operator<<(ostream&, const Cursor&);
    friend istream& operator>>(istream&, Cursor&);
    friend Cursor operator+ (const Cursor&, const Cursor&);
    friend Cursor operator- (const Cursor&, const Cursor&);
    string toString();
};

Cursor::Cursor() :
    gor(100), ver(100), vid("horizontal"), ras(5) {};


Cursor::Cursor(int _gor, int _ver, string _vid, int _ras) :
    gor(_gor), ver(_ver), vid(_vid), ras(_ras) {};

Cursor::Cursor(const Cursor& _q) :
    gor(_q.gor), ver(_q.ver), vid(_q.vid), ras(_q.ras) {};

void Cursor::Ismen_Coordinat(const int _gor, const int _ver) {
    gor = _gor;
    ver = _ver;
};

void Cursor::Read() {
    cout << "Ent horizontal" << endl;
    cin >> gor;
    cout << "Ent vertical" << endl;
    cin >> ver;
    cout << "Ent exterior" << endl;
    cin >> vid;
    cout << "Ent size" << endl;
    int _ras;
    cin >> _ras;
    if ((ras <= 15) && (ras >= 1)) {
        ras = _ras;
    }
    else {
        cout << "Error. BZ=5" << endl;
        ras = 5;
    }
}

void Cursor::Ismen_Vida(const string _vid) {
    vid = _vid;
};

void Cursor::Ismen_Rasmera(const int _ras) {
    if ((_ras <= 15) && (_ras >= 1)) {
        ras = _ras;
    }
    else {
        cout << "Error" << endl;
    }
};

void Cursor::Obnul() {
    gor = 100;
    ver = 100;
    vid = "horizontal";
    ras = 5;
};


void Cursor::Vostanovit(const Cursor& _q) {
    gor = _q.gor;
    ver = _q.ver;
    vid = _q.vid;
    ras = _q.ras;
};

void Cursor::Otchet() {
    cout << "horizontal=" << gor << endl;
    cout << "vertical=" << ver << endl;
    cout << "exterior - " << vid << endl;
    cout << "size=" << ras << endl;
};

ostream& operator<<(ostream& cout, const Cursor& q) {
    cout << "horizontal=" << q.gor << endl;
    cout << "vertical=" << q.ver << endl;
    cout << "exterior=" << q.vid << endl;
    cout << "size=" << q.ras << endl;
    return cout;
};

istream& operator>>(istream& cin, Cursor& q) {
    cin >> q.gor;
    cin >> q.ver;
    cin >> q.vid;
    cin >> q.ras;
    return cin;
};

string Cursor::toString() {
    char str[80];
    sprintf(str, "%d %d %s %d", gor, ver, vid.c_str(), ras);
    return str;
};

Cursor operator+ (const Cursor& a1, const Cursor& a2) {
    if (a1.ras + a2.ras > 15) { cout << "Error"; return a1; }
    Cursor a((a1.gor + a2.gor), (a1.ver + a2.ver), "Gor", (a1.ras + a2.ras));
    return a;
}
Cursor operator- (const Cursor& a1, const Cursor& a2) {
    if (a1.ras - a2.ras < 1) { cout << "Error"; return a1; }
    Cursor a((a1.gor - a2.gor), (a1.ver - a2.ver), "Gor", (a1.ras - a2.ras));
    return a;
}

int main()
{
    Cursor q, copq;
    q.Read();
    copq = Cursor(q);
    int x, y;
    cout << "Enter new number of a horizontal" << endl;
    cin >> x;
    cout << "Enter new number of a vertical" << endl;
    cin >> y;
    q.Ismen_Coordinat(x, y);
    copq = Cursor(q);
    string z;
    cout << "Enter new appearance" << endl;
    cin >> z;
    q.Ismen_Vida(z);
    copq = Cursor(q);
    cout << "Enter new size" << endl;
    cin >> x;
    q.Ismen_Rasmera(x);
    copq = Cursor(q);
    q.Obnul();
    q.Vostanovit(copq);
    q.Otchet();
    return 0;
}