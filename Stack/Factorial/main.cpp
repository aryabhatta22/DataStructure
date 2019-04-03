
#include <iostream>

using namespace std;

class stack
{
    int arr[1024], ptr;
 public:
    stack()
     {
      ptr = 0;
     }
     void push(int n)
     {
      arr[ptr++]=n;
     }
     int pop()
     {
      return arr[--ptr];
     }
};

int main()
{
     int n, i;
     stack s;
     
     cin>>n;
     for(i=n;i>0;i--)
     {
      s.push(i);
     }
     
     int fact = 1;
     
     while(n--)
         fact*=s.pop();
         
     cout<<"Factorial: "<<fact<<endl;
     return 0;
}