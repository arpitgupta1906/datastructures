#include<bits/stdc++.h>
using namespace std;

int ceilindex(vector<int> &a,int l,int r,int key){
    while(r-l>1){
        int m=l+(r-l)/2;
        if(a[m]>=key)
            r=m;
        else 
            l=m;
    }
    return r;
}

int lis(vector<int> &a){
    if(a.size()==0)
        return 0;

    vector<int> tail(a.size(),0);
    int length=1;
    tail[0]=a[0];

    for(int i=0;i<a.size();i++){

        if(a[i]<tail[0])   ///if the current element is the 
                            ///smallest till now
            tail[0]=a[i];
        else if(a[i]>tail[length-1])  //if the current element is 
                                      //the largest till now
            tail[length++]=a[i];

        else{
            tail[ceilindex(tail,-1,length-1,a[i])]=a[i];
        }
    }

    return length;
}

int main(){
    vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6 };
    cout<<lis(v);
}