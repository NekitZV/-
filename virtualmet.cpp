#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Array {
public:
static const int n = 16;
int array_size;
unsigned char array[n];


Array () {
    
    array_size = sizeof array / sizeof array[0];
    
    for (int counter = 0; counter < array_size; counter ++) array[counter] = '0';
}


unsigned char & operator[] (int index) {
    if (index >= 0 and index < array_size){
    	return array[index];
    }
    else cout << "error";
}

friend ostream& operator <<(ostream& out, Array& a)
{
    for(int index = 0; index < a.array_size; index++)
    {
        out << (int)a.array[index] << ",";
    }
    out << endl;
    return out;
}

int getSize(){
	return array_size;
}

virtual unsigned char summator(unsigned char b[n]) {
    for (int counter = 0; counter < array_size; counter ++) array[counter] = array[counter] + b[counter];
    return *array;
}
};

class Hex : public Array {
	unsigned char hexarr[100];

public:
virtual unsigned char summator(unsigned char b[n]) {
    for (int counter = 0; counter < 100; counter ++) hexarr[counter] = hexarr[counter] + b[counter];
    return *hexarr;
}
Hex () { 
    for (int counter = 0; counter < 100; counter ++) array[counter] = '0';
}
unsigned char & operator[] (int index) {
    if (index >= 0 and index < 100) return hexarr[index];
    else cout << "error";
}

};


class Money : public Array {
	unsigned char cop[4];
	long rubles[50];


public:
virtual unsigned char summator(unsigned char b[n]) {
    for (int counter = 0; counter < 100; counter ++) cop[counter] = cop[counter] + b[counter];
    return *cop;
}
Money () { 
    for (int counter = 0; counter < 100; counter ++) rubles[counter] = '0';
    for (int counter = 0; counter < 4; counter ++) cop[counter] = '0';
}
unsigned char & operator[] (int index) {
    if (index >= 0 and index < 100){
    	return cop[index];
    }
    else cout << "error";
}

};




int main()
{
	unsigned char aro[16];
	setlocale(LC_ALL, "Russian");
	Array ar;
	for (int i = 0; i < ar.getSize(); ++i)
	{
		cout << ar[i] << " ";
		cout << endl;
	}
	cout << "--------------" << endl;
 	//Array ar2;
	aro[5] = '5';
	aro[4] = '3';
	ar.summator(aro);
	for (int i = 0; i < ar.getSize(); ++i)
	{
		cout << ar[i] << " ";
		cout << endl;
	}

	return 0;
}
