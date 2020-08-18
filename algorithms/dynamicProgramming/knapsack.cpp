#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n){
    int dp[n+1][W+1]={};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 or j==0)
                dp[i][j]=0;
            else if(j<wt[i-1])
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
        }
    }

    return dp[n][W];
}

int main(){
    int val[] = { 60, 120, 100 }; 
    int wt[] = { 10, 30, 20 }; 
    int W = 50; 
    int n=3;
    cout<<knapSack(W,wt,val,n)<<"\n";
    return 0;
}