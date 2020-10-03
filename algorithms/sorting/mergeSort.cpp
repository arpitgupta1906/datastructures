#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int m,int l,int r){
    int n1=m-l+1;
    int n2=r-m;

    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=a[m+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }
        else {
            a[k++]=right[j++];
        }
    }

    while(i<n1){
        a[k++]=left[i++];
    }
    while(j<n2){
        a[k++]=right[j++];
    }
}

void merge_sort(int a[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);

        merge(a,m,l,r);
    }
}

int main(){
    int arr[]={12,444,63,84,24,6,444,-23};
    merge_sort(arr,0,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}
