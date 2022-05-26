#include <iostream>
using namespace std;

class Bank
{
  static int account;
  string name;
  float balance;
 
  public:
  Bank()
  {
    account = 1;
    name = " ";
    balance = 0;
  }
  void OpenAccount();
  void ShowAccount();
  void Deposite();
  void Withdraw();
  int friend Search(Bank obj[], int size);
};

int Bank:: account =1;

void Bank::OpenAccount()
{
    account = account +1;
    cout<<"Enter the Account holder name: ";
    cin>>name;
    
    cout<<"Enter Opening balance: ";
    cin>>balance;
    
    cout<<"\n-----Your Account Details Are-----";
    cout<<"\nYour Account Number is : "<<account;
    cout<<"\nAccount holder Name is : "<<name;
    cout<<"\nYour Balance : "<<balance<<endl;
}

void Bank :: ShowAccount()
{

    cout<<"\nYour Account Number is : "<<account;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nAvailable Balance : \n"<<balance<<endl;
}

void Bank::Deposite()
{
    float amt;
    cout<<"Enter Amount to be deposited : ";
    cin>>amt;
    balance = balance+amt;
}

void Bank :: Withdraw()
{
    float wd_amt;
    cout<<"Enter Amount You want to Withdraw : ";
    cin>>wd_amt;
    if(wd_amt>balance)
    {
        cout<<"Sorry, You don't have enough balance";
    }
    else
    {
        balance = balance-wd_amt;
    }
}

int Search(Bank obj[], int size)
{
    int acc,flag=-1;
    cout<<"Enter Your Account Number : ";
    cin>>acc;
    for(int i = 0; i<size;i++)
    {
        if(acc==obj[i].account)
        {
            flag = i;
            break;
        }
     }
      if(flag<0)
        {
            cout<<"\nRecord is not found !!!\n";
        }
    return flag;
}

int main()
{
    Bank obj[10];
    int no,ch;
    static int j=0;
    do{
    cout<<"----------Welcome to the State Bank Of India----------\n";
    cout<<"\n1. Open Account ";
    cout<<"\n2. Show Account Details ";
    cout<<"\n3. Deposite Amount ";
    cout<<"\n4. Withdraw Amount ";
    cout<<"\n5. Search Account ";
    cout<<"\n0. Exit\n ";
    cout<<"\nEnter choice : ";
    cin>>ch;
    switch(ch)
        {
            case 1: obj[j].OpenAccount();
                    cout<<"\nThank you For Visiting !\n"<<endl;
                    j=j+1;
                    break;
               
            case 2: no=Search(obj,10);
                    if(no>=0)
                    {
                        obj[no].ShowAccount();
                    }
                    break;
       
            case 3: no=Search(obj,10);
                    if(no>=0)
                    {
                        obj[no].Deposite();
                        obj[no].ShowAccount();
                    }
                    break;
                   
            case 4: no=Search(obj,10);
                    if(no>=0)
                    {
                       obj[no].Withdraw();
                       obj[no].ShowAccount();
                    }
                   
                    break;
                   
            case 5: no=Search(obj,10);
                    if(no>=0)
                    {
                        obj[no].ShowAccount();
                    }
                   
                    break;
        }
    }while(ch!=0);
   
    return 0;
}






