/***********************************
 * Description : C++ program to implement all basic operations of an array
 * Date : 03 Apr, 2019
 **********************************/


#include<iostream>

using namespace std;

template<class T>   //to make a generic class array
class Array{
private:
    T *Arr;         //array type is T
    int size;       
    int length;     
public:

    //constructor
    Array(){
        size=10;           
        Arr=new T[10];    //dynamic allocation of type T size 10
        length=0;          
    }
    
    Array(int sz){         
        size=sz;            
        Arr=new T[size];       //dynamic allocation of type T size "sz"
        length=0;
    }
    
    //destructor
    ~Array(){
        delete []Arr;
    }
    
    //memeber functions
    void display();
    void insert(int index, T x);      //x(inserting element) should be type T
    T deleteElement(int index);       //deleted element should be type T
    
};

template<class T>                   //template<class T> should be included before every function definition
void Array<T>::display(){           //Array changed to Array<T>
    for(int i=0;i<length;i++){
        cout<<Arr[i]<<" ";
    }
    
    cout<<endl;
}

template<class T>                               //template<class T> should be included before every function definition
void Array<T>::insert(int index, T x){          //inserting element x type changed from int to T, Array changed to Array<T>
    if(index>=0&&index<=length){
        for(int i=length-1; i>=index;i++){         
            Arr[i+1]=Arr[i];
        }
        
        Arr[index]=x;           
        length++;               
    }
}

template<class T>                           //template<class T> should be included before every function definition
T Array<T>::deleteElement(int index){       //return type of function chnaged from int to T, Array changed to Array<T>
    T delElement=0;                       
    if(index>=0&&index<length){
        delElement=Arr[index];            
        for(int i=index;i<length-1;i++){
            Arr[i]=Arr[i+1];              
        }
        length--;                         
    }
    return delElement;
}

int main()
{
    Array<int> obj(10);                 //Array changed from Array to Array<int> for interger type array
    
    obj.insert(0,5);
    obj.insert(1,6);
    obj.insert(2,9);
    obj.display();
    cout<<obj.deleteElement(1)<<endl;
    obj.display();
    cout<<endl;
    
    Array<float> objf(10);                 //Array changed from Array to Array<float> for float type array
    
    objf.insert(0,5.6);
    objf.insert(1,6);
    objf.insert(2,9.73);
    objf.display();
    cout<<objf.deleteElement(1)<<endl;
    objf.display();
    
    cout<<endl;
    return 0;
}