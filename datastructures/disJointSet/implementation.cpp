#include <bits/stdc++.h>
using namespace std;

void initialize(int a[],int n,int size[]){
    for(int i=0;i<n;i++){
        a[i]=i;
        size[i]=1;
    }
}

int root(int a[],int i){
    while(a[i]!=i){
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}

void weighted_union(int a,int b,int arr[],int size[]){
    int root_a=root(arr,a);
    int root_b=root(arr,b);
    if(root_a==root_b)
    return;
    if(size[root_a]<size[root_b]){
        arr[root_a]=arr[root_b];
        size[root_b]+=size[root_a];
        size[root_a]=0;
    }
    else{
        arr[root_b]=arr[root_a];
        size[root_a]+=size[root_b];
        size[root_b]=0;
    }
}

bool find(int a,int b,int arr[]){
    if(root(arr,a)==root(arr,b))
    return true;
    else
    return false;
}

int main(){
    int a[20],size[20];
    weighted_union(1,2,a,size);
    find(1,6,a);
    return 0;
}