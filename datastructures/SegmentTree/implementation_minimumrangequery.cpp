#include <bits/stdc++.h>
using namespace std;

void build(int tree[],int a[],int node,int start,int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        int mid=(start+end)/2;
        build(tree,a,2*node,start,mid);
        build(tree,a, 2*node+1,mid+1,end);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

void update(int tree[],int a[],int idx,int value,int node,int start,int end){
    if(end==start){
        a[idx]=value;
        tree[node]=a[idx];
    }
    else{
        int mid=(start+end)/2;
        if(idx>=start and idx<=mid)
        update(tree,a,idx,value,2*node,start,mid);
        else
        update(tree,a,idx,value,2*node+1,mid+1,end);

        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int tree[],int node,int start,int end,int l, int r){
    if(l>end || r<start)
    return 100005;
    if(l<=start and r>=end)
    return tree[node];
    int mid=(end+start)/2;
    return min(query(tree,2*node,start,mid,l,r),query(tree,2*node+1,mid+1,end,l,r));
}

int main(){
    int tree[2000005],a[100005];
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    build(tree,a,1,1,n);
    while(q--)
    {
    char b;
    int x,y;
    cin>>b>>x>>y;
    if(b=='q')
    {
    int c=query(tree,1,1,n,x,y);
    cout<<c<<endl;
    }
    else
    update(tree,a,x,y,1,1,n);
    }
return 0;
}