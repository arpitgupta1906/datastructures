#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void max_heapify(long a[],int i,int n){
    int m=i;
    int leftchild=2*i+1;
    int rightchild=2*i+2;
    if(a[leftchild]>a[m] and leftchild<n){
        m=leftchild;
    }
    if(a[rightchild]>a[m] and rightchild<n){
        m=rightchild;
    }
    if(m!=i){
        swap(a[i],a[m]);
        max_heapify(a,m,n);
    }
}

void build_heap(long a[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(a,i,n);
    }
}


void heapsort(long a[],int n){
    build_heap(a,n);
    int i=0;
    while(i<n){
        i++;
        swap(a[n-i],a[0]);
        max_heapify(a,0,n-i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
    if(i>=2){
        heapsort(a,i+1);
        cout<<a[i]<<" "<<a[i-1]<<" "<<a[i-2]<<"\n";
    }
    else
    cout<<-1<<"\n";
    }
    return 0;
}