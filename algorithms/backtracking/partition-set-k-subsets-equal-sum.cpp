#include <bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleRec(int a[],int subsetsum[],bool vis[],int subset,
            int k,int n,int curr,int limit){
        
    if(subsetsum[curr]==subset){
        if(curr==k-2)
            return true;

        return isKPartitionPossibleRec(a,subsetsum,vis,subset,k,n,curr+1,n-1);
    }

    for(int i=limit;i>=0;i--){
        if(vis[i])
        continue;

        int temp=subsetsum[curr]+a[i];

        if(temp<=subset){
            vis[i]=true;
            subsetsum[curr]+=a[i];
            bool next=isKPartitionPossibleRec(a,subsetsum,vis,subset,k
            ,n,curr,i-1);

            vis[i]=false;
            subsetsum[curr]-=a[i];
            if(next)
                return true;
        }
    }
    return false;

}

bool isKPartitionPossible(int a[],int n,int k){
    if(k==1)
        return false;

    if(n<k)
        return false;

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

    if(sum%k!=0)
        return false;
    
    int subset=sum/k;
    int subsetsum[k]={};
    bool vis[n]={};
    
    subsetsum[0]=a[n-1];
    vis[n-1]=true;

    return isKPartitionPossibleRec(a,subsetsum,vis,subset,k,n,0,n-1);
}

int main(){
    int arr[] = {2, 1, 4, 5, 3, 3}; 
    int N = 6; 
    int K = 3; 
  
    if (isKPartitionPossible(arr, N, K)) 
        cout << "Partitions into equal sum is possible.\n"; 
    else
        cout << "Partitions into equal sum is not possible.\n"; 

    return 0;
}