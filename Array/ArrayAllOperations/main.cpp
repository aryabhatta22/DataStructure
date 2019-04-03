/***********************************
 * Description : C++ program to implement all basic operations of an array
 * Date : 03 Apr, 2019
 **********************************/


#include<iostream>

using namespace std;


class Array{
private:
    int *Arr;       //To dynamically allocate memeory to array in constructor
    int size;       //capacity of array
    int length;     //number of elemnts present
public:

    //constructor
    Array(){
        size=10;            //say
        Arr=new int[10];    //dynamic allocation of size 10
        length=0;           //no elemt present at beginning
    }
    
    Array(int sz){           //to make array of required size
        size=sz;            
        Arr=new int[size];
        length=0;
    }
    
    //destructor
    ~Array(){
        delete []Arr;
    }
    
    //memeber functions
    void display();
    void insert(int index, int x);      //x is element to be inserted
    int deleteElement(int index);
    
};

void Array::display(){
    for(int i=0;i<length;i++){
        cout<<Arr[i]<<" ";
    }
    
    cout<<endl;
}

void Array::insert(int index, int x){
    if(index>=0&&index<=length){
        for(int i=length-1; i>=index;i++){          //to shift the elements from end of array to index where element is to be inserted
            Arr[i+1]=Arr[i];
        }
        
        Arr[index]=x;           //element is inserted at given index
        length++;               //length of array will increase
    }
}

int Array::deleteElement(int index){
    int delElement=0;                       //element which will be delted intialized
    if(index>=0&&index<length){
        delElement=Arr[index];              //value of delting element is stored 
        for(int i=index;i<length-1;i++){
            Arr[i]=Arr[i+1];                //array is shifted 
        }
        length--;                           //length of array will decrease after deletion
    }
    return delElement;
}

int main()
{
    Array obj(10);
    
    obj.insert(0,5);
    obj.insert(1,6);
    obj.insert(2,9);
    obj.display();
    cout<<obj.deleteElement(1)<<endl;
    obj.display();
    
    cout<<endl;
    return 0;
}