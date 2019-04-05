/***********************************
 * Description :
 * Date : 
 **********************************/


#include<iostream>

using namespace std;

template<class T>
class Stack{
public:
    T *st;
    int size;
    int top;
    
public:
    //constructor
    Stack(){
        size=10;
        st=new T[10];
        top=-1;
    }
    Stack(int sz){
        size=sz;
        st=new T[sz];
        top=-1;
    }
    
    
    //member function
    void push(T x);
    T pop();
    int isEmpty();
    int isFull();
};

template<class T>

void Stack<T>::push(T x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top]=x;
    }
}

template<class T>

T Stack<T>::pop()
{
    T x=-1;
    if(isEmpty())
        cout<<"Stack underlfow"<<endl;
    else
    {
        x=st[top];
        top--;
    }
    
    return x;
}

template<class T>

int Stack<T>::isFull()
{
    return top==size-1;             //size-1 means is stack is at highest index
}

template<class T>

int Stack<T>::isEmpty()
{
    return top==-1;                 //negative value means stack is empty
}

int main()
{
    int num{0},sum{0};              //num to take number from user
                                    //sum to calculate sum of digits
    
    Stack<int> st(10);
    cout<<"Enter a number: ";
    cin>>num;
    while(num>0){
        st.push(num%10);            //digits of number being pushed to stack st
        num/=10;
    }
    while(!st.isEmpty()){           //untill the stack is not emptied
        sum+=st.pop();              //top element is being poped one by one and being added to sum
    }
    cout<<"Sum of digits is: "<<sum;    //displaying the sum
    cout<<endl;
    return 0;
}