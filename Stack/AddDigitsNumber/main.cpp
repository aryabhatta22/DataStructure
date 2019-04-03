/***********************************
 * Description : using stack, add digits of number
 * Date : 03 Apr, 2019
 **********************************/


#include <bits/stdc++.h> 

using namespace std;

stack<int> st;

void pushback(int num){
    while(num>0){
        st.push(num%10);
        num/=10;
    }
}

int SumDigits(int num){
    pushback(num);
    
    int sum{0};
    
    while(!st.empty()){             //not st.isempty
        sum+=st.top();
        st.pop();
    }
    
    return sum;
}
int main()
{
    int num{1234};
    
    cout<<"Sum of digits of "<<num<<" is "<<SumDigits(num)<<endl;
    
    cout<<endl;
    return 0;
}