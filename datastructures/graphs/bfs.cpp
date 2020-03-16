#include <bits/stdc++.h>
using namespace std;

vector <int> v[10];
bool vis[10];
int level[10]={};

void bfs(int s){
    queue <int> q;
    q.push(s);
    level[s]=0;
    vis[s]=true;

    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0;i<v[p].size();i++){
            if(vis[v[p][i]] == false){
                level[v[p][i]]=level[p]+1;
                q.push(v[[p][i]]);
                vis[v[p][i]]=true;
            }
        }
    }
}

int main(){
    return 0;
}