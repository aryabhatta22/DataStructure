/***********************************
 * Description : C++ program to delete duplicate elements from array 1223334444...... by:
 *              i) min number of moments
 *             ii) max number of moments
 * Date : 04 Apr, 2019
 **********************************/

#include<iostream>

using namespace std;

template<class T>
class Array{
private:
    T *Arr;
    int size;
    int length;
    
public:
    //constructor
    Array(){
        Arr=new T[10];
        size=10;
        length=0;
    }
    
    Array(int n){
        size=(n*(n+1))/2;
        Arr=new T[size];
        length=0;
    }
    
    //memeber functions 
    void getpattern(int n);
    void minDel(int n);
    void maxDel(int n);
    void display();
    void insert(int index, T x);
    int deleteElement(int index);
};

//to insert an elemnt at any given index
template<class T>
void Array<T>::insert(int index, T x){          
    if(index>=0&&index<=length){
        for(int i=length-1; i>=index;i++){         
            Arr[i+1]=Arr[i];
        }
        
        Arr[index]=x;           
        length++;               
    }
}

//to delete element at any given index
template<class T>                           
int Array<T>::deleteElement(int index){       
    int flag{0};
    if(index>=0&&index<length){
        for(int i=index;i<length-1;i++){
            Arr[i]=Arr[i+1];              
            flag++;
        }
        length--;                         
    }
    return flag;
}
//to display elements of array
template<class T>                   
void Array<T>::display(){           
    for(int i=0;i<length;i++){
        cout<<Arr[i]<<" ";
    }
    
    cout<<endl;
}

//to create the pattern 1223334444.....
template<class T>
void Array<T>::getpattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            this->insert(length,i);
        }
    }
}

//to delete element with min number of moments
template<class T>
void Array<T>::minDel(int n){
    int flag{0};
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            flag+=this->deleteElement(length-i);
        }
    }
    cout<<"\nNumber of moments: "<<flag<<endl;
}

//to delete element with max number of moments
template<class T>
void Array<T>::maxDel(int n){
    int flag{0};
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            flag+=this->deleteElement(i);
        }
    }
    cout<<"\nNumber of moments: "<<flag<<endl;
}

int main()
{
    cout<<"\nFor min deletions:"<<endl;
    
    
    Array<int> obj(4);
    obj.getpattern(4);
    cout<<"\nCurrent Array:";
    obj.display();
    obj.minDel(4);
    cout<<"\nArray after deltion: ";
    obj.display();
    
    cout<<"============================================"<<endl;
    cout<<"\nFor max deletions:"<<endl;
    
    Array<int> obj2(4);
    obj2.getpattern(4);
    cout<<"\nCurrent Array:";
    obj2.display();
    obj2.maxDel(4);
    cout<<"\nArray after deltion: ";
    obj.display();
    
    cout<<endl;
    return 0;
}