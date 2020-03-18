#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1);
}

void quicksort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);

        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

void threewaypartition(int a[],int l,int r,int &i,int &j){
    i=l-1,j=r;
    int p=l-1,q=r;
    int v=a[r];

    while(true){
        while(a[++i]<v);
        while(v<a[--j]){
            if(j==l)
            break;
        }

        if(i>=j)
        break;

        swap(a[i],a[j]);

        if(a[i]==v)
        {
            p++;
            swap(a[i],a[p]);
        }

        if(a[j]==v){
            q--;
            swap(a[j],a[q]);
        }

        swap(a[i],a[r]);

        j=i-1;
        for(int k=l;k<p;k++,j--){
            swap(a[k],a[j]);
        }

        i=i+1;
        for(int k=r-1;k>q;k--,i++)
        swap(a[i],a[k]);
    }
}

void quicksort3way(int a[],int l,int r){
    if(r<=l) return;
    int i,j;
    partition(a,l,j);
    quicksort(a,l,j);
    quicksort(a,i,r);
}

int main(){
    int a[]={22,54,3,2,7,3456,3};
    quicksort(a,0,7-1);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}