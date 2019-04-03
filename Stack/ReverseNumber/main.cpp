/***********************************
 * Description : using stack, reverse a number
 * Date : 03 Apr, 2019
 **********************************/


#include <bits/stdc++.h> 
using namespace std; 
  
// Stack to maintain order of digits 
stack <int> st; 
  
// Function to push digits into stack 
void push_digits(int number) 
{ 
    while (number != 0)  
    { 
        st.push(number % 10); 
        number = number / 10; 
    } 
} 
  
// Function to reverse the number 
int reverse_number(int number) 
{ 
    // Function call to push number's digits to stack 
    push_digits(number); 
      
    int reverse = 0; 
    int i = 1; 
      
    // Pop the digits and form the reversed number 
    while (!st.empty())  
    { 
        reverse = (reverse) + (st.top() * i); 
        st.pop(); 
        i = i * 10; 
    } 
      
    return reverse; 
} 
  

int main() 
{ 
    int number = 1234; 
      
    // Function call to reverse number 
    cout << reverse_number(number); 
    cout<<endl;
    return 0; 
} 