#include <bits/stdc++.h>
using namespace std;
#define CAPACITY 100


class Stack{
    int top;
    public:
        int a[CAPACITY];
        Stack();
        bool push(int x);
        int pop();
        int peek();
        bool isFull();
        bool isEmpty();
        void display();
};


Stack::Stack(){
    top=-1;
}


bool Stack::push(int x){
    if(top> CAPACITY){
        cout<<"Stack Overflow";
        return false;
    }
    else{
        top++;
        a[top]=x;
        return true;
    }
}


bool Stack::isFull(){
    if(top==CAPACITY-1){
        return true;
    }
    else
    {
        return false;
    }
    
}


bool Stack::isEmpty(){
   return (top<0);
}


int Stack::pop(){
    int x=0;
    if(top<0){
        cout<<"Stack Empty";
    }
    else{
        x=a[top];
        top--;
    }
    return x;
}


int Stack::peek(){
    int x=0;
    if(top<0){
        cout<<"Stack is Empty";
    }
    else
    {
        x=a[top];
    }
    return x;
    
}


void Stack::display(){
    if(top<0){
       cout<<"Stack is Empty"<<endl; 
    }
    for(int i=0;i<=top;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main(){
    Stack s;
    cout<<"Stack created"<<endl;
    s.isEmpty();
    cout<<"Enter number of items to add"<<endl;
    int n,d;
    cin>>n;
    while(n--){
        cin>>d;
        s.push(d);
    }
    s.display();
    s.isEmpty();
    s.pop();
    cout<<"\nRemoving one item"<<endl;
    s.display();
    cout<<s.peek();
    return 0;
}