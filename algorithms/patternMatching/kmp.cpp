#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pattern,int lps[]){
    int l=0;
    lps[0]=0;
    int i=1;
    while(i<pattern.size()){
        if(pattern[i]==pattern[l]){
            l++;
            lps[i]=l;
            i++;
        }
        else{
            if(l!=0){
                l=lps[l-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmpmatching(string txt,string pat){
    int lps[pat.size()];
    
    computeLPS(pat,lps);

    int i=0,j=0;//i for txt ,j for pat

    while(i<txt.size()){
        if(pat[j]==txt[i]){
            j++,i++;
        }
        if(j==pat.size()){
            cout<<"Pattern found at"<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(i<txt.size() and pat[j]!=txt[i]){
            if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main(){
    string txt="ABABDABACDABABCABAB";
    string pattern="ABABCABAB";
    
    kmpmatching(txt,pattern);
    
    return 0;
}