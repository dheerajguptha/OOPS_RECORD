#include<iostream>
using namespace std;
class Account{
    public:
      int accno;
      string name;
      float balance;
      void display(){
        cout<<"Account No:"<<accno
        <<",Name"<<name
        <<",Balance"<<balance<<endl;
      }
    };
    
   int main(){
    Account a1,a2;
    a1.accno=1001;
    a1.name="Ramesh";
    a1.balance=25000.0;
    a2.accno=1002;
    a2.name="Sita";
    a2.balance=40000.75;
    a1.display();
    a2.display();
    return 0;
   } 
      

