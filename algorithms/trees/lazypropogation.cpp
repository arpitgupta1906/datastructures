#include<bits/stdc++.h>
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

void update(int tree[],int lazy[],int startrange,int endrange,int delta
    int low,int high,int pos){

        if(low>high)
        return;

        if(lazy[pos]!=0){
            tree[pos]+=lazy[pos];
            if(low!=high){
                lazy[2*pos+1]+=lazy[pos];
                lazy[2*pos]+=lazy[pos];
            }
            lazy[pos]=0;
        }

        //no overlap condition

        if(startrange>high || endrange<low)
            return;

        //total overlap condition
        if(startrange<=low and endrange>=high){
            tree[pos]+=delta;
            if(low!=high){
                lazy[2*pos+1]+=delta;
                lazy[2*pos]+=delta;
            }
            return;
        }

        //otherwise, partial overlap
        int mid=(low+high)/2;
        update(tree,lazy,startrange,endrange,delta,low,mid,2*pos);
        updata(tree,lazy,startrange,endrange,delta,mid+1,high,2*pos+1);
        tree[pos]+=min(tree[2*pos+1],tree[2*pos]);

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
    int tree[2000005],a[100005],lazy[2000005]={};
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
}