#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){
    int num;
    vector<int> v1;
    cout << "Enter vector elements (press any letter key to stop)" << endl;
    while(cin >> num){ v1.push_back(num); }
    reverse(v1.begin(), v1.end());
    for(auto x : v1){ cout << x << " ";}

}