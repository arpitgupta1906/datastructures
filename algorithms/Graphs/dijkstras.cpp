#include <bits/stdc++.h>
using namespace std;

vector<int> dis(1000,1e4);
bool vis[1000];
vector <pair<int,int>> adj[1000];

void dijkstras(int s){
    memset(vis,false,sizeof(vis));

    priority_queue <pair<int, int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        pair <int,int> p=pq.top();
        pq.pop();
        
        int node=p.second;
        if(vis[node])
        continue;

        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            int e=adj[node][i].first;
            int w=adj[node][i].second;
            if(dis[node]+w<dis[e]){
                dis[e]=dis[node]+w;
                pq.push({dis[e],e});
            }
        }

    }
}

void addEdge(int a,int b,int c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}

int main(){
    
    int nodes=9;
    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 
    dijkstras(0);
    for(int i=0;i<nodes;i++){
        cout<<dis[i]<<"\n";
    }
    return 0;
}