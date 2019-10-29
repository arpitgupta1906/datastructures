#include <bits/stdc++.h>
using namespace std;


class Stack{
    struct Node{
    int data;
    struct Node* next;
    }*top;
    // struct Node *top;
    public:
        Stack();
        void push(int data);
        bool isEmpty();
        void display();
        int pop();
        int peek();
};


Stack::Stack(){
    top=NULL;
}

void Stack::push(int data){
    struct Node *temp;
    temp=new Node();
    
    if(!temp){
        cout<<"\nHeap Overflow";
        exit(1);
    } 
    temp->data=data;
    temp->next=top;
    top=temp;
}


bool Stack::isEmpty(){
    return top==NULL;
}


int Stack::peek(){
    if(!isEmpty())
        return top->data;
    else
    {
        exit(1);
    }
}


int Stack::pop(){
    struct Node *temp;
    if(top==NULL){
        cout<<"\nStack Underflow";
    }
    else
    {
        temp=top;
        top=top->next;
        return temp->data;
    }
}


void Stack::display(){
    struct Node *temp;
    if(top==NULL){
        cout<<"\nStack Underflow";
        exit(1);
    }
    else{
        temp=top;
        while(temp!=NULL){
            cout<<(temp->data)<<" ";
            temp=temp->next;
        }
    }
    
}


int main(){
     Stack s;
    cout<<"Stack created"<<endl;
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