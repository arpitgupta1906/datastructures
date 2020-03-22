#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long prim(int x){
    priority_queue <PII ,vector<PII>,greater<PII>> q;
    int y;
    long minimumcost=0;
    PII p;
    q.push(make_pair(0,x));
    while(!q.empty()){
        p=q.top();
        q.pop();
        x=p.second;
        if(marked[x]==true)
        continue;
        marked[x]=true;
        minimumcost+=p.first;
        for(int i=0;i<adj[x].size();i++){
            y=adj[x][i].second;
            if(marked[y]==false){
                q.push(adj[x][i]);
            }
        }
    }
    return minimumcost;
}

int main(){
    int nodes, edges, x, y;
    long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}