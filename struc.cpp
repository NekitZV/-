#include <iostream>
#include <string>
using namespace std;
 
class Account 
{ 
private: 
    string name; 
    int number; 
    int summa; 
    int percent;  
public:
    void Read(); 
    void Display();  
    void Change_Owner();
    void Withdraw();
    void Deposit();
    void Percent(); 
    void Exchange(); 
    void In_Words();
}; 
 
void Account::Read() 
{ 
    cout << "Enter the Last Name: " << endl; 
    cin >> name; 
    cout << "Enter the bank account number: " << endl; 
    cin >> number; 
    cout << "Enter the amount: " << endl; 
    cin >> summa; 
    cout << "Enter the percent: " << endl; 
    cin >> percent; 
} 
 
void Account::Display() 
{ 
    cout << "Last Name: " << name  << endl; 
    cout << "Bank account number: " << number << endl; 
    cout << "Balance: " << summa << endl; 
    cout << "Percent: " << percent << endl; 
}  
 
void Account::Change_Owner() 
{
    cout << "Enter the last name of the new owner: " << endl; 
    cin >> name; 
} 
 
void Account::Withdraw() 
{   
    int s;
    cout << "Enter the amount you would like to withdraw " << endl; 
    cin >> s; 
 
    if( s > summa) 
        cout << "Insufficient funds " << endl; 
    else 
    { 
        summa -= s; 
        cout << "Remaining amount: " << summa << endl; 
    } 
} 
 
void Account::Deposit() 
{   
    int s;
    cout << "Enter the amount you would like to deposit: " << endl; 
    cin >> s; 
 
    summa += s; 
    cout << "Balance: " << summa  << endl;
} 
 
void Account::Percent() 
{ 
    cout << "Interest accured " << endl; 
    cout << "The interest on your deposit is equal to: " << percent << endl;  
    summa = summa + ((summa*percent) / 100); 
    cout << "The amount after interest is equal to: " << endl; 
    cout << summa  << endl;
} 
 
void Account::Exchange() 
{   
    int number;
    cout << "Which currence you would like to exchange to: " << endl; 
    cout << "1) USD " << endl; 
    cout << "2) EUR " << endl;  
    cin >> number;  
    if(number == 1) 
        cout << summa << "RUB = " << summa / 62 << "USD" << endl;  
    else if(number == 2) 
        cout << summa << "RUB = " << summa / 66 << "EUR" << endl;  
    else 
        cout << "Incorrect Input "<< endl;
 
} 
 
char* numeral(int n, size_t size, char* buf) 
{ 
    char *one[] = {"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ",
                  "ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ",
                  "sixteen ","seventeen ","eighteen ","nineteen " };
    char *ten[] = {"","", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", 
                  "eighty ", "ninety " };
    
    buf = new char[size];
    sprintf(buf, "%u", n);
    int len = strlen(buf);
    int temp, temp2;
    switch(len)
    {
        case 1:
            cout << one[n];
            break;
        case 2:
            if(n < 20)
            {
                cout << one[n];
            }
            else if(n < 100)
            {
                if((n%10)==0) cout << ten[n/10];
                else cout << ten[n/10] << one[n%10];
            }
            break;
        case 3:
            temp = n/100;
            n -= (n/100)*100;
            if(n < 20)
            {
                cout << one[temp] << "hundred " << one[n];
                
            }
            else if(n < 100)
            {
                if((n%10)==0) cout << one[temp] << "hundred " << ten[n/10];
                else cout << one[temp] << "hundred " << ten[n/10] << one[n%10];
            }
            break;
        case 4:
            temp = n/1000;
            n -= (n/1000)*1000;
            cout <<  one[temp] << "thousand ";
            temp = n/100;
            n -= (n/100)*100;
            if(n < 20)
            {
                cout << one[temp] <<  "hundred ";
                cout << one[n];
            }
            else if(n < 100)
            {
                if((n%10)==0){
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                }
                else {
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                    cout << one[n%10];
                }
            }
            break;
        case 5:
            temp = n/1000;
            n -= (n/1000)*1000;
            if(temp<20){
                cout << one[temp] << "thousand ";
            }
            else if(temp < 100)
            {
                if((temp%10)==0) cout << ten[temp/10] << "thousand ";
                else cout << ten[temp/10] << one[temp%10] << "thousand ";
            }
            temp = n/100;
            n -= (n/100)*100;
            if(n < 20)
            {
                cout << one[temp] <<  "hundred ";
                cout << one[n];
            }
            else if(n < 100)
            {
                if((n%10)==0){
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                }
                else {
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                    cout << one[n%10];
                }
            }
            break;
        case 6:
            temp2 = n/1000;
            n -= (n/1000)*1000;
            
            temp = temp2/100;
            temp2 -=temp*100;
            
            if(temp2<20){
                cout << one[temp] << "hundred  and " << one[temp2] << "thousand ";
            }
            else if(temp2 < 100)
            {
                if((temp%10)==0) cout << one[temp] << "hundred  and " << ten[temp2/10] << "thousand ";
                else cout << one[temp] << "hundred and " << ten[temp2/10] << one[temp2%10] << "thousand ";
            }
            temp = n/100;
            n -= (n/100)*100;
            if(n < 20)
            {
                cout << one[temp] << "hundred ";
                cout << one[n];
                
            }
            else if(n < 100)
            {
                if((n%10)==0){
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                }
                else {
                    cout << one[temp] << "hundred ";
                    cout << ten[n/10]; 
                    cout << one[n%10];
                }
            }
            break;
    }
    return buf;                                
}
 
 
void Account::In_Words() 
{ 
    char* str; 
    char buf [100]; 
    int choice = summa;
    str = numeral(choice, 256, buf); 
    cout << str <<  endl; 
}
 
 
int main() 
{   
    Account acc;  

    cout << "Personal Information: " << endl;
    acc.Read();
    cout << "Print data: " << endl;
    acc.Display();
    cout << "Change the account owner " << endl;
    acc.Change_Owner();
    cout << "Withdraw" << endl;
    acc.Withdraw();
    cout << "deposit" << endl;
    acc.Deposit();
    cout << "Exchange Currency" << endl;
    acc.Exchange();
    cout << "Print in words " << endl;
    acc.In_Words();
}