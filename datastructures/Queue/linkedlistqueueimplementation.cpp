#include <bits/stdc++.h>
using namespace std;


class Queue{
    public:
        struct Node{
            int data;
            struct Node* next;
        }*front,*rear;

        Queue();
        void enqueue(int item);
        int dequeue();
        void display();
        int frontitem();
        int rearitem();
};


Queue::Queue(){
    front=rear=NULL;

}


int Queue::frontitem(){
    if(front==NULL)
        return INT_MIN;
    else
    {
        return front->data;
    }
    
}


int Queue::rearitem(){
    if(rear==NULL)
        return INT_MIN;
    else
    {
        return rear->data;
    }
    
}


void Queue::enqueue(int item){
    struct Node* temp=new Node();
    temp->data=item;
    temp->next=NULL;
    if(rear==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}


int Queue::dequeue(){
    if(front==NULL)
        return INT_MIN;
    else
    {   
        int value=front->data;
        front=front->next;
        if(front==NULL)
        rear=NULL;
        return value;
    }
    
}


void Queue::display(){
    struct Node* temp=front;
    while(temp!=NULL){
        cout<<(temp->data)<<" ";
        temp=temp->next;
    }
}


int main(){
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        q.enqueue(r);
    }
    q.display();
    cout<<"\ndequeing ";
    q.dequeue();
    q.display();
    return 0;
}