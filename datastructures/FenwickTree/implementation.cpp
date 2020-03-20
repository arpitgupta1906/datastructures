#include <bits/stdc++.h>
using namespace std;

int bit[1000],a[1000],n;

void update(int x,int val){
    for(;x<=n;x+=x&(-x)){
        bit[x]+=val;
    }
}

int query(int x){
    int sum=0;
    for(;x>0;x-=x&(-x)){
        sum+=bit[x];

    }
    return sum;
}

int main(){
    cin>>n;
    int i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }
    cout<<"sum of first 10"<<query(10)<<"\n";
    cout<<"sum between [2,7]"<<query(7)-query(2-1);
}