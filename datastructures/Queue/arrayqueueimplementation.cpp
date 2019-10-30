#include <bits/stdc++.h>
using namespace std;


class Queue{
    public:
    int front,rear,size,capacity;
    int *a;
    Queue(int size);
    void enqueue(int data);
    int dequeue();
    int frontitem();
    int rearitem();
    bool isEmpty();
    bool isFull();
    void display();
};


Queue::Queue(int d){
    front=rear=size=0;
    capacity=d;
    a=new int[(size)*sizeof(int)];
}


bool Queue::isEmpty(){
    return (size==0);
}



bool Queue::isFull(){
    return (size>=capacity);
}


int Queue::frontitem(){
    if(this->isEmpty())
        return INT_MIN;
    return a[front];
}


int Queue::rearitem(){
     if(this->isEmpty())
        return INT_MIN;
    return a[rear-1];
}


void Queue::enqueue(int data){
    if(!isFull()){
        a[rear]=data;
        rear=(rear+1)%capacity;
        size++;
        cout<<data<<" enqueued to queue";
    }

}


int Queue::dequeue(){
    if(isEmpty())
        return INT_MIN;
    else
    {
        int data=a[front];
        size--;
        front=(front+1)%capacity;
        return data;
    }
    
}


void Queue::display(){
    if(isEmpty())
        cout<<"\nQueue is Empty";
    else if(rear>=front)
    {
        for(int i=front;i<rear;i++){
            cout<<a[i]<<" ";
        }
    }
    else{
        for(int i=front;i<size;i++)
            cout<<a[i]<<" ";
        for(int i=0;i<rear;i++)
            cout<<a[i]<<" ";
    }
    
}


int main(){
    int n;
    cin>>n;
    Queue q(n);
    for(int i=0;i<3;i++){
        int g;
        cin>>g;
        q.enqueue(g);
    }
    q.display();
    cout<<"\ndequeing";
    q.dequeue();
    q.display();
    return 0;
}