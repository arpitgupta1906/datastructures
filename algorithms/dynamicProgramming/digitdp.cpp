#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void getdigits(ll x,vector<ll> &digit){
    while(x){
        digit.push_back(x%10);
        x/=10;
    }
}

long long dp[20][180][2];

long long getsum(int idx,ll sum,ll tight,vector<ll> digit){
    if(idx==-1)
        return sum;

    if(dp[idx][sum][tight]!=-1 and tight!=1){
        return dp[idx][sum][tight];
    }

    ll res=0;
    int k=(tight)?digit[idx]: 9;

    for(int i=0;i<=k;i++){
        ll newtight=(digit[idx]==i)?tight:0;

        res+=getsum(idx-1,sum+i,newtight,digit);
    }

    if(!tight)
        dp[idx][sum][tight]=res;

    return res;
}

ll rangedigitsum(ll a,ll b){
    memset(dp,-1,sizeof(dp));

    vector<ll> digitA;
    getdigits(a-1,digitA);

    ll ans1=getsum(digitA.size()-1,0,1,digitA);

    memset(dp,-1,sizeof(dp));

    vector<ll> digitB;
    getdigits(b,digitB);

    ll ans2=getsum(digitB.size()-1,0,1,digitB);

    return ans2-ans1;
}

////given a range of numbers, find the sum of digits
int main(){
     long long a = 5, b = 11; 
    cout << "digit sum for given range : "
         << rangedigitsum(a, b) << endl; 
    return 0; 
}