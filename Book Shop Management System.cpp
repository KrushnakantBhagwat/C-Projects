#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
 
class BOOK
{
  char title[20];
  char author[30];
  float price;
  char publisher[30];
  int stock_position;
 
  public:
  int count = 0;
  BOOK()                   
  {
    strcpy(title," ");
    strcpy(author," ");
    price=0.0;
    strcpy(publisher," ");
    stock_position=0;
    count=0;
  }
 
  char *rettit()          
  {
      return title;
  }
 
  char *retaut()          
  {
      return author;
  }
  int retstk()
  {
      return stock_position;  
  }
  float retprice()
  {
      return price;          
  }
 
  void get_details();        
  void show_details();       
  friend BOOK Search();      
  friend void buy();        
  void listb();             
  void modify(int c);       
};

BOOK null_obj;              
BOOK g_obj;                 

void BOOK::get_details()    
{
     cout<<"\nEnter BOOK Details: ";
     
     cout<<"\n ENTER BOOK TITLE ";
     cin>>title;
     
     cout<<"ENTER AUTHOR NAME ";
     cin>>author;
     
     cout<<"ENTER BOOK PRICE ";
     cin>>price;
     
     cout<<"ENTER PUBLISHER ";
     cin>>publisher;
     
     cout<<"ENTER THE AVAILABLE STOCK ";
     cin>>stock_position;
     count = count + 1;
}

void BOOK::show_details()    
{
    cout<<setw(10)<<"\nTHE ENTERED DETAILS ARE: ";
    cout<<setw(10)<<"\n S.NO. "<<setw(10)<<count;
    cout<<setw(10)<<"\n Title: "<<setw(10)<<title;
    cout<<setw(10)<<"\n Author name: "<<setw(10)<<author;
    cout<<setw(10)<<"\n Price: "<<setw(10)<<price;
    cout<<setw(10)<<"\n Publisher name: "<<setw(10)<<publisher;
    cout<<setw(10)<<"\n Number of BOOKs Availabale: "<<setw(10)<<stock_position;
}

void BOOK::listb()    
{
    cout<<setw(10)<<"\n Title: "<<title<<setw(10)<<"\n Author name: "<<author
    <<setw(10)<<"\n Number of BOOKs Availabale: "<<stock_position<<endl<<endl;
}

BOOK Search()    
{
    char titl[30];
    char aut[30];
    int newf=0;
    int ch;
   
    cout<<"\nEnter BOOK Title : ";
    cin>>titl;
    cout<<"Enter AUthor's Name : ";
    cin>>aut;
    ifstream fin;
    fin.open("Bshop",ios::in);
    while(!fin.eof())
    {
       
        fin.read((char *)&g_obj, sizeof(BOOK));
       
        if((strcmp(g_obj.retaut(),aut)==0) && (strcmp(g_obj.rettit(),titl)==0))
        {
            g_obj.show_details();
            newf = 1;
            return g_obj;
            break;
        }
    }
    fin.close();
   
    if(newf==0)
        {
            cout<<"No record found";
            return null_obj;
        }
}

void buy()    
{
    float t_cost=0.0;
    char ch;
    g_obj = Search();
    g_obj.show_details();
    int copies;
    if(g_obj.retprice()==0.0)
    {
        cout<<"Enter valid details !!!"<<endl;
    }
   
    else
    {
        cout<<"\nEnter Number of copies you want: ";
        cin>>copies;
               
        if(g_obj.retstk()>=copies)
        {
            t_cost = copies*g_obj.retprice();
            cout<<"Total Amount is: "<<t_cost<<endl;
            cout<<"******Confirmation required*******"<<endl;
            cout<<"Press 'Y' (to buy) or Press 'N' (go to main menu): ";
            cin>>ch;
            if(ch=='Y' || ch=='y')
            {
                fstream f;
                f.open("Bshop",ios::ate|ios::in|ios::out);
                f.clear();
                int last=f.tellg();
                int object = g_obj.count;
                int location=(object-1)*sizeof(BOOK);
                if(f.eof())
                    f.clear();
                f.seekp(location);
                g_obj.modify(copies);
                f.write((char*)&g_obj, sizeof(BOOK));
                g_obj.show_details();
                f.close();
                cout<<"\n*******Thank you for buying our book******* "<<endl<<endl;
            }
           
        }
               
       else
        {
            cout<<"\nRequired copies not in stock!!!"<<endl;
        }
       
    }
}

void BOOK::modify(int copies)    
{
    stock_position = stock_position - copies;
}




int main()
{
    int flag = 0;
    int ch;
    ofstream fout;
    fout.open("Bshop",ios::app);
    fout.close();
    do{
    cout<<"\n\n\n****Welcome to the BOOK Store****";
    cout<<"\n1. Add BOOK Deatils ";
    cout<<"\n2. Search BOOK Deatils ";
    cout<<"\n3. Buy BOOK ";
    cout<<"\n4. List of all Books available ";    
    cout<<"\n0. Exit ";
    cout<<"\nEnter choice : ";
    cin>>ch;
    switch(ch)
        {
            case 1: {
                    ofstream fout;
                    fout.open("Bshop",ios::app);
                    g_obj.get_details();
                    fout.write((char *)&g_obj,sizeof(BOOK));
                    fout.close();
                    cout<<"\nThank you !"<<endl;
                    break;
                    }
               
            case 2: {
                    g_obj = Search();
                    if(g_obj.retstk() == 0)
                        {
                            cout<<"Enter Valid account details"<<endl;
                        }
                    break;
                    }
       
            case 3: {
                    buy();
                    break;
                    }
                   
            case 4: {
                    ifstream fin;
                    fin.open("Bshop",ios::in);
                    while(fin.read((char *)&g_obj, sizeof(BOOK)))
                    {
                        g_obj.listb();
                    }
                    fin.close();
                    break;
                    }
                   
        }
    }while(ch!=0);
    return 0;
}


