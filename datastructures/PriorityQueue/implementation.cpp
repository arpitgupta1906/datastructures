#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    int capacity;
    int *a;
    int queue_size;
public:
    PriorityQueue();
    void heapify(int i);
    int extract_maximum();
    int maximum();
    void insert(int k);
    void increase_val(int i,int val);
     
};

 PriorityQueue:: PriorityQueue()
{
    queue_size=0;
    capacity=100000;
    a=new int[capacity];
}

int PriorityQueue::maximum(){
    return a[queue_size];
}

void PriorityQueue::heapify(int i){
    int left=2*i+1;
    int right=2*i+2;
    int greatest=i;
    if(left<queue_size && a[left]>a[greatest])
        greatest=left;
    if(right<queue_size && a[right]>a[greatest])
        greatest=right;

    if(greatest!=i){
        swap(a[i],a[greatest]);
        heapify(greatest);
    }
}

int PriorityQueue::extract_maximum(){
    if(queue_size==0)
        cout<<"\nCan't remove element";

    int root=a[0];
    a[0]=a[queue_size-1];
    queue_size--;
    heapify(0);

    return root;
}

void PriorityQueue::insert(int k){
    queue_size++;
    increase_val(queue_size-1,k);
}

void PriorityQueue::increase_val(int i,int val){
    a[i] = val; 
    while (i != 0 && a[(i-1)/2] < a[i]) 
    { 
       swap(a[i], a[(i-1)/2]); 
       i = (i-1)/2; 
    } 
}

int main(){
    PriorityQueue p;
    return 0;
}