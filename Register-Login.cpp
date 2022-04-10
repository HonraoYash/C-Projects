#include<iostream>
#include<fstream>
#include<string>

using namespace std;


bool avail(string un)
{

  ifstream file(un+".txt");
  if(!file)
  {
    return true;
  }
  else
  {
    cout<<"Username already exits :( \n No worries! choose another one\n"<<endl;
    return false;
  }

  file.close();
  // int i;
  // while(i!=0)
  //   {
  //     if(a[i]==un);
  //     {
  //       cout<<"Username already exists!";
  //       return false;
  //     }
      
  //   }
  
  // return true;
}

void islogged()
{
  string un,pw,st1,st2,st3;
  cout<<"Enter your Username\n";
  cin>>un;    
  ifstream file(un + ".txt");
    
  if(!file)
  {
    cout<<"Incorrect Username \n Please try again :("<<endl;
  }
  else
  {
    cout<<"Enter password\n";
    cin>>pw;
    getline(file,st1);
    getline(file,st2);
    getline(file,st3);
    if(st3==pw)
    {
      cout<<"User logged in successfully!\n";
    }
    else
    {
      cout<<"Wrong password :( \n";
    }
  }
  file.close();
 
}

int main()
{
  int n;
  char ch;
  string username,password; 
 do
{
  cout<<"\t\t\t\t\tWelcome!"<<endl;
  cout<<"\t\t\t\tWould you like to -"<<endl;
  cout<<"\t\t\t\t\t1)Register. \n";
  cout<<"\t\t\t\t\t2)Login. \n";
  cin>>n;
  

if(n==1)
{
     cout<<"Enter username of your choice-\n";
     cin>>username;
     if(avail(username))
     {
       
         ofstream file;
         file.open(username + ".txt");
         file<<"Username-";
         file<<username<<endl;
         cout<<"Enter a strong password-\n";
         cin>>password;
         file<<"Password-\n";
         file<<password;
         cout<<"User registered successfully!!\n";
         file.close();
         cout<<"Do you want to login? (y/n) \n";
         cin>>ch;
         if(ch=='y')
          {
           islogged();
          }
      } 
}
else if(n==2)
{
  islogged();
}
  else
{
  cout<<"Wrong choice :(";
}

 cout<<"Do you want to continue? (y/n)\n"; 
 cin>>ch;
}while(ch=='y');  


  
  return 0;
}