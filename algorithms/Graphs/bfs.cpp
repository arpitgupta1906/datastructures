#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int level[100];
bool vis[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
    level[s]=0;
    vis[s]=true;
    while(!q.empty()){
        int d=q.front();
        q.pop();
        for(int i=0;i<adj[d].size();i++){
            if(vis[adj[d][i]]==false){
                level[adj[d][i]]=level[d]+1;
                vis[adj[d][i]]=true;
                q.push(adj[d][i]);
            }
        }
    }
}

int main(){
    adj[2].push_back(3);
    bfs(2);
    return 0;
}