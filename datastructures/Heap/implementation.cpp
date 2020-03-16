#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    private:
        int *harr;
        int capacity;
        int heap_size;
    public:
        MinHeap(int capcaity);
        void MinHeapify(int);
        int parent(int i){
            return (i-1)/2;
        }

        int left(int i){
            return (2*i)+1;
        }

        int right(int i){
            return (2*i+2);
        }

        int extractMin();
        void makeheap();
        void decreaseKey(int i,int new_val);

        int getMin(){
            return harr[0];
        }

        void deleteKey(int i);

        void insertKey(int k);
};

MinHeap::MinHeap(int cap=pow(10,5)){
    heap_size=0;
    capacity=cap;
    harr=new int[cap];
}

void MinHeap::MinHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<heap_size && harr[l]<harr[smallest])
        smallest=l;
    if(r<heap_size && harr[r]<harr[smallest])
        smallest=r;

    if(smallest!=i){
        swap(harr[0],harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin(){
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }

    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::makeheap(){
    for(int i=heap_size/2-1;i>=0;i--){
        MinHeapify(i);
    }
}

void MinHeap::insertKey(int k){
    if(heap_size==capacity){
        cout<<"\nOverflow:  could not insert element";
        return;
    }

    heap_size++;
    int i=heap_size-1;
    harr[i]=k;

    while ((i!=0 && harr[parent(i)]>harr[i]))
    {
        swap(harr[i],harr[parent(i)]);
        i=parent(i);
    }
}

void MinHeap::decreaseKey(int i,int new_val){
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(harr[i], harr[parent(i)]); 
       i = parent(i); 
    } 
}

void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}



int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
} 