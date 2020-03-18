#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 and a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

}

int main(){
    int a[]={19,929,39,88,33};
    insertionSort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}