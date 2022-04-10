#include <iostream>
using namespace std;

bool issafe(int **arr,int x,int y,int n)
{
  int i,j;
 for(i=0;i<x;i++)
   {
     if(arr[i][y]==1)
     {
       return false;
     }
   }
  i=x;
  j=y;
  while(i>=0 && j>=0)
    {
      if(arr[i][j]==1)
      {
        return false;
      }
      i--;
      j--;
    }
  i=x;
  j=y;
  while(i>=0 && j<n)
    {
       if(arr[i][j]==1)
      {
        return false;
      }
      i--;
      j--;
    }
  return true;
}

bool nqueen(int **arr,int x,int n)
{
  int j;
  if(x>=n)
  {
    return true;
  }
  for(j=0;j<n;j++)
    {
      if(issafe(arr,x,j,n))
      {
        arr[x][j]=1;

        if(nqueen(arr,x+1,n))
        { 
          return true;
        }

        arr[x][j]=0;
      }
    }
  return false;
}

int main() 
{
 int n,i,j;
  cout<<"Enter the number of rows:\n";
  cin>>n;
  
 int **arr=new int *[n];
 for(i=0;i<n;i++)
   {
     arr[i]=new int[n];
   }
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          arr[i][j]=0;
        }
    }
  


  if(nqueen(arr,0,n))
  {
      cout<<"The Solution Chess board is:\n";
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          cout<<arr[i][j]<<"\t";
        }
      cout<<endl;
    }
  }


  
}