#include<bits/stdc++.h>
using namespace std;

void RabinKarpsearch(string txt,string pat,int q){
    int d=256; //number of characters 
    
    int n=txt.size(),j;
    int m=pat.size();
    int p=0,t=0,h=1;

//h is = pow(d,M-1)%q

    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }

    for(int i=0;i<m;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }

    for(int i=0;i<n-m+1;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j])
                break;
            }

            if(j==m)
            cout<<"Pattern matched at"<<i<<"\n";
        }

        if(i<n-m){
            t=((d*(t-txt[i]*h))+txt[i+m])%q;
            if(t<0)
            t+=q;
        }
    }
}

int main(){
    string txt="GEEKS FOR GEEKS";
    string pattern="GEEK";
    int q=101;
    RabinKarpsearch(txt,pattern,q);
    return 0;
}