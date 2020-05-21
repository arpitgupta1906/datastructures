#include<bits/stdc++.h>
using namespace std;

#define N 1000

int Time=0;
vector<int> dis(N+1,0);
vector<int> adj[N];
vector<int> low(N+1,0);
bool ap[N+1]={};

vector<int> disbr(N+1,0);
vector<int> lowbr(N+1,0);
vector<pair<int,int>> br;

int dfsap(int u,int parent){
    int children=0;
    low[u]=dis[u]=++Time;

    for(auto v:adj[u]){
        if(v==parent)
            continue;
        
        if(!dis[v]){
            children++;
            dfsap(v,u);
            if(dis[u]<=low[v])   //////condition 1
             ap[u]=true; 
             low[u]=min(low[u],low[v]); ///this implies that v might be an 
                                        ///ancestor of u
        }else{
            low[u]=min(low[u],dis[v]);
        }

    }
    return children;
}

void dfsbr(auto u,int p){
    lowbr[u]=disbr[u]=++Time;
    for(int v: adj[u]){
        if(v==p)
        continue;

        if(!disbr[v]){
            dfsbr(v,u);
            if(disbr[u]<lowbr[v]){
                br.push_back({u,v});

            }
            lowbr[u]=min(lowbr[u],lowbr[v]);
        }else{
            lowbr[u]=min(lowbr[u],disbr[v]);
        }
    }
}

void AP(){
    Time=0;
    for(int i=0;i<N;i++){
        if(!dis[i]){
            ap[i]=dfsap(i,i)>1; ///condition 2
        }
    }
}

void BR(){
    Time=0;
    for(int i=0;i<N;i++){
        if(!disbr[i]){
            dfsbr(i,i);
        }
    }
}

int main(){

}